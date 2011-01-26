/*
 Universidade de Brasilia
 Instituto de Ciencias Exatas
 Departamento de Ciencia da Computacao
 Software Basico
 Turma A - 02/2007
 
 Rafael Liu Santos 			05/23101
 Thiago de Oliveira Franca	05/24387
 Tulio Conrado Campos		05/24557
 
 TNTvm
 
 class_struc.c: modulo que le a estrutura do arquivo .class.
 Assertivas de entrada: arquivos e ponteiros para estrutura validos.
 */

#include "class_struc.h"

void lerUtf8(FILE *arq, CONSTANT_Utf8_info *utf8_info) {
	int i;

	u2 tamanho = fget_u2(arq);

	assert (arq != NULL);

	/* aloca tamanho do array */
	utf8_info->length = tamanho;
	utf8_info->bytes = malloc(sizeof(u1) * tamanho);

	/* adiciona os bytes */
	for (i = 0; i < tamanho; i++) {
		utf8_info->bytes[i] = fget_u1(arq);
	}
}

int lerConstantPool(FILE *arq, ClassFile *class_file) {
	int i;
	u1 tag;
	u2 tamanho = fget_u2(arq);
	cp_info *info;

	assert (arq != NULL);
	assert (class_file != NULL);

	/* aloca tamanho do array */
	class_file->constant_pool_count = tamanho;
	//TODO: Verificar se está correto agora, alterado para (tamanho + 1)
	class_file->constant_pool = malloc(sizeof(cp_info) * (tamanho + 1));

	/* cria cada elemento do array */
	info = class_file->constant_pool;
	for (i = 1; i < tamanho; i++) {
		tag = fget_u1(arq);
		info[i].tag = tag;

		switch (tag) {
		/* elementos de mesma assinatura (u2) */
		case CONSTANT_Class:
		case CONSTANT_String:
			info[i].info.string_info.string_index = fget_u2(arq);
			break;

			/* elementos de mesma assinatura (u2, u2) */
		case CONSTANT_Fieldref:
		case CONSTANT_Methodref:
		case CONSTANT_InterfaceMethodref:
		case CONSTANT_NameAndType:
			info[i].info.name_and_type_info.name_index = fget_u2(arq);
			info[i].info.name_and_type_info.descriptor_index = fget_u2(arq);
			break;

			/* elementos de mesma assinatura (u4) */
		case CONSTANT_Integer:
		case CONSTANT_Float:
			info[i].info.float_info.bytes = fget_u4(arq);
			break;

			/* elementos de mesma assinatura (u4, u4) */
		case CONSTANT_Long:
		case CONSTANT_Double:
			info[i].info.double_info.high_bytes = fget_u4(arq);
			info[i].info.double_info.low_bytes = fget_u4(arq);
			break;

		case CONSTANT_Utf8:
			lerUtf8(arq, &(info[i].info.utf8_info));
			break;

		default:
			//TODO: Verificar se para.
			return UNDEFINED_FLAG;
		}
	}
	return OK;
}

int lerInterfaces(FILE *arq, ClassFile *class_file) {
	int i;
	u2 tamanho;
	tamanho = fget_u2(arq);

	/* aloca tamanho do array */
	class_file->interfaces_count = tamanho; 
	class_file->interfaces = malloc(sizeof(u2) * tamanho);

	/* cria cada elemento do array */
	for (i = 0; i < tamanho; i++) {
		class_file->interfaces[i] = fget_u2(arq);
	}

	return OK; 
}

int lerFields(FILE *arq, ClassFile *class_file) {
	int i;
	u2 tamanho;
	tamanho = fget_u2(arq);

	/* aloca tamanho do array */
	class_file->fields_count = tamanho; 
	class_file->fields = malloc(sizeof(field_info) * tamanho);

	/* cria cada elemento do array */
	for (i = 0; i < tamanho; i++) {
		class_file->fields[i].access_flags = fget_u2(arq);
		class_file->fields[i].name_index = fget_u2(arq);
		class_file->fields[i].descriptor_index = fget_u2(arq); 
		class_file->fields[i].attributes_count = fget_u2(arq);
		lerAttributesArray(arq, class_file->constant_pool, &(class_file->fields[i].attributes), class_file->fields[i].attributes_count);
	}

	return OK; 
}

int lerMethods(FILE *arq, ClassFile *class_file) {
	int i;
	u2 tamanho;
	tamanho = fget_u2(arq);

	/* aloca tamanho do array */
	class_file->methods_count = tamanho; 
	class_file->methods = malloc(sizeof(method_info) * tamanho);

	/* cria cada elemento do array */
	for (i = 0; i < tamanho; i++) { 
		class_file->methods[i].access_flags = fget_u2(arq);
		class_file->methods[i].name_index = fget_u2(arq);
		class_file->methods[i].descriptor_index = fget_u2(arq);
		class_file->methods[i].attributes_count = fget_u2(arq);             
		lerAttributesArray(arq, class_file->constant_pool, &(class_file->methods[i].attributes), class_file->methods[i].attributes_count);
	}

	return OK;
}

int lerAttributes(FILE *arq, ClassFile *class_file) {
	class_file->attributes_count = fget_u2(arq); 

	lerAttributesArray(arq, class_file->constant_pool, &(class_file->attributes), class_file->attributes_count);

	return OK;
}

