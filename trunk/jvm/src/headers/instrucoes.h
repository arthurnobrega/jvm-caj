/*
 Universidade de Brasilia
 Instituto de Ciencias Exatas
 Departamento de Ciencia da Computacao
 Software Basico
 Turma A - 02/2010

 Arthur Thiago Barbosa Nobrega 06/31205
 Julio Cesar Junior 05/34986
 Renato Carrasco Costa 07/37771
 
 intrucoes.h: interface que define a assinatura das instrucoes da TNTvm
 */
#ifndef INSTRUCOES_H_
#define INSTRUCOES_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * define as flags de NaN e infinity muito necessárias para as operações com float.
 * Para isso, usaremos as funções 
 * int isfinite (float-type x)
 * int isnormal (float-type x)
 * int isnan (float-type x)
 * 
 * com as respectivas macros, assim como definido no manual no GNU C Library.
*/
#include "../classfile/java.h"
#include "../classfile/class_struc.h"
#include "../classfile/class_util.h"
#include "heap.h"
#include "stack.h"

#define FALSE 0
#define TRUE 1

/* macro para definir a mascara usada para retirar os 5 bits menos significativos do
 * parametro 2 das instruções de shift*/
#define MASK_SHIFT 0x1F;

typedef struct classe_carregada_struct classe_carregada3;

/*Definição dos tipos dos arrays.*/
#define T_BOOLEAN 4
#define T_CHAR 5
#define T_FLOAT 6
#define T_DOUBLE 7
#define T_BYTE 8
#define T_SHORT 9
#define T_INT 10
#define T_LONG 11


/**
 * Vetor de instruções
 */
int (*instrucao[0xff]) ();

/**
 * Inicializa vetor de instruções
 */
void init_instructions();

int execute(classe_carregada3 *classe, char *func_nome, char *func_desc, int estatico);

/**
 * Metodo generico para chamada de funcoes. Recebe uma flag TRUE ou FALSE
 * que indica se o metodo eh estatico
 */
void invoke(int estatico);

/**
 * Pega parametros e cria o offset
 */
u2 carrega_branch();

/* 
 * A próxima função é utilizada para implementar a instrução multianewarray
 * Ela é recursiva. O critério de parada é ter inicializado todas as dimensões,
 * zerando o contador dimensoes.
 */
void add_multiarray(u4 ** ponteiro, u4 * tamanhos, u4 dimensoes );

int _nop();
int _aconst_null();
int _iconst_m1();
int _iconst_0();
int _iconst_1();
int _iconst_2();
int _iconst_3();
int _iconst_4();
int _iconst_5();
int _lconst_0();
int _lconst_1();
int _fconst_0();
int _fconst_1();
int _fconst_2();
int _dconst_0();
int _dconst_1();
int _bipush();
int _sipush();
int _ldc();
int _ldc_w();
int _ldc2_w();
int _iload();
int _lload();
int _fload();
int _dload();
int _aload();
int _iload_0();
int _iload_1();
int _iload_2();
int _iload_3();
int _lload_0();
int _lload_1();
int _lload_2();
int _lload_3();
int _fload_0();
int _fload_1();
int _fload_2();
int _fload_3();
int _dload_0();
int _dload_1();
int _dload_2();
int _dload_3();
int _aload_0();
int _aload_1();
int _aload_2();
int _aload_3();
int _iaload();
int _laload();
int _faload();
int _daload();
int _aaload();
int _baload();
int _caload();
int _saload();
int _istore();
int _lstore();
int _fstore();
int _dstore();
int _astore();
int _istore_0();
int _istore_1();
int _istore_2();
int _istore_3();
int _lstore_0();
int _lstore_1();
int _lstore_2();
int _lstore_3();
int _fstore_0();
int _fstore_1();
int _fstore_2();
int _fstore_3();
int _dstore_0();
int _dstore_1();
int _dstore_2();
int _dstore_3();
int _astore_0();
int _astore_1();
int _astore_2();
int _astore_3();
int _iastore();
int _lastore();
int _fastore();
int _dastore();
int _aastore();
int _bastore();
int _castore();
int _sastore();
int _pop();
int _pop2();
int _dup();
int _dup_x1();
int _dup_x2();
int _dup2();
int _dup2_x1();
int _dup2_x2();
int _swap();
int _iadd();
int _ladd();
int _fadd();
int _dadd();
int _isub();
int _lsub();
int _fsub();
int _dsub();
int _imul();
int _lmul();
int _fmul();
int _dmul();
int _idiv();
int _ldiv();
int _fdiv();
int _ddiv();
int _irem();
int _lrem();
int _frem();
int _drem();
int _ineg();
int _lneg();
int _fneg();
int _dneg();
int _ishl();
int _lshl();
int _ishr();
int _lshr();
int _iushr();
int _lushr();
int _iand();
int _land();
int _ior();
int _lor();
int _ixor();
int _lxor();
int _iinc();
int _i2l();
int _i2f();
int _i2d();
int _l2i();
int _l2f();
int _l2d();
int _f2i();
int _f2l();
int _f2d();
int _d2i();
int _d2l();
int _d2f();
int _i2b();
int _i2c();
int _i2s();
int _lcmp();
int _fcmpl();
int _fcmpg();
int _dcmpl();
int _dcmpg();
int _ifeq();
int _ifne();
int _iflt();
int _ifge();
int _ifgt();
int _ifle();
int _if_icmpeq();
int _if_icmpne();
int _if_icmplt();
int _if_icmpge();
int _if_icmpgt();
int _if_icmple();
int _if_acmpeq();
int _if_acmpne();
int _goto();
int _jsr();
int _ret();
int _tableswitch();
int _lookupswitch();
int _ireturn();
int _lreturn();
int _freturn();
int _dreturn();
int _areturn();
int _return();
int _getstatic();
int _putstatic();
int _getfield();
int _putfield();
int _invokevirtual();
int _invokespecial();
int _invokestatic();
int _invokeinterface();
/*int _xxxunusedxxx1();*/
int _new();
int _newarray();
int _anewarray();
int _arraylength();
int _athrow();
int _checkcast();
int _instanceof();
int _monitorenter();
int _monitorexit();
int _wide();
int _multianewarray();
int _ifnull();
int _ifnonnull();
int _goto_w();
int _jsr_w();

/*
 * para testes...
 * */
void teste_instrucoes(void);

int is_inegative(u4 value);
int convert_u4_to_int(u4 value);

#endif /*INSTRUCOES_H_*/
