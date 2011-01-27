/*
 Universidade de Brasilia
 Instituto de Ciencias Exatas
 Departamento de Ciencia da Computacao
 Software Basico
 Turma A - 02/2010

 Arthur Thiago Barbosa Nobrega 06/31205
 Julio Cesar Junior 05/34986
 Renato Carrasco Costa 07/37771

 bits.c: fornece funcoes utilitarias para tratamento de operacoes de baixo nivel
 como conversao de endianess e bits.
 */

/**
 * Modulo de Impressao
 * - funcoes para impressao das diversas partes da estrutura do
 *   arquivo .class.
 *
 * Assertivas de entrada: estrutura valida.
**/
#include "print_class.h"
#include "class_util.h"

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
	printf("]\n");

	return OK;
}

int printf_General_Information(ClassFile class_file) {
	cp_info *info;
	u1* class_name = get_class_name_classfile(&class_file);
	info = class_file.constant_pool;
	printf("\n\n----------------------------------------------\n");
	printf("INFORMACOES DO CLASSFILE DA CLASSE '%s' \n",class_name);
	printf("----------------------------------------------\n");
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
	printf("----------------------------------------------\n\n");

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
	/**
	 * vetor de mnemonicos
	 * */
	char *instrucao [0xd0];
	instrucao[0x00] = "_nop";
		instrucao[0x01] = "_aconst_null";
		instrucao[0x02] = "_iconst_m1";
		instrucao[0x03] = "_iconst_0";
		instrucao[0x04] = "_iconst_1";
		instrucao[0x05] = "_iconst_2";
		instrucao[0x06] = "_iconst_3";
		instrucao[0x07] = "_iconst_4";
		instrucao[0x08] = "_iconst_5";
		instrucao[0x09] = "_lconst_0";
		instrucao[0x0a] = "_lconst_1";
		instrucao[0x0b] = "_fconst_0";
		instrucao[0x0c] = "_fconst_1";
		instrucao[0x0d] = "_fconst_2";
		instrucao[0x0e] = "_dconst_0";
		instrucao[0x0f] = "_dconst_1";
		instrucao[0x10] = "_bipush";
		instrucao[0x11] = "_sipush";
		instrucao[0x12] = "_ldc";
		instrucao[0x13] = "_ldc_w";
		instrucao[0x14] = "_ldc2_w";
		instrucao[0x15] = "_iload";
		instrucao[0x16] = "_lload";
		instrucao[0x17] = "_fload";
		instrucao[0x18] = "_dload";
		instrucao[0x19] = "_aload";
		instrucao[0x1a] = "_iload_0";
		instrucao[0x1b] = "_iload_1";
		instrucao[0x1c] = "_iload_2";
		instrucao[0x1d] = "_iload_3";
		instrucao[0x1e] = "_lload_0";
		instrucao[0x1f] = "_lload_1";
		instrucao[0x20] = "_lload_2";
		instrucao[0x21] = "_lload_3";
		instrucao[0x22] = "_fload_0";
		instrucao[0x23] = "_fload_1";
		instrucao[0x24] = "_fload_2";
		instrucao[0x25] = "_fload_3";
		instrucao[0x26] = "_dload_0";
		instrucao[0x27] = "_dload_1";
		instrucao[0x28] = "_dload_2";
		instrucao[0x29] = "_dload_3";
		instrucao[0x2a] = "_aload_0";
		instrucao[0x2b] = "_aload_1";
		instrucao[0x2c] = "_aload_2";
		instrucao[0x2d] = "_aload_3";
		instrucao[0x2e] = "_iaload";
		instrucao[0x2f] = "_laload";
		instrucao[0x30] = "_faload";
		instrucao[0x31] = "_daload";
		instrucao[0x32] = "_aaload";
		instrucao[0x33] = "_baload";
		instrucao[0x34] = "_caload";
		instrucao[0x35] = "_saload";
		instrucao[0x36] = "_istore";
		instrucao[0x37] = "_lstore";
		instrucao[0x38] = "_fstore";
		instrucao[0x39] = "_dstore";
		instrucao[0x3a] = "_astore";
		instrucao[0x3b] = "_istore_0";
		instrucao[0x3c] = "_istore_1";
		instrucao[0x3d] = "_istore_2";
		instrucao[0x3e] = "_istore_3";
		instrucao[0x3f] = "_lstore_0";
		instrucao[0x40] = "_lstore_1";
		instrucao[0x41] = "_lstore_2";
		instrucao[0x42] = "_lstore_3";
		instrucao[0x43] = "_fstore_0";
		instrucao[0x44] = "_fstore_1";
		instrucao[0x45] = "_fstore_2";
		instrucao[0x46] = "_fstore_3";
		instrucao[0x47] = "_dstore_0";
		instrucao[0x48] = "_dstore_1";
		instrucao[0x49] = "_dstore_2";
		instrucao[0x4a] = "_dstore_3";
		instrucao[0x4b] = "_astore_0";
		instrucao[0x4c] = "_astore_1";
		instrucao[0x4d] = "_astore_2";
		instrucao[0x4e] = "_astore_3";
		instrucao[0x4f] = "_iastore";
		instrucao[0x50] = "_lastore";
		instrucao[0x51] = "_fastore";
		instrucao[0x52] = "_dastore";
		instrucao[0x53] = "_aastore";
		instrucao[0x54] = "_bastore";
		instrucao[0x55] = "_castore";
		instrucao[0x56] = "_sastore";
		instrucao[0x57] = "_pop";
		instrucao[0x58] = "_pop2";
		instrucao[0x59] = "_dup";
		instrucao[0x5a] = "_dup_x1";
		instrucao[0x5b] = "_dup_x2";
		instrucao[0x5c] = "_dup2";
		instrucao[0x5d] = "_dup2_x1";
		instrucao[0x5e] = "_dup2_x2";
		instrucao[0x5f] = "_swap";
		instrucao[0x60] = "_iadd";
		instrucao[0x61] = "_ladd";
		instrucao[0x62] = "_fadd";
		instrucao[0x63] = "_dadd";
		instrucao[0x64] = "_isub";
		instrucao[0x65] = "_lsub";
		instrucao[0x66] = "_fsub";
		instrucao[0x67] = "_dsub";
		instrucao[0x68] = "_imul";
		instrucao[0x69] = "_lmul";
		instrucao[0x6a] = "_fmul";
		instrucao[0x6b] = "_dmul";
		instrucao[0x6c] = "_idiv";
		instrucao[0x6d] = "_ldiv";
		instrucao[0x6e] = "_fdiv";
		instrucao[0x6f] = "_ddiv";
		instrucao[0x70] = "_irem";
		instrucao[0x71] = "_lrem";
		instrucao[0x72] = "_frem";
		instrucao[0x73] = "_drem";
		instrucao[0x74] = "_ineg";
		instrucao[0x75] = "_lneg";
		instrucao[0x76] = "_fneg";
		instrucao[0x77] = "_dneg";
		instrucao[0x78] = "_ishl";
		instrucao[0x79] = "_lshl";
		instrucao[0x7a] = "_ishr";
		instrucao[0x7b] = "_lshr";
		instrucao[0x7c] = "_iushr";
		instrucao[0x7d] = "_lushr";
		instrucao[0x7e] = "_iand";
		instrucao[0x7f] = "_land";
		instrucao[0x80] = "_ior";
		instrucao[0x81] = "_lor";
		instrucao[0x82] = "_ixor";
		instrucao[0x83] = "_lxor";
		instrucao[0x84] = "_iinc";
		instrucao[0x85] = "_i2l";
		instrucao[0x86] = "_i2fv";
		instrucao[0x87] = "_i2d";
		instrucao[0x88] = "_l2i";
		instrucao[0x89] = "_l2f";
		instrucao[0x8a] = "_l2d";
		instrucao[0x8b] = "_f2i";
		instrucao[0x8c] = "_f2l";
		instrucao[0x8d] = "_f2d";
		instrucao[0x8e] = "_d2i";
		instrucao[0x8f] = "_d2l";
		instrucao[0x90] = "_d2f";
		instrucao[0x91] = "_i2b";
		instrucao[0x92] = "_i2c";
		instrucao[0x93] = "_i2s";
		instrucao[0x94] = "_lcmp";
		instrucao[0x95] = "_fcmpl";
		instrucao[0x96] = "_fcmpg";
		instrucao[0x97] = "_dcmpl";
		instrucao[0x98] = "_dcmpg";
		instrucao[0x99] = "_ifeq";
		instrucao[0x9a] = "_ifne";
		instrucao[0x9b] = "_iflt";
		instrucao[0x9c] = "_ifge";
		instrucao[0x9d] = "_ifgt";
		instrucao[0x9e] = "_ifle";
		instrucao[0x9f] = "_if_icmpeq";
		instrucao[0xa0] = "_if_icmpne";
		instrucao[0xa1] = "_if_icmplt";
		instrucao[0xa2] = "_if_icmpge";
		instrucao[0xa3] = "_if_icmpgt";
		instrucao[0xa4] = "_if_icmple";
		instrucao[0xa5] = "_if_acmpeq";
		instrucao[0xa6] = "_if_acmpne";
		instrucao[0xa7] = "_goto";
		instrucao[0xa8] = "_jsr";
		instrucao[0xa9] = "_ret";
		instrucao[0xaa] = "_tableswitch";
		instrucao[0xab] = "_lookupswitch";
		instrucao[0xac] = "_ireturn";
		instrucao[0xad] = "_lreturn";
		instrucao[0xae] = "_freturn";
		instrucao[0xaf] = "_dreturn";
		instrucao[0xb0] = "_areturn";
		instrucao[0xb1] = "_return";
		instrucao[0xb2] = "_getstatic";
		instrucao[0xb3] = "_putstatic";
		instrucao[0xb4] = "_getfield";
		instrucao[0xb5] = "_putfield";
		instrucao[0xb6] = "_invokevirtual";
		instrucao[0xb7] = "_invokespecial";
		instrucao[0xb8] = "_invokestatic";
		instrucao[0xb9] = "_invokeinterface";
		/*instrucao[0xba] = _xxxunusedxxx1;*/
		instrucao[0xbb] = "_new";
		instrucao[0xbc] = "_newarray";
		instrucao[0xbd] = "_anewarray";
		instrucao[0xbe] = "_arraylength";
		instrucao[0xbf] = "_athrow";
		instrucao[0xc0] = "_checkcast";
		instrucao[0xc1] = "_instanceof";
		instrucao[0xc2] = "_monitorenter";
		instrucao[0xc3] = "_monitorexit";
		instrucao[0xc4] = "_wide";
		instrucao[0xc5] = "_multianewarray";
		instrucao[0xc6] = "_ifnull";
		instrucao[0xc7] = "_ifnonnull";
		instrucao[0xc8] = "_goto_w";
		instrucao[0xc9] = "_jsr_w";

	assert(info != NULL);
	assert(attributes != NULL);

	/* trata da identacao */
	if (identacao == 0) {
		ident = "";
		printf("Attributes:\n");
	} else {
		ident = malloc(identacao + 1);
		memcpy(ident, " ", strlen(ident));
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

		if (strncmp("Code", (char *)get_utf8_string(info, attributes[i].attribute_name_index), strlen("Code")) == 0) {
		/* trata atribute code */
			code = attributes[i].info.code;

			printf("%s  -> max stack: %i\n", ident, code.max_stack);
			printf("%s  -> max locals: %i\n", ident, code.max_locals);

			/* le code */
			printf("%s  -> code length: %i\n", ident, code.code_length);
			printf("%s  -> code: ", ident);
			for (j = 0; j < code.code_length; j++) {
				printf("%s ", instrucao[code.code[j]]);
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

		} else if (strncmp("LineNumberTable", (char *)get_utf8_string(info, attributes[i].attribute_name_index), strlen("LineNumberTable")) == 0) {
		/* trata line number */
			line_num = attributes[i].info.line_number_table;

			printf("%s  -> line number table length: %i\n", ident, line_num.line_number_table_length);
			for (j = 0; j < line_num.line_number_table_length; j++) {
				printf("%s    -> start pc: %i\n", ident, line_num.line_number[j].start_pc);
				printf("%s       line number: %i\n", ident, line_num.line_number[j].line_number);
			}

		} else if (strncmp("LocalVariableTable", (char *)get_utf8_string(info, attributes[i].attribute_name_index), strlen("LocalVariableTable")) == 0) {
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
