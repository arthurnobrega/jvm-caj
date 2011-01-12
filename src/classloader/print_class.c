/**
 * Alunos:
 *  Renato Carrasco Costa 07/37771
 *  Arthur ...
 *  Júlio ...
 *
 * Modulo de Impressao
 * - funcoes para impressao das diversas partes da estrutura do
 *   arquivo .class.
 *
 * Assertivas de entrada: estrutura valida.
**/
#include "headers/print_class.h"

void printf_help() {
	printf("USO: classview <ARQUIVO>\n");
}

int printf_Access_Flag(ClassFile class_file){
	u2 access_flags;
	access_flags = class_file.access_flags;

	printf("Access Flags: 0x%X [ ", access_flags); 
	if (is_bit(access_flags, 0))
		printf("public ");
	if (is_bit(access_flags, 4))
		printf("final ");
	if (is_bit(access_flags, 5))
		printf("super ");
	if (is_bit(access_flags, 9))
		printf("interface ");
	if (is_bit(access_flags, 10))
		printf("abstract ");
	printf("]");

	return OK;
}

int printf_General_Information(ClassFile class_file){
	cp_info *info;
	info = class_file.constant_pool;

	printf("Magic: 0x%X\n", class_file.magic);
	printf("Minor Version: %i\n", class_file.minor_version);
	printf("Major Version: %i\n", class_file.major_version);
	printf_Access_Flag(class_file); printf("\n");
	printf("This Class: cpinfo #%d { ",class_file.this_class);
	printf_class(info, class_file.this_class); printf(" }\n");
	printf("Super Class: cpinfo #%d { ",class_file.super_class);
	printf_class(info, class_file.super_class); printf(" }\n");
	printf("Constant Pool Count: %d\n",class_file.constant_pool_count);
	printf("Interfaces Count: %i\n",class_file.interfaces_count);
	printf("Fields Count: %d\n",class_file.fields_count);
	printf("Methods Count: %d\n",class_file.methods_count);

	return OK;
}


void printf_utf8(cp_info *info, int index) {
	printf("%ls", get_utf8(info, index));
}

void printf_name_and_type(cp_info *info, int index) {
	printf("%ls %ls",
		get_utf8(info, info[index].info.name_and_type_info.name_index),
		get_utf8(info, info[index].info.name_and_type_info.descriptor_index)
	);
}

void printf_class(cp_info *info, int index) {
	printf("%ls", get_utf8(info, info[index].info.class_info.name_index));
}

int printf_Interfaces(ClassFile class_file){
	int i;
	cp_info *info;
	u2 *interfaces;

	info = class_file.constant_pool;
	interfaces = class_file.interfaces;

	printf("Interfaces:\n");
	for (i = 0; i < class_file.interfaces_count; i++){
		printf("%i) cp_info #%d { ", i+1, interfaces[i]);
		printf_class(info, interfaces[i]); printf(" }\n");
	}

	return OK;
}

int printf_Field_Access_Flag(u2 access_flags){
	printf("[ ");
	if (is_bit(access_flags, 0))
		printf("public ");
	if (is_bit(access_flags, 1))
		printf("private ");
	if (is_bit(access_flags, 2))
		printf("protected ");
	if (is_bit(access_flags, 3))
		printf("static ");
	if (is_bit(access_flags, 4))
		printf("final ");
	if (is_bit(access_flags, 6))
		printf("volatile ");
	if (is_bit(access_flags, 7))
		printf("transient");
	printf("]");

	return OK;
}

int printf_Fields(ClassFile class_file){
	int i;
	cp_info *info;
	field_info *fields;

	info = class_file.constant_pool;
	fields = class_file.fields;

	printf("Fields:\n");
	for (i = 0; i < class_file.fields_count; i++) {
		printf("%d) ", i+1);
		printf_utf8(info, fields[i].name_index); printf("\n");
		printf("  -> name: cp_info #%d { ", fields[i].name_index);
		printf_utf8(info, fields[i].name_index); printf(" }\n");
		printf("  -> descriptor: cp_info #%d { ", fields[i].descriptor_index);
		printf_utf8(info, fields[i].descriptor_index); printf(" }\n");
		printf("  -> access flag: 0x%X ", fields[i].access_flags);
		printf_Field_Access_Flag(fields[i].access_flags); printf("\n");
		printf_Attributes_rec(info, fields[i].attributes, fields[i].attributes_count, 2);
	}

	return OK;
}

int printf_Method_Access_Flag(u2 access_flags){
	printf("[ ");
	if (is_bit(access_flags, 0))
		printf("public ");
	if (is_bit(access_flags, 1))
		printf("private ");
	if (is_bit(access_flags, 2))
		printf("protected ");
	if (is_bit(access_flags, 3))
		printf("static ");
	if (is_bit(access_flags, 4))
		printf("final ");
	if (is_bit(access_flags, 5))
		printf("synchronized ");
	if (is_bit(access_flags, 8))
		printf("native ");
	if (is_bit(access_flags, 10))
		printf("abstract ");
	if (is_bit(access_flags, 11))
		printf("strict ");
	printf("]");

	return OK;
}

