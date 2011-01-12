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
 
 bits.c: define funcoes para leitura do .class.
 */
#ifndef CLASS_STRUC_H
#define CLASS_STRUC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/debug.h"

#include "class_util.h"
#include "bits.h"
#include "java.h"
#include "erros.h"

/**
 * Le strutura do .class
 */
int lerClass(FILE *arq, ClassFile *class_file);

/**
 * Le elemento utf8 do pool de constante
 */
void lerUtf8(FILE *arq, CONSTANT_Utf8_info *utf8_info);

/**
 * Le elementos do pool de constante
 */
int lerConstantPool(FILE *arq, ClassFile *class_file);

/**
 * Le os campos do .class
 */
int lerFields(FILE *arq, ClassFile *class_file);

/**
 * Le os atributos do .class
 */
int lerAttributes(FILE *arq, ClassFile *class_file);

/**
 * Le os atributos do stream
 */
int lerAttributesArray(FILE *arq, cp_info *info, attribute_info **attributes, int attributes_count);

/**
 * Le as interfaces do .class. 
 */
int lerInterfaces(FILE *arq, ClassFile *class_file);


#endif
