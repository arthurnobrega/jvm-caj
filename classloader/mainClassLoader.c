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

/*
 * imprime saida de erro por parametros para usuario.
 */
void print_help() {
	printf("USO: Classloader [nome da classe]\n");
}

int main(int argc, char *argv[]) {
		classe_carregada *class_loaded;
		u1 *class_name;

		if (argc != 2) {
			print_help();
			return EXIT_FAILURE;
		}

		/*
		 * inicializacao necessaria do vetor de instrucoes (para mapeamento pelo compilador das
		 * instrucoes) e inicializacao da heap, inicializando a estrutura de dados (do tipo
		 * classes_carregadas).
		 */
		init_instrucoes();
		init_heap();

		/*pega o nome qualificado da classe para carregamento inicial: carregar a classe em
		 * memória e executar seu clinit.
		 */

		class_name = (u1 *) argv[1];
		class_loaded = get_classe_carregada(class_name);
		if (class_loaded == NULL) {
			printf("Não foi possível carregar a classe");
			return EXIT_FAILURE;
		}

		/*
		 * chamada a metodos para impressao da classe
		 */

		printf_Access_Flag(*class_loaded->classe);
		printf_General_Information(*class_loaded->classe);
		printf_Interfaces(*class_loaded->classe);
		printf_Fields( *class_loaded->classe);
		printf_Attributes(*class_loaded->classe);
		printf_Methods(*class_loaded->classe);
		printf_Constant_Pool(*class_loaded->classe);

		printf("\n\nPressione qualquer tecla para sair...");
		getchar();

		return (EXIT_SUCCESS);
}
