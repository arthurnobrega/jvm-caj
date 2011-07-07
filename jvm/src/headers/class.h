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
 

 class.h: Define as funcoes basicas de execucao do .class como iniciacao, instanciacao e carregamento
 */
#ifndef CLASS_
#define CLASS_

typedef struct instancia_struct instancia3;
typedef struct classe_carregada_struct classe_carregada2;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../classfile/java.h"
#include "../classfile/class_util.h"
#include "../classfile/class_struc.h"
#include "instrucoes.h"
#include "debug.h"
#include "heap.h"
#include "debug.h"

#define OBJECT_CLASS "java/lang/Object"

/**
 * Boota classe executando o main()
 */
void boot(classe_carregada2 *classe);

/**
 * Retorna primeiro Code_attribute que bata com o nome passado.
 * O parâmetro classe será modificado para apontar para a 
 * classe_carregada onde o método foi encontrado
 */
Code_attribute *get_code(classe_carregada2 **classe, char *nome, char *desc);

/**
 * Retorna primeiro method_info que bata com o nome passado 
 */
method_info *get_metodo(ClassFile *class_file, char *nome, char *desc);

/**
 * Retorna atributo que bata com o nome passado 
 */
attribute_info *get_attribute(char *nome, cp_info *cp, attribute_info *att, u2 count);

/**
 * Cria uma instancia da classe
 */
instancia3 *create_instance(u1 *class_name);

classe_carregada2 *load_class(u1 *class_name);

u4 get_field_value(cp_info *info, instancia3 *objeto, u2 fieldref);

void put_field_value(cp_info *info, instancia3 *objeto, u2 fieldref, u4 valor);

u2 get_field_index(ClassFile *class_file, u1 *field_name);

#endif /*CLASS_*/
