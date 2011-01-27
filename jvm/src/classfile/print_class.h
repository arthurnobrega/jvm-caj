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

#ifndef PRINT_CLASS_H
#define PRINT_CLASS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "class_util.h"
#include "java.h"
#include "erros.h"
#include "bits.h"

/**
 * Imprime as flags de acesso da classe
 */
int printf_Access_Flag(ClassFile class_file);

/**
 * Imprime as informacoes gerais da classe
 */
int printf_General_Information(ClassFile class_file);

/**
 * Procura e imprime a informacao utf8 do constant pool
 */
void printf_utf8(cp_info *info, int index);

/**
 * Procura e imprime a informacao utf8 do name and type
 */
void printf_name_and_type(cp_info *info, int index);

/**
 * Procura e imprime a informacao utf8 da classe
 */
void printf_class(cp_info *info, int index);

/**
 * Imprime as interfaces da classe
 */
int printf_Interfaces(ClassFile class_file);

/**
 * Imprime as flags de acesso dos campos da classe
 */
int printf_Field_Access_Flag(u2 access_flags);

/**
 * Imprime os campos da classe
 */
int printf_Fields(ClassFile class_file);

/**
 * Imprime os atributos da classe
 */
int printf_Attributes(ClassFile class_file);

/**
 * Imprime recursivamente atributos da stream
 */
int printf_Attributes_rec(cp_info *info, attribute_info *attributes, u2 attributes_count, int identacao);

/**
 * Imprime os metodos da classe
 */
int printf_Methods(ClassFile class_file);

/**
 * Imprime pool de constantes
 */
int printf_Constant_Pool(ClassFile class_file);

#endif
