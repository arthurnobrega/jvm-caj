/*
 Universidade de Brasilia
 Instituto de Ciencias Exatas
 Departamento de Ciencia da Computacao
 Software Basico
 Turma A - 02/2010
 
 class_util.h: define funcoes de manipulacao dos dados da estrutura do arquivo .class. 
 */
#ifndef CLASS_UTIL_H
#define CLASS_UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <assert.h>
#include <string.h>

#include "java.h"
#include "class_util.h"

/**
 * Estabelece locate (necessario para utf8)
 */
int set_locale();

/**
 * Retorna ponteiro ascii do utf8
 */
u1 *get_ascii(cp_info *info, u2 index);

/**
 * Retorna ponteiro para o nome da classe
 */
u1 *get_class(cp_info *info, u2 index);

/**
 * Retorna ponteiro wide char do utf8
 */
wchar_t *get_utf8(cp_info *info, u2 index);

/**
 * Retorna nome qualificado da classe
 */
u1 *get_nome_qualificado(ClassFile *class_file);

/**
 * Tranforma nome qualificado em nome de arquivo 
 */
u1 *c2f(u1 *classe);

int contar_args(char *args);

#endif
