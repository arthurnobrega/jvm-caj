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


 tntvm.c: Arquivo inicial do projeto. ContÃ©m a funcao main que tem papel de iniciar a execucao
 da Virtual Machine.
 */

#include <stdio.h>
#include <stdlib.h>
#include "headers/heap.h"
#include "headers/stack.h"
#include "classfile/java.h"
#include "classfile/print_class.h"
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
	
	if (argc < 2 || argc > 3) {
		printf("---------------HELP-----------------\n");
		printf("%s [classe]\n", argv[0]);
		printf("ou\n");
		printf("%s -classfile [classe]\n", argv[0]);
		printf("---------------HELP-----------------");
		return EXIT_FAILURE;
	}

	/*pega o nome qualificado da classe para carregamento inicial: carregar a classe em
	 * memória e executar seu clinit.
	 */
	if (argc == 2) {
		class_name = (u1 *) argv[1];
	} else if (argc == 3) {
		class_name = (u1 *) argv[2];
	}
	class_file = get_heap_element(class_name);
	if (class_file == NULL) {
		printf("Não foi possível carregar a classe");
		return EXIT_FAILURE;
	}

	if (argc == 3 && strcmp(argv[1], "-classfile") == 0) {
		printf_General_Information(*class_file->classe);
		printf_Access_Flag(*class_file->classe);
		printf_Fields(*class_file->classe);
		printf_Attributes(*class_file->classe);
		printf_Methods(*class_file->classe);
		printf_Constant_Pool(*class_file->classe);
	}

	/*
	 * executa o init da classe, começando de fato a execução da classe.
	 */
	boot(class_file);

//	printf("\n\nPressione <ENTER> para sair...");
//	getchar();
	
	/*compilacao condicional para testes..*/

	return (EXIT_SUCCESS);
}

