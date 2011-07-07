/*
 Universidade de Brasilia
 Instituto de Ciencias Exatas
 Departamento de Ciencia da Computacao
 Software Basico
 Turma A - 02/2010

 Arthur Thiago Barbosa Nobrega 06/31205
 Julio Cesar Junior 05/34986
 Renato Carrasco Costa 07/37771
 
 class_struc.c: modulo que le a estrutura do arquivo .class.
 Assertivas de entrada: arquivos e ponteiros para estrutura validos.
 */

#include "class_struc.h"

void read_utf8(FILE *arq, CONSTANT_Utf8_info *utf8_info) {
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

int read_constant_pool(FILE *arq, ClassFile *class_file) {
	int i;
	u1 tag;
	u2 tamanho = fget_u2(arq);
	cp_info *info;

	assert (arq != NULL);
	assert (class_file != NULL);

	/* aloca tamanho do array */
	class_file->constant_pool_count = tamanho;
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
#ifdef DEBUG
		printf("\nCONSTANT_String em lerConstantPool %d\n",tag);
#endif
			info[i].info.string_info.string_index = fget_u2(arq);
			break;

			/* elementos de mesma assinatura (u2, u2) */
		case CONSTANT_Fieldref:
		case CONSTANT_Methodref:
		case CONSTANT_InterfaceMethodref:
		case CONSTANT_NameAndType:
#ifdef DEBUG
		printf("\nCONSTANT_NameAndType em lerConstantPool %d\n",tag);
#endif
			info[i].info.name_and_type_info.name_index = fget_u2(arq);
			info[i].info.name_and_type_info.descriptor_index = fget_u2(arq);
			break;

			/* elementos de mesma assinatura (u4) */
		case CONSTANT_Integer:
#ifdef DEBUG
		printf("\nCONSTANT_Integer em lerConstantPool %d\n",tag);
#endif
			info[i].info.integer_info.bytes = fget_u4(arq);
			break;
		case CONSTANT_Float:
#ifdef DEBUG
		printf("\nCONSTANT_Float em lerConstantPool %d\n",tag);
#endif
			info[i].info.float_info.bytes = fget_u4(arq);
			break;

			/* elementos de mesma assinatura (u4, u4) */
		case CONSTANT_Long:
#ifdef DEBUG
		printf("\nCONSTANT_Long em lerConstantPool %d\n",tag);
#endif
			info[i].info.long_info.high_bytes = fget_u4(arq);
			info[i].info.long_info.low_bytes = fget_u4(arq);
			i++;
			break;
		case CONSTANT_Double:
#ifdef DEBUG
		printf("\nCONSTANT_DOUBLE em lerConstantPool %d\n",tag);
#endif
			info[i].info.double_info.high_bytes = fget_u4(arq);
			info[i].info.double_info.low_bytes = fget_u4(arq);
			i++;
			break;

		case CONSTANT_Utf8:
#ifdef DEBUG
		printf("\nCONSTANT_Utf8 em lerConstantPool %d\n",tag);
#endif
			read_utf8(arq, &(info[i].info.utf8_info));
			break;

		default:
			/*TODO: Verificar se para.*/
#ifdef DEBUG
			printf("\nUNDEFINED_FLAG em lerConstantPool %d\n",tag);
#endif
			return UNDEFINED_FLAG;
		}
	}
	return OK;
}

int read_interfaces(FILE *arq, ClassFile *class_file) {
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

int read_fields(FILE *arq, ClassFile *class_file) {
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

		read_attributes_array(arq, class_file->constant_pool, &(class_file->fields[i].attributes), class_file->fields[i].attributes_count);
	}

	return OK; 
}

int read_methods(FILE *arq, ClassFile *class_file) {
	int i;
	u2 tamanho;
	tamanho = fget_u2(arq);
#ifdef DEBUG
	printf(">>>lerMethods -> alocando tamanho do array? %d\n", tamanho);
#endif
	/* aloca tamanho do array */
	class_file->methods_count = tamanho; 
	class_file->methods = malloc(sizeof(method_info) * tamanho);
#ifdef DEBUG
	printf(">>>lerMethods -> criando cada elemento do array\n");
#endif
	/* cria cada elemento do array */
	for (i = 0; i < tamanho; i++) { 
		class_file->methods[i].access_flags = fget_u2(arq);
		class_file->methods[i].name_index = fget_u2(arq);
		class_file->methods[i].descriptor_index = fget_u2(arq);
		class_file->methods[i].attributes_count = fget_u2(arq);             
		read_attributes_array(arq, class_file->constant_pool, &(class_file->methods[i].attributes), class_file->methods[i].attributes_count);
	}
#ifdef DEBUG
	printf(">>>lerMethods -> alocado tamanho do array\n");
#endif
	return OK;
}

int read_attributes(FILE *arq, ClassFile *class_file) {
	class_file->attributes_count = fget_u2(arq);

	read_attributes_array(arq, class_file->constant_pool, &(class_file->attributes), class_file->attributes_count);

	return OK;
}

