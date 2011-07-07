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


stack.c: Implementa as funcoes de manipulacao da pilha de execução e de seus frames.
 */
#include "headers/stack.h"
#include "classfile/print_class.h"
#include "classfile/class_util.h"
#include "headers/class.h"

void push(u4 var) {
	op_stack_item *op_item;

	/* adiciona operando ao stack do frame atual */
	op_item = (op_stack_item *) malloc(sizeof(op_stack_item));
	op_item->var = var;
	op_item->prox = frame_stack->op_item;
	frame_stack->op_item = op_item;
}

u4 pop() {
	op_stack_item *retorno;

	/* remove operando do stack do frame atual */
	retorno = frame_stack->op_item;
	assert(frame_stack->op_item != NULL);
	frame_stack->op_item = frame_stack->op_item->prox;

	return retorno->var;
}

void add_array(void * referencia, u4 tamanho){
	arrays_struct * temp;

	temp = malloc(sizeof(arrays_struct));
	temp->referencia = referencia;
	temp->tamanho = tamanho;
	temp->prox = arrays;
	arrays = temp;
}

arrays_struct * get_array(void * referencia){
	arrays_struct * ret = arrays;

	assert(referencia != NULL);
	assert(arrays != NULL);
	while(ret != NULL){
		if(ret->referencia == referencia){
			break;
		}
		ret = ret->prox;
	}
	return ret;
}

void create_frame(instance *objeto, Code_attribute *code_attribute, cp_info *constant_pool) {
	frame_stack_item *frame_item;

	assert(code_attribute != NULL);
	assert(constant_pool != NULL);

	/* adiciona frame */
	frame_item = (frame_stack_item *) malloc(sizeof(frame_stack_item));
	frame_item->pc = 0;
	frame_item->code_attribute = code_attribute;
	frame_item->constant_pool = constant_pool;
	frame_item->op_item = NULL;
	frame_item->variables_count = code_attribute->max_locals;
	frame_item->variable = (u4 *) malloc(sizeof(u4) * code_attribute->max_locals);
	if (objeto != NULL) {
		frame_item->variable[0] = (u4) objeto;
	}
	frame_item->prox = frame_stack;
	frame_stack = frame_item;

#ifdef DEBUG
	printf("FRAME CRIADO\n");
#endif
}

void destroy_frame(int controle) {
	frame_stack_item *frame_item;
	u4 return1;
	u4 return2;

	/* remove frame */
	frame_item = frame_stack;

	/* manda elementos da stack do frame superior para o inferior */
	if (controle == POP1) {
		return1 = pop();
	} else if (controle == POP2) {

		return2 = pop();
		return1 = pop();
	}

	frame_stack = frame_stack->prox;

	if (controle == POP1) {
		push(return1);
	} else if (controle == POP2) {
		push(return1);
		push(return2);
	}

#ifdef DEBUG
	printf("FRAME DESTRUIDO\n");
#endif
	free(frame_item);
}
