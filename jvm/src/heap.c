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

 heap.c: Implementa as funcoes de manipulacao do vetor de classes carregadas (aqui chamado de heap)
 */
#include "headers/heap.h"

void init_heap() {
	heap = NULL;
}

heap_element *add_heap_element(ClassFile *class_file) {
	heap_element *element;
	
	assert(class_file != NULL);

	/* cria instancia */
	element = (heap_element *) malloc(sizeof(heap_element));
	element->classe = class_file;
	element->prox = heap;
	heap = element;

	return element;
}

/**
 * cp_info da classe que chama
 * instancia do objeto a ser alterado
 * indice fieldref do field
 */
heap_element *get_heap_element(u1 *class_name) {
	heap_element *tmp = heap;

	assert(class_name != NULL);

	while (tmp != NULL) {
		if (strcmp((char *) get_class_name_classfile(tmp->classe), (char *) class_name) == 0) {
#ifdef DEBUG
			printf("get_heap_element(): Classe '%s' retornada da heap\n", class_name);
#endif
			return tmp;
		}
		tmp = tmp->prox;
	}

#ifdef DEBUG
	printf("get_heap_element(): Classe '%s' será carregada na heap\n", class_name);
#endif
	return load_class(class_name);
}
