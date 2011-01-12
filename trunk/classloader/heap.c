/*
 Universidade de Brasilia
 Instituto de Ciencias Exatas
 Departamento de Ciencia da Computacao
 Software Basico
 Turma A - 02/2010


 heap.c: Implementa as funcoes de manipulacao do vetor de classes carregadas (aqui chamado de heap)
 */
#include "headers/heap.h"

void init_heap() {
	classes = NULL;
}

classe_carregada *adc_class(ClassFile *class_file) {
	classe_carregada *classe;
	
	assert(class_file != NULL);

	/* cria instancia */
	classe = (classe_carregada *) malloc(sizeof(classe_carregada));
	classe->classe = class_file;
	classe->prox = classes;
	classes = classe;

	return classe;
}

/**
 * cp_info da classe que chama
 * instancia do objeto a ser alterado
 * indice fieldref do field
 */
classe_carregada *get_classe_carregada(u1 *class_name) {
	classe_carregada *tmp = classes;

	assert(class_name != NULL);

	while (tmp != NULL) {
		if (strcmp((char *) get_nome_qualificado(tmp->classe), (char *) class_name) == 0) {
#ifdef DEBUG
			printf("criar_instancia(): Classe '%s' retornada da heap\n", class_name);
#endif
			return tmp;
		}
		tmp = tmp->prox;
	}

#ifdef DEBUG
	printf("criar_instancia(): Classe '%s' carregada na heap\n", class_name);
#endif
	return load_class(class_name);
}
