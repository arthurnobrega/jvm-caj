/*
 Universidade de Brasilia
 Instituto de Ciencias Exatas
 Departamento de Ciencia da Computacao
 Software Basico
 Turma A - 02/2010
 
 stack.h: arquivo de interface que define funcoes e estruturas para a implementacao da pilha 
 de execucao e seus frames.
 */
#ifndef STACK_H_
#define STACK_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "heap.h"
#include "java.h"

typedef struct instancia_struct instancia2;

#define NAO_IMP -2
#define NORMAL_INST -1
#define POP0 0
#define POP1 1
#define POP2 2
#define DESVIO 3

/* stack de operandos */
struct struct_op_stack_item {
	u4 var;
	struct struct_op_stack_item *prox;
};
typedef struct struct_op_stack_item op_stack_item; 

/* estrutura do frames */
struct struct_frame_stack_item { 
	u4 pc;
	Code_attribute *code_attribute;
	u2 variables_count;
	u4 *variable;
	op_stack_item *op_item;
	cp_info *constant_pool;
	struct struct_frame_stack_item *prox;
};
typedef struct struct_frame_stack_item frame_stack_item; 

frame_stack_item *frame_stack;

/*Struct para armazenar os vetores iniciados em cada frame.*/
struct arrays_struct_type{
	void * referencia;
	u4 tamanho;
	struct arrays_struct_type * prox;
};
typedef struct arrays_struct_type arrays_struct;

arrays_struct * arrays;

/**
 * Dá um push na stack de operando do frame atual
 */
void push(u4 var);

/**
 * Dá um pop na stack de operando do frame atual
 */
u4 pop();

/*Adiciona uma nova referencia ao conjunto de arrays*/
void add_array(void * referencia, u4 tamanho);

/*Função de busca de uma referencia de vetor para obter seu tamanho*/
arrays_struct * get_array(void * referencia);

/**
 * Cria um frame com o Code_attribute e empilha
 */
void create_frame(instancia2 *objeto, Code_attribute *code_attribute, cp_info *constant_pool);

/**
 * Desempilha o frame passando o valor de retorno pro frame anterior
 */
void destroy_frame(int controle);

#endif /*STACK_H_*/
