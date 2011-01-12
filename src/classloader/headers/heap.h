/*
 Universidade de Brasilia
 Instituto de Ciencias Exatas
 Departamento de Ciencia da Computacao
 Software Basico
 Turma A - 02/2010
 
 heap.h: Define as funcoes de manipulacao do vetor de classes carregadas (aqui chamado de heap)
 */
#ifndef HEAP_H_
#define HEAP_H_

#include <stdio.h>
#include <stdlib.h>
#include "java.h"
#include "class_struc.h"
#include "class_util.h"
#include "class.h"

struct instancia_struct {
	u1 *nome_qualificado;
	u2 fields_count;
	u4 *field;
	struct instancia_struct *super;
};
typedef struct instancia_struct instancia;

struct classe_carregada_struct {
	ClassFile *classe;
	instancia *instancia_estatica;
	struct classe_carregada_struct *prox;
};
typedef struct classe_carregada_struct classe_carregada;

/*
 * Instância global à heap que representa o vetor de classes carregadas dinamicamente pela tntvm.
 */
classe_carregada *classes;

void init_heap();

/*
 * Adiciona classe ao heap
*/
classe_carregada *adc_class(ClassFile *class_file);

/**
 * Retorna classe carregada do heap
 */
classe_carregada *get_classe_carregada(u1 *class_name);

#endif /*HEAP_H_*/
