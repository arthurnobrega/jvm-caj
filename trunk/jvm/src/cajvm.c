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
 
 tntvm.c: Arquivo inicial do projeto. ContÃ©m a funcao main que tem papel de iniciar a execucao
 da Virtual Machine.
 */

#include <stdio.h>
#include <stdlib.h>
#include "headers/heap.h"
#include "headers/stack.h"
#include "classfile/java.h"
#include "headers/class.h"
#include "headers/debug.h"

/*#include "testes/testes.h"*/

/*
 * Variável global que armazena o valor do classfile recém-carregado. Ele será alterado em load_class
 * e será consultado para ser adicionado nas classes carregadas.
 */
ClassFile *class_file;

int main(int argc, char *argv[]) {
	heap_element *class_file;
	u1 *class_name;

	/*
	 * inicializacao necessaria do vetor de instrucoes (para mapeamento pelo compilador das
	 * instrucoes) e inicializacao da heap, inicializando a estrutura de dados (do tipo
	 * classes_carregadas).
	 */
	init_instructions();
	init_heap();
	
	if (argc != 2) {
		printf("USO: cajvm [nome qualificado da classe]\n");
		return EXIT_FAILURE;
	}

	/*pega o nome qualificado da classe para carregamento inicial: carregar a classe em
	 * memória e executar seu clinit.
	 */
	class_name = (u1 *) argv[1];
	class_file = get_heap_element(class_name);
	if (class_file == NULL) {
		printf("Não foi possível carregar a classe");
		return EXIT_FAILURE;
	}
	/*
	 * executa o init da classe, começando de fato a execução da classe.
	 */
	boot(class_file);
	
	printf("\n\nPressione qualquer tecla para sair...");
	getchar();
	
	/*compilacao condicional para testes..*/

	return (EXIT_SUCCESS);
}