int printf_Attributes_rec(cp_info *info, attribute_info *attributes, u2 attributes_count, int identacao) {
	int i, j;
	char *ident;
	Code_attribute code;
	LineNumberTable_attribute line_num;
	LocalVariableTable_attribute local_var;

	assert(info != NULL);
	assert(attributes != NULL);

	/* trata da identacao */
	if (identacao == 0) {
		ident = "";
		printf("Attributes:\n");
	} else {
		ident = malloc(identacao + 1);
		for (i = 0; i < identacao; i++) {
			ident[i] = ' ';
		}
		printf("%s-> attributes:\n", ident);
	}

	for (i = 0; i < attributes_count; i++) {
		printf("%s%d) ", ident, i+1);
		printf_utf8(info, attributes[i].attribute_name_index); printf("\n");
		printf("%s  -> attribute name index: cp_info #%d { ", ident, attributes[i].attribute_name_index);
		printf_utf8(info, attributes[i].attribute_name_index); printf(" }\n");
		printf("%s  -> attribute length: %d\n", ident, attributes[i].attribute_length);

		if (strncmp("Code", (char *)get_ascii(info, attributes[i].attribute_name_index), strlen("Code")) == 0) {
		/* trata atribute code */
			code = attributes[i].info.code;

			printf("%s  -> max stack: %i\n", ident, code.max_stack);
			printf("%s  -> max locals: %i\n", ident, code.max_locals);

			/* le code */
			printf("%s  -> code length: %i\n", ident, code.code_length);
			printf("%s  -> code: ", ident);
			for (j = 0; j < code.code_length; j++) {
				printf("0x%X ", code.code[j]);
			}
			printf("\n");

			/* cria tabela de excecoes */
			printf("%s  -> exception table length: %i\n", ident, code.exception_table_length);
			for (j = 0; j < code.exception_table_length; j++) {
				printf("%s    -> start pc: %i\n", ident, code.exceptions[j].start_pc);
				printf("%s    -> end pc: %i\n", ident, code.exceptions[j].end_pc);
				printf("%s    -> handler pc: %i\n", ident, code.exceptions[j].handler_pc);
				printf("%s    -> catch type: %i\n", ident, code.exceptions[j].catch_type);
			}

			/* cria atributos */
			printf("%s  -> attributes count: %i\n", ident, code.attributes_count);
			printf_Attributes_rec(info, code.attributes, code.attributes_count, identacao + 2);

		} else if (strncmp("LineNumberTable", (char *)get_ascii(info, attributes[i].attribute_name_index), strlen("LineNumberTable")) == 0) {
		/* trata line number */
			line_num = attributes[i].info.line_number_table;

			printf("%s  -> line number table length: %i\n", ident, line_num.line_number_table_length);
			for (j = 0; j < line_num.line_number_table_length; j++) {
				printf("%s    -> start pc: %i\n", ident, line_num.line_number[j].start_pc);
				printf("%s       line number: %i\n", ident, line_num.line_number[j].line_number);
			}

		} else if (strncmp("LocalVariableTable", (char *)get_ascii(info, attributes[i].attribute_name_index), strlen("LocalVariableTable")) == 0) {
		/* trata local variable */
			local_var = attributes[i].info.local_variable_table;

			printf("%s  -> local variable table length: %i\n", ident, local_var.local_variable_table_length);
			for (j = 0; j < local_var.local_variable_table_length; j++) {
				printf("%s    -> start pc: %i\n", ident, local_var.local_variable[j].start_pc);
				printf("%s       length: %i\n", ident, local_var.local_variable[j].length);
				printf("%s       name index: cp_info #%i { ", ident, local_var.local_variable[j].name_index);
				printf_utf8(info, local_var.local_variable[j].name_index); printf(" }\n");
				printf("%s       descriptor index: cp_info #%i { ", ident, local_var.local_variable[j].descriptor_index);
				printf_utf8(info, local_var.local_variable[j].descriptor_index); printf(" }\n");
				printf("%s       index: %i\n", ident, local_var.local_variable[j].index);
			}
		}
	}

	return OK;
}

int printf_Attributes(ClassFile class_file){
	return printf_Attributes_rec(class_file.constant_pool, class_file.attributes, class_file.attributes_count, 0);
}

int printf_Methods(ClassFile class_file) {
	int i;
	cp_info *info;
	method_info *methods;

	info = class_file.constant_pool;
	methods = class_file.methods;

	printf("Methods:\n");
	for (i = 0; i < class_file.methods_count; i++) {
		printf("%d) ", i+1);
		printf_utf8(info, methods[i].name_index); printf("\n");
		printf("  -> name: cp_info #%d { ", methods[i].name_index);
		printf_utf8(info, methods[i].name_index); printf(" }\n");
		printf("  -> descriptor: cp_info #%d { ", methods[i].descriptor_index);
		printf_utf8(info, methods[i].descriptor_index); printf(" }\n");
		printf("  -> access flag: 0x%X ", methods[i].access_flags);
		printf_Method_Access_Flag(methods[i].access_flags); printf("\n");
		printf_Attributes_rec(info, methods[i].attributes, methods[i].attributes_count, 2);
	}

	return OK;
}

