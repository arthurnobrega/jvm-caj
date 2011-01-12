



#include <stdio.h>
#include <stdlib.h>
#include "headers/heap.h"
#include "headers/stack.h"
#include "headers/java.h"
#include "headers/class.h"
#include "headers/print_class.h"

/*
 * Variável global que armazena o valor do classfile recém-carregado. Ele será alterado em load_class
 * e será consultado para ser adicionado nas classes carregadas.
 */
ClassFile *class_file;

int main(int argc, char *argv[]) {

	//TODO ler arquivo da classe, carregar a classe, e chamar as funcoes para imprimir q estao no prin_class.c

/*
	classe_carregada *class_file;
		u1 *volt;


		 * inicializacao necessaria do vetor de instrucoes (para mapeamento pelo compilador das
		 * instrucoes) e inicializacao da heap, inicializando a estrutura de dados (do tipo
		 * classes_carregadas).

		init_instrucoes();
		init_heap();

 * não entendi pq o ifndef TESTE...mas seria bom tirar esse ifndef TESTE dai..naõ?
 *
 *
	#ifndef TESTE

		if (argc != 2) {
			print_help();
			return EXIT_FAILURE;
		}

		pega o nome qualificado da classe para carregamento inicial: carregar a classe em
		 * memória e executar seu clinit.

		volt = (u1 *) argv[1];
		class_file = get_classe_carregada(volt);
		if (class_file == NULL) {
			printf("Não foi possível carregar a classe");
			return EXIT_FAILURE;
		}

		 ta... acho que pro classloader a gnete precisa mudar isso aqui..esse boot() ai
		 *
		 * executa o init da classe, começando de fato a execução da classe.

		boot(class_file);

		printf("\n\nPressione qualquer tecla para sair...");
		getchar();

		tirar o ifndef e o endif???..
		 *
		 * compilacao condicional para testes..
	#else
		teste();
	#endif




*/






/*
 * duvida cruel..
 * esse class_file já naõ tava definido ali em cima como variável global? e o tipo como *ClassFile?
 * pq ele ta aqui denovo??
 * */
		classe_carregada *class_file;
			u1 *volt;

			/*
			 * inicializacao necessaria do vetor de instrucoes (para mapeamento pelo compilador das
			 * instrucoes) e inicializacao da heap, inicializando a estrutura de dados (do tipo
			 * classes_carregadas).
			 */
			init_instrucoes();
			init_heap();

			if (argc != 2) {
				print_help();
				return EXIT_FAILURE;
			}

			/*pega o nome qualificado da classe para carregamento inicial: carregar a classe em
			 * memória e executar seu clinit.
			 */

			//volt é o nome da classe, seria bom colocar isso pra ser passado pelo usuario ou deixar pra ser passado como parametro mesmo?
			volt = (u1 *) argv[1];
			class_file = get_classe_carregada(volt);
			if (class_file == NULL) {
				printf("Não foi possível carregar a classe");
				return EXIT_FAILURE;
			}

			/*
			 * chamada a metodos para impressao da classe
			 */

			printf_Access_Flag(class_file);
			printf_General_Information(class_file);
			printf_Interfaces(class_file);
			printf_Fields( class_file);
			printf_Attributes(class_file);
			printf_Methods(class_file);
			printf_Constant_Pool(class_file);

			printf("\n\nPressione qualquer tecla para sair...");
			getchar();







		return (EXIT_SUCCESS);
}
