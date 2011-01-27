/*
 Universidade de Brasilia
 Instituto de Ciencias Exatas
 Departamento de Ciencia da Computacao
 Software Basico
 Turma A - 02/2010

 Arthur Thiago Barbosa Nobrega 06/31205
 Julio Cesar Junior 05/34986
 Renato Carrasco Costa 07/37771
 
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
int read_class_file(FILE *arq, ClassFile *class_file);

/**
 * Le elemento utf8 do pool de constante
 */
void read_utf8(FILE *arq, CONSTANT_Utf8_info *utf8_info);

/**
 * Le elementos do pool de constante
 */
int read_constant_pool(FILE *arq, ClassFile *class_file);

/**
 * Le os campos do .class
 */
int read_fields(FILE *arq, ClassFile *class_file);

/**
 * Le os atributos do .class
 */
int read_attributes(FILE *arq, ClassFile *class_file);

/**
 * Le os atributos do stream
 */
int read_attributes_array(FILE *arq, cp_info *info, attribute_info **attributes, int attributes_count);

/**
 * Le as interfaces do .class. 
 */
int read_interfaces(FILE *arq, ClassFile *class_file);


#endif