int read_attributes_array(FILE *arq, cp_info *constant_pool, attribute_info **attributes, int attributes_count) {
	int i, j;

	/* aloca tamanho do array */
	(*attributes) = malloc(sizeof(attribute_info) * attributes_count);

	/* cria cada elemento do array */
#ifdef DEBUG
	printf("Attributes count: %d\n",attributes_count);
#endif
	for (i = 0; i < attributes_count; i++) {
		(*attributes)[i].attribute_name_index = fget_u2(arq);
		(*attributes)[i].attribute_length = fget_u4(arq);

#ifdef DEBUG
		int name_index = (*attributes)[i].attribute_name_index;
		printf("Attribute Name Index: %d\n", name_index);
		printf("Attribute Name: %s\n", get_utf8_string(constant_pool, name_index));
		printf("Attribute Length: %d\n", (*attributes)[i].attribute_length);
	printf(">>>read_attributes_array: vai testar o tipo de attributo\n");
#endif
		if (strncmp("Code", (char *)get_utf8_string(constant_pool, (*attributes)[i].attribute_name_index), strlen("Code")) == 0) {
			/* trata atribute code */
#ifdef DEBUG
	printf(">>>read_attributes_array: entrou em Code\n");
#endif
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
			read_attributes_array(arq, constant_pool, &((*attributes)[i].info.code.attributes), (*attributes)[i].info.code.attributes_count);

		} else if (strncmp("LineNumberTable", (char *)get_utf8_string(constant_pool, (*attributes)[i].attribute_name_index), strlen("LineNumberTable")) == 0) {
			/* trata line number */
#ifdef DEBUG
	printf(">>>read_attributes_array: LineNumberTable\n");
#endif
			(*attributes)[i].info.line_number_table.line_number_table_length = fget_u2(arq);
			(*attributes)[i].info.line_number_table.line_number = malloc(sizeof(LineNumberTable_attribute) * (*attributes)[i].info.line_number_table.line_number_table_length);
			for (j = 0; j < (*attributes)[i].info.line_number_table.line_number_table_length; j++) {
				(*attributes)[i].info.line_number_table.line_number[j].start_pc = fget_u2(arq);
				(*attributes)[i].info.line_number_table.line_number[j].line_number = fget_u2(arq);
			}
#ifdef DEBUG
	printf(">>>read_attributes_array: LineNumberTable ok\n");
#endif
		} else if (strncmp("LocalVariableTable", (char *)get_utf8_string(constant_pool, (*attributes)[i].attribute_name_index), strlen("LocalVariableTable")) == 0) {
			/* trata local variable */
#ifdef DEBUG
	printf(">>>read_attributes_array: LocalVariableTable\n");
#endif
			(*attributes)[i].info.local_variable_table.local_variable_table_length = fget_u2(arq);
			(*attributes)[i].info.local_variable_table.local_variable = malloc(sizeof(LocalVariableTable_attribute) * (*attributes)[i].info.local_variable_table.local_variable_table_length);
			for (j = 0; j < (*attributes)[i].info.local_variable_table.local_variable_table_length; j++) {
				(*attributes)[i].info.local_variable_table.local_variable[j].start_pc = fget_u2(arq);
				(*attributes)[i].info.local_variable_table.local_variable[j].length = fget_u2(arq);
				(*attributes)[i].info.local_variable_table.local_variable[j].name_index = fget_u2(arq);
				(*attributes)[i].info.local_variable_table.local_variable[j].descriptor_index = fget_u2(arq);
				(*attributes)[i].info.local_variable_table.local_variable[j].index = fget_u2(arq);
			}
#ifdef DEBUG
	printf(">>>read_attributes_array: LocalVariableTable ok\n");
#endif
		} else {
#ifdef DEBUG
			printf(">>>read_attributes_array: ignora atributo\n");
		#endif
			/* ignora atributo */
			for (j = 0; j < (*attributes)[i].attribute_length; j++) {
				fget_u1(arq);
			}
#ifdef DEBUG
	printf(">>>read_attributes_array: ignorado\n");
#endif
		}
#ifdef DEBUG
	printf(">>>read_attributes_array: saindo do if dentro de for\n");
#endif
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
	if (!read_constant_pool(arq, class_file)) {
		printf("Erro: nao foi possivel ler a sessao Constant Pool\n");
		return 0;
	}
#ifdef DEBUG
	printf("CONSTANTPOOL lido\n");
#endif
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
#ifdef DEBUG
	printf("->interfaces serao lidas\n");
#endif
	/*le as interfaces*/
	if (!read_interfaces(arq, class_file)) {
		printf("Erro: nao foi possivel ler a sessao Interfaces\n");
		return 0;
	}
#ifdef DEBUG
	printf("->fields serao lidos\n");
#endif
	/*le os campos*/
	if (!read_fields(arq, class_file)) {
		printf("Erro: nao foi possivel ler a sessao Fields\n");
		return 0;
	}
#ifdef DEBUG
	printf("->Methods serao lidos\n");
#endif
	/*le os metodos*/
	if (!read_methods(arq, class_file)) {
		printf("Erro: nao foi possivel ler a sessao Methods\n");
		return 0;
	}
#ifdef DEBUG
	printf("->Attributes serao lidos\n");
#endif
	/*le os atributos*/
	if (!read_attributes(arq, class_file)) {
		printf("Erro: nao foi possivel ler a sessao Attributes\n");
		return 0;
	}
	return OK;
}
