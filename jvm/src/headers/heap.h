/*
 Universidade de Brasilia
 Instituto de Ciencias Exatas
 Departamento de Ciencia da Computacao
 Software Basico
 Turma A - 01/2011

 Arthur Thiago Barbosa Nobrega 06/31205
 Daniel Lucas A. de Freitas 05/96434
 Julio Cesar Junior 05/34986
 Renato Carrasco Costa 07/37771
 

 heap.h: Define as funcoes de manipulacao do vetor de classes carregadas (aqui chamado de heap)
 */
#ifndef HEAP_H_
#define HEAP_H_

#include <stdio.h>
#include <stdlib.h>
#include "../classfile/java.h"
#include "../classfile/class_struc.h"
#include "../classfile/class_util.h"
#include "class.h"

struct instancia_struct {
	u1 *nome_qualificado;
	u2 fields_count;
	u4 *field;
	struct instancia_struct *super;
};
typedef struct instancia_struct instance;

struct classe_carregada_struct {
	ClassFile *classe;
	instance *instancia_estatica;
	struct classe_carregada_struct *prox;
};
typedef struct classe_carregada_struct heap_element;

/*
 * Inst�ncia global � heap que representa o vetor de classes carregadas dinamicamente pela jvm.
 */
heap_element *heap;

void init_heap();

/*
 * Adiciona classe ao heap
*/
heap_element *add_heap_element(ClassFile *class_file);

/**
 * Retorna classe carregada do heap
 */
heap_element *get_heap_element(u1 *class_name);

#endif /*HEAP_H_*/