int printf_Constant_Pool(ClassFile class_file) {
	int i;
	cp_info *info;
	info = class_file.constant_pool;

	printf("Constant Pool:\n");
	for (i = 1; i < class_file.constant_pool_count; i++) {
		switch (info[i].tag) {
		case CONSTANT_Class:
			printf("%i) Class\n", i);
			printf("  -> tag: %i\n", info[i].tag);
			printf("  -> name_index: cp_info #%i { ", info[i].info.class_info.name_index);
			printf_utf8(info, info[i].info.class_info.name_index); printf(" }\n");
			break;
		case CONSTANT_String:
			printf("%i) String\n", i);
			printf("  -> tag: %i\n", info[i].tag);
			printf("  -> string_index: cp_info #%i { ", info[i].info.string_info.string_index);
			printf_utf8(info, info[i].info.string_info.string_index); printf(" }\n");
			break;
		case CONSTANT_Fieldref:
			printf("%i) Field\n", i);
			printf("  -> tag: %i\n", info[i].tag);
			printf("  -> class_index: cp_info #%i { ", info[i].info.fieldref_info.class_index);
			printf_class(info, info[i].info.fieldref_info.class_index); printf(" }\n");
			printf("  -> name_and_type_index: cp_info #%i { ", info[i].info.fieldref_info.name_and_type_index);
			printf_name_and_type(info, info[i].info.fieldref_info.name_and_type_index); printf(" }\n");
			break;
		case CONSTANT_Methodref:
			printf("%i) Method\n", i);
			printf("  -> tag: %i\n", info[i].tag);
			printf("  -> class_index: cp_info #%i { ", info[i].info.methodref_info.class_index);
			printf_class(info, info[i].info.methodref_info.class_index); printf(" }\n");
			printf("  -> name_and_type_index: cp_info #%i { ", info[i].info.methodref_info.name_and_type_index);
			printf_name_and_type(info, info[i].info.methodref_info.name_and_type_index); printf(" }\n");
			break;
		case CONSTANT_InterfaceMethodref:
			printf("%i) Interface Method\n", i);
			printf("  -> tag: %i\n", info[i].tag);
			printf("  -> class_index: cp_info #%i {", info[i].info.interface_methodref_info.class_index);
			printf_class(info, info[i].info.interface_methodref_info.class_index); printf(" }\n");
			printf("  -> name_and_type_index: cp_info #%i { ", info[i].info.interface_methodref_info.name_and_type_index);
			printf_name_and_type(info, info[i].info.interface_methodref_info.name_and_type_index); printf(" }\n");
			break;
		case CONSTANT_NameAndType:
			printf("%i) Name And Type\n", i);
			printf("  -> tag: %i\n", info[i].tag);
			printf("  -> name_index: cp_info #%i { ", info[i].info.name_and_type_info.name_index);
			printf_utf8(info, info[i].info.name_and_type_info.name_index); printf(" }\n");
			printf("  -> descriptor_index: cp_info #%i { ", info[i].info.name_and_type_info.descriptor_index);
			printf_utf8(info, info[i].info.name_and_type_info.descriptor_index); printf(" }\n");
			break;
		case CONSTANT_Integer:
			printf("%i) Integer\n", i);
			printf("  -> tag: %i\n", info[i].tag);
			printf("  -> bytes: %i\n", info[i].info.integer_info.bytes);
			break;
		case CONSTANT_Float:
			printf("%i) Float\n", i);
			printf("  -> tag: %i\n", info[i].tag);
			printf("  -> bytes: %i\n", info[i].info.float_info.bytes);
			break;
		case CONSTANT_Long:
			printf("%i) Long\n", i);
			printf("  -> tag: %i\n", info[i].tag);
			printf("  -> high_bytes: %i\n", info[i].info.long_info.high_bytes);
			printf("  -> low_bytes: %i\n", info[i].info.long_info.low_bytes);
			break;
		case CONSTANT_Double:
			printf("%i) Double\n", i);
			printf("  -> tag: %i\n", info[i].tag);
			printf("  -> high_bytes: %i\n", info[i].info.double_info.high_bytes);
			printf("  -> low_bytes: %i\n", info[i].info.double_info.low_bytes);
			break;
		case CONSTANT_Utf8:
			printf("%i) Utf8\n", i);
			printf("  -> tag: %i\n", info[i].tag);
			printf("  -> length: %i\n", info[i].info.utf8_info.length);
                        printf("  -> bytes: ");
			printf_utf8(info, i); printf("\n");
			break;
		default:
			return 0;
		}
	}
	return 1;
}