int lerAttributesArray(FILE *arq, cp_info *info, attribute_info **attributes, int attributes_count) {
	int i, j;

	/* aloca tamanho do array */
	(*attributes) = malloc(sizeof(attribute_info) * attributes_count);

	/* cria cada elemento do array */
	for (i = 0; i < attributes_count; i++) {
		(*attributes)[i].attribute_name_index = fget_u2(arq);
		(*attributes)[i].attribute_length = fget_u4(arq);

		if (strncmp("Code", (char *)get_utf8_string(info, (*attributes)[i].attribute_name_index), strlen("Code")) == 0) {
			/* trata atribute code */
			(*attributes)[i].info.code.max_stack = fget_u2(arq);
			(*attributes)[i].info.code.max_locals = fget_u2(arq);

			/* le code */
			(*attributes)[i].info.code.code_length = fget_u4(arq);
			(*attributes)[i].info.code.code = malloc(sizeof(u1) * (*attributes)[i].info.code.code_length);
			for (j = 0; j < (*attributes)[i].info.code.code_length; j++) {
				(*attributes)[i].info.code.code[j] = fget_u1(arq);
			}

			/* cria tabela de excecoes */
			(*attributes)[i].info.code.exception_table_length = fget_u2(arq);
			(*attributes)[i].info.code.exceptions = malloc(sizeof(exception_table) * (*attributes)[i].info.code.exception_table_length);
			for (j = 0; j < (*attributes)[i].info.code.exception_table_length; j++) {
				(*attributes)[i].info.code.exceptions[j].start_pc = fget_u2(arq);
				(*attributes)[i].info.code.exceptions[j].end_pc = fget_u2(arq);
				(*attributes)[i].info.code.exceptions[j].handler_pc = fget_u2(arq);
				(*attributes)[i].info.code.exceptions[j].catch_type = fget_u2(arq);
			}

			/* cria atributos */
			(*attributes)[i].info.code.attributes_count = fget_u2(arq);
			lerAttributesArray(arq, info, &((*attributes)[i].info.code.attributes), (*attributes)[i].info.code.attributes_count);

		} else if (strncmp("LineNumberTable", (char *)get_utf8_string(info, (*attributes)[i].attribute_name_index), strlen("LineNumberTable")) == 0) {
			/* trata line number */
			(*attributes)[i].info.line_number_table.line_number_table_length = fget_u2(arq);
			(*attributes)[i].info.line_number_table.line_number = malloc(sizeof(LineNumberTable_attribute) * (*attributes)[i].info.line_number_table.line_number_table_length);
			for (j = 0; j < (*attributes)[i].info.line_number_table.line_number_table_length; j++) {
				(*attributes)[i].info.line_number_table.line_number[j].start_pc = fget_u2(arq);
				(*attributes)[i].info.line_number_table.line_number[j].line_number = fget_u2(arq);
			}

		} else if (strncmp("LocalVariableTable", (char *)get_utf8_string(info, (*attributes)[i].attribute_name_index), strlen("LocalVariableTable")) == 0) {
			/* trata local variable */
			(*attributes)[i].info.local_variable_table.local_variable_table_length = fget_u2(arq);
			(*attributes)[i].info.local_variable_table.local_variable = malloc(sizeof(LocalVariableTable_attribute) * (*attributes)[i].info.local_variable_table.local_variable_table_length);
			for (j = 0; j < (*attributes)[i].info.local_variable_table.local_variable_table_length; j++) {
				(*attributes)[i].info.local_variable_table.local_variable[j].start_pc = fget_u2(arq);
				(*attributes)[i].info.local_variable_table.local_variable[j].length = fget_u2(arq);
				(*attributes)[i].info.local_variable_table.local_variable[j].name_index = fget_u2(arq);
				(*attributes)[i].info.local_variable_table.local_variable[j].descriptor_index = fget_u2(arq);
				(*attributes)[i].info.local_variable_table.local_variable[j].index = fget_u2(arq);
			}

		} else {
			/* ignora atributo */
			for (j = 0; j < (*attributes)[i].attribute_length; j++) {
				fget_u1(arq);
			}
		}
	}

	return OK;
}

int read_class_file(FILE *arq, ClassFile *class_file) {
	u2 super_class;
	assert (arq != NULL);
	assert (class_file != NULL);

	/* le magic */
	class_file->magic = fget_u4(arq);

	/* verifica magic */
	if (class_file->magic != CONSTANT_Magic) {
		printf("Erro: arquivo nao e um .class\n");
		return 0;
	}

	/* le versoes */
	class_file->minor_version = fget_u2(arq);
	class_file->major_version = fget_u2(arq);

	/* le pool de constantes*/
	if (!lerConstantPool(arq, class_file)) {
		printf("Erro: nao foi possivel ler a sessao Constant Pool\n");
		return 0;
	}

	/*le a flag de acesso*/
	class_file->access_flags=fget_u2(arq);
	/*le a this_class*/
	class_file->this_class=fget_u2(arq);
	/*le super class*/
	super_class = fget_u2(arq);
	if (super_class <= class_file->constant_pool_count) {
		class_file->super_class = super_class;
	} else {
		class_file->super_class = 0;
	}

	/*le as interfaces*/
	if (!lerInterfaces(arq, class_file)) {
		printf("Erro: nao foi possivel ler a sessao Interfaces\n");
		return 0;
	}

	/*le os campos*/
	if (!lerFields(arq, class_file)) {
		printf("Erro: nao foi possivel ler a sessao Fields\n");
		return 0;
	}

	/*le os metodos*/
	if (!lerMethods(arq, class_file)) {
		printf("Erro: nao foi possivel ler a sessao Methods\n");
		return 0;
	}

	/*le os atributos*/
	if (!lerAttributes(arq, class_file)) {
		printf("Erro: nao foi possivel ler a sessao Attributes\n");
		return 0;
	}

	return OK;
}
