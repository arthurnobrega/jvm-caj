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

 class_util.c: fornece funcoes de manipulacao dos dados da estrutura do arquivo .class. 
 */
#include "class_util.h"

int set_locale() {
	if (!setlocale(LC_CTYPE, "")) {
		printf("Erro: nao foi possivel especificar locale\n");
		return 0;
	}
	return 1;
}

u1 *get_ascii(cp_info *info, u2 index) {
	u2 tamanho = info[index].info.utf8_info.length;
	u1 *nome = malloc(tamanho+1);
	nome = memcpy(nome, info[index].info.utf8_info.bytes, tamanho);
	nome[tamanho] = '\0';
	return nome;
}

u1 *get_class(cp_info *info, u2 index) {
	assert(info != NULL);

	return get_ascii(info, info[index].info.class_info.name_index);
}

u1 *get_nome_qualificado(ClassFile *class_file) {
	assert(class_file != NULL);

	return get_class(class_file->constant_pool, class_file->this_class);
}

wchar_t *get_utf8(cp_info *info, u2 index) {
	u1 *mbs;
	wchar_t *wcs;
	int tamanho = info[index].info.utf8_info.length;
	mbs = info[index].info.utf8_info.bytes;

	assert (mbs != NULL);

	wcs = malloc(sizeof(wchar_t) * tamanho +1);
	mbstowcs(wcs, (char *)&mbs[0], tamanho);
	wcs[tamanho] = '\0';

	return wcs;
}

u1 *c2f(u1 *classe) {
	u1 *tmp = calloc(strlen((char *) classe) + 7, sizeof(u1));
	int i = 0;

	strcpy((char *) tmp, (char *) classe);

	while (tmp[i++] != '\0') {
		if (tmp[i] == '/') {
			tmp[i] = '\\';
		}
	}

	strcat((char *) tmp, ".class");
	return tmp;
}

int contar_args(char *args) {
	int i = 0, count = 0;
	int ref = 0;
	while (args[++i] != '\0') {
		if (args[i] == 'L') {
			ref = 1;
		} else if (args[i] == ';') {
			count++;
			ref = 0;
		} else if (args[i] == ')') {
			break;
		} else if (args[i] == '[' || ref == 1) {
			/* pula */
		} else {
			count++;
		}
	}
	
	return count;
}
