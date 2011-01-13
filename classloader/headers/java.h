/*
 Universidade de Brasilia
 Instituto de Ciencias Exatas
 Departamento de Ciencia da Computacao
 Software Basico
 Turma A - 02/2010
 
 java.h: interface basica que define a estrutura do arquivo .class segundo a especificacao da Sun 
 */
#ifndef JAVA_H
#define JAVA_H

typedef unsigned int u4;
typedef unsigned short u2;
typedef unsigned char u1;

#define CONSTANT_Magic      0xCAFEBABE

#define CONSTANT_Class      7
#define CONSTANT_Fieldref   9
#define CONSTANT_Methodref 10
#define CONSTANT_InterfaceMethodref 11
#define CONSTANT_String     8
#define CONSTANT_Integer    3
#define CONSTANT_Float      4
#define CONSTANT_Long 	    5
#define CONSTANT_Double     6
#define CONSTANT_NameAndType 12
#define CONSTANT_Utf8 	    1

typedef struct {
//	u1 tag; // Valor 7
	u2 name_index;
} CONSTANT_Class_info;

typedef struct {
//	u1 tag; // Valor 9
	u2 class_index;
	u2 name_and_type_index;
} CONSTANT_Fieldref_info;

typedef struct {
//	u1 tag;  Valor 10
	u2 class_index;
	u2 name_and_type_index;
} CONSTANT_Methodref_info;

typedef struct {
//	u1 tag; // Valor 11
	u2 class_index;
	u2 name_and_type_index;
} CONSTANT_InterfaceMethodref_info;

typedef struct {
//	u1 tag; // Valor 8
	u2 string_index;
} CONSTANT_String_info;

typedef struct {
//	u1 tag; // Valor 3
	u4 bytes;
} CONSTANT_Integer_info ;

typedef struct {
//	u1 tag; // Valor 4
	u4 bytes;
} CONSTANT_Float_info ;

typedef struct {
//	u1 tag; // Valor 5
	u4 high_bytes;
	u4 low_bytes;
} CONSTANT_Long_info;

typedef struct {
//	u1 tag; // Valor 6
	u4 high_bytes;
	u4 low_bytes;
} CONSTANT_Double_info;

typedef struct {
//	u1 tag; // Valor 12
	u2 name_index;
	u2 descriptor_index;
} CONSTANT_NameAndType_info;

typedef struct {
//	u1 tag; // Valor 1
	u2 length;
	u1 *bytes;
} CONSTANT_Utf8_info;

/*Defines do Access Table*/
#define ACC_PUBLIC 	0x0001
#define ACC_FINAL 	0x0010 	
#define ACC_SUPER 	0x0020 	
#define ACC_INTERFACE 	0x0200
#define ACC_ABSTRACT 	0x0400

/*Field Access Flags*/
#define ACC_PRIVATE 	0x0002 	/*Declared private; usable only within the defining class.*/
#define ACC_PROTECTED 	0x0004 	/*Declared protected; may be accessed within subclasses.*/
#define ACC_STATIC 	0x0008 	/*Declared static.*/
#define ACC_VOLATILE 	0x0040 	/*Declared volatile; cannot be cached.*/
#define ACC_TRANSIENT 	0x0080

/*Method Access Flags*/
#define ACC_SYNCHRONIZED 	0x0020 	/*Declared synchronized; invocation is wrapped in a monitor lock.*/
#define ACC_NATIVE 	0x0100 	/*Declared native; implemented in a language other than Java.*/
#define ACC_STRICT 	0x0800

typedef union {
	CONSTANT_Class_info class_info;
	CONSTANT_Fieldref_info fieldref_info;
	CONSTANT_Methodref_info methodref_info;
	CONSTANT_InterfaceMethodref_info interface_methodref_info;
	CONSTANT_Utf8_info utf8_info;
	CONSTANT_NameAndType_info name_and_type_info;
	CONSTANT_Double_info double_info;
	CONSTANT_Long_info long_info;
	CONSTANT_Float_info float_info;
	CONSTANT_Integer_info integer_info;
	CONSTANT_String_info string_info;
} info_union;

