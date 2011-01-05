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
 
 bits.c: fornece funcoes utilitarias para tratamento de operacoes de baixo nivel 
 como conversao de endianess e bits.
 */
#include "bits.h"

int is_bit(char byte, int bit) {
	return (byte & (1 << bit)) == (1 << bit);
}

char set_bit(char byte, int bit, int val) {
	if (val == 0) {
		byte &= ~(1 << bit);
	} else {
		byte |= (1 << bit);
	}

	return byte;
}

void print_bits(char c) {
	int i;

	for (i = BYTE_TAM-1; i >=0; i--) {
		printf("%i", (c & (1 << i)) != 0);
	}
}

u4 fget_u4(FILE *arq) {
	u4 retorno;
	assert (arq != NULL);

	fread(&retorno, sizeof(u4), 1, arq);

	return TROCA_BYTES_U4(retorno);
}

u2 fget_u2(FILE *arq) {
	u2 retorno;

	assert (arq != NULL);

	fread(&retorno, sizeof(u2), 1, arq);

	return TROCA_BYTES_U2(retorno);
}

u1 fget_u1(FILE *arq) {
	u1 retorno;

	assert (arq != NULL);

	fread(&retorno, sizeof(u1), 1, arq);

	return retorno;
}
