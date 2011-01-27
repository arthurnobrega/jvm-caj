/*
 Universidade de Brasilia
 Instituto de Ciencias Exatas
 Departamento de Ciencia da Computacao
 Software Basico
 Turma A - 02/2007
 
 Turma A - 02/2010

 Arthur Thiago Barbosa Nobrega 06/31205
 Julio Cesar Junior 05/34986
 Renato Carrasco Costa 07/37771
 
 bits.h: define funcoes utilitarias para tratamento de operacoes de baixo nivel 
 como conversao de endianess e bits.
 */
#ifndef BITS_H
#define BITS_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "java.h"

#define BYTE_TAM 8

#define TROCA_BYTES_U2(n) ((n >> 8) | (n << 8))
#define TROCA_BYTES_U4(n) (((n & 0x000000FF) << 24) | ((n & 0x0000FF00) << 8) | ((n & 0x00FF0000) >> 8) | ((n & 0xFF000000) >> 24))

/**
 * Retorna se o bit de um byte esta setado
 */
int is_bit(char byte, int bit);

/**
 * Retorna um byte com certo bit setado
 */
char set_bit(char byte, int bit, int val);

/**
 * Imprime char em forma binaria
 */
void print_bits(char c);

/**
 * Le do arquivo 4 bytes no formato big-endian
 */
u4 fget_u4(FILE *f);

/**
 * Le do arquivo 2 bytes no formato big-endian
 */
u2 fget_u2(FILE *f);

/**
 * Le do arquivo 1 bytes no formato big-endian
 */
u1 fget_u1(FILE *f);

#endif