typedef struct {
	u1 tag;
	info_union info;
} cp_info;
/*
typedef struct {
    	u2 attribute_name_index;
    	u4 attribute_length;
    	u1 * info;
    } attribute_info;
Predefined attributes*/

typedef struct {
	/*u2 attribute_name_index;
    	u4 attribute_length;*/
	u2 sourcefile_index;
} SourceFile_attribute;

typedef struct {
	/*u2 attribute_name_index;
    	u4 attribute_length;*/
	u2 constantvalue_index;
} ConstantValue_attribute;

typedef struct {
	u2 start_pc;
	u2 end_pc;
	u2 handler_pc;
	u2 catch_type;
} exception_table;   

typedef struct attribute_info_struct attribute_info;

typedef struct {
	/*u2 attribute_name_index;
    	u4 attribute_length;*/
	u2 max_stack;
	u2 max_locals;
	u4 code_length;
	u1 *code;
	u2 exception_table_length;
	exception_table *exceptions;
	u2 attributes_count;
	attribute_info *attributes;
} Code_attribute;

typedef struct {
	/*u2 attribute_name_index;
    	u4 attribute_length;*/
	u2 number_of_exceptions;
	u2 *exception_index_table;
} Exceptions_attribute;

typedef struct {  
	u2 inner_class_info_index;	     
	u2 outer_class_info_index;	     
	u2 inner_name_index;	     
	u2 inner_class_access_flags;	     
} type_classes;

typedef struct {
	/*u2 attribute_name_index;
    	u4 attribute_length;*/
	u2 number_of_classes;
	type_classes *classes;
}InnerClasses_attribute;

typedef struct {
	u2 start_pc;
	u2 line_number;	     
} line_number_table;

typedef struct {
	u2 attribute_name_index;
	u4 attribute_length;
	u2 line_number_table_length;
	line_number_table *line_number;
} LineNumberTable_attribute;

typedef struct {
	u2 start_pc;
	u2 length;
	u2 name_index;
	u2 descriptor_index;
	u2 index;
} local_variable_table;

typedef struct {
	u2 attribute_name_index;
	u4 attribute_length;
	u2 local_variable_table_length;
	local_variable_table *local_variable;
} LocalVariableTable_attribute;

/*typedef struct {
    	u2 attribute_name_index;
    	u4 attribute_length;
    }Synthetic_attribute;*/

typedef union {
	SourceFile_attribute source_file;
	ConstantValue_attribute constant_value;
	Code_attribute code;
	Exceptions_attribute exception;
	InnerClasses_attribute inner_class;
	LineNumberTable_attribute line_number_table;
	LocalVariableTable_attribute local_variable_table;
	/*	Synthetic_attribute synthetic;*/
} attribute_union;

struct attribute_info_struct {
	u2 attribute_name_index;
	u4 attribute_length;
	attribute_union info;
};

typedef struct {
	u2 access_flags;
	u2 name_index;
	u2 descriptor_index;
	u2 attributes_count;
	attribute_info *attributes;
} field_info;

typedef struct {
	u2 access_flags;
	u2 name_index;
	u2 descriptor_index;
	u2 attributes_count;
	attribute_info *attributes;
} method_info; 

/*Class file structure*/    
typedef struct {
	u4 magic;
	u2 minor_version;
	u2 major_version;
	u2 constant_pool_count;
	cp_info *constant_pool;
	u2 access_flags;
	u2 this_class;
	u2 super_class;
	u2 interfaces_count;
	u2 *interfaces;
	u2 fields_count;
	field_info *fields;
	u2 methods_count;
	method_info *methods;
	u2 attributes_count;
	attribute_info *attributes;
} ClassFile;

#endif
