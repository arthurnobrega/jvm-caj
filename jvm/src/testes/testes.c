/*
 * Testes para as instruções da jvm
 * 
 * */

#include "testes.h"

void teste_stack() {
	/* stack de frames */
	Code_attribute code_attribute;
	code_attribute.max_locals = code_attribute.max_stack = 1;
	cp_info *constant_pool;

	/* frame 0 */
	create_frame(NULL, &code_attribute, constant_pool);
	
	/* frame 1 */
	create_frame(NULL, &code_attribute, constant_pool);
	printf("create: ok\n");
	
	/* stack de operandos */
	push(9);
	push(3);
	push(1);
	push(8);
	printf(pop() == 8 ? "pop 1: ok\n" : "pop 1: pau\n");
	printf(pop() == 1 ? "pop 2: ok\n" : "pop 2: pau\n");
	printf(pop() == 3 ? "pop 3: ok\n" : "pop 3: pau\n");

	/* frame 1 */
	destroy_frame(POP1);

	/* frame 0 */
	printf(pop() == 9 ? "return: ok\n" : "return: pau\n");
	destroy_frame(0);
	printf("destroy: ok\n");
}

void teste_heap() {
	heap_element *classe = get_heap_element("classes/Classe1");
	if (classe == NULL) {
		printf("class1: pau (NULL)\n");
	} else {
		printf(strcmp(get_class_name_classfile(classe->classe), "classes/Classe1") == 0 ? "classe1: ok\n" : "classe1: pau\n");
	}
	classe = get_heap_element("classes/Classe2");
	if (classe == NULL) {
		printf("class2: pau (NULL)\n");
	} else {
		printf(strcmp(get_class_name_classfile(classe->classe), "classes/Classe2") == 0 ? "classe2: ok\n" : "classe2: pau\n");
	}
}

void teste_instrucoes() {
	
	/*
	 * declaracoes
	 * */

	/* stack de frames */
	Code_attribute code_attribute;
	cp_info *constant_pool;
	
	code_attribute.max_locals = code_attribute.max_stack = 1;
	/* frame 0 */
	create_frame(NULL, &code_attribute, constant_pool);

	/*
	 * iadd
	 * */
	printf("_iadd\n");
	push(2);
	push(2);
	_iadd();
	printf("%s", ((int) pop() == 4) ? "OK\n" : "Falhou\n");
	
	/*
	 * fadd
	 * */
	printf("_fadd\n");
	float v1f = 2.7;
	float v2f = 2.4;
	u4 v1, v2, sai;
	float ret;
	memcpy(&v1, &v1f, sizeof(u4));
	memcpy(&v2, &v2f, sizeof(u4));
	push(v1);
	push(v2);
	_fadd();
	sai = pop();
	memcpy(&ret, &sai, sizeof(float));
	printf("resultado: %0.3f\n", ret);
	
	/*
	 * isub
	 * */
	printf("_isub\n");
	push(2);
	push(1);
	_isub();
	printf("%s", ((int) pop() == -1) ? "OK\n" : "Falhou\n");
	
	/*
	 * fsub
	 * */
	printf("_fsub\n");
	v1f = 2.7;
	v2f = 2.4;
	memcpy(&v1, &v1f, sizeof(u4));
	memcpy(&v2, &v2f, sizeof(u4));
	push(v2);
	push(v1);	
	_fsub();
	sai = pop();
	memcpy(&ret, &sai, sizeof(float));
	printf("resultado: %0.3f\n", ret);
	
	/*
	 * imul
	 * */
	printf("_imul\n");
	push(3);
	push(4);
	_imul();
	printf("%s", ((int) pop() == 12) ? "OK\n" : "Falhou\n");
	
	/*
	 * fmul
	 * */
	printf("_fmul\n");
	v1f = 2.5;
	v2f = 2.0;
	memcpy(&v1, &v1f, sizeof(u4));
	memcpy(&v2, &v2f, sizeof(u4));
	push(v2);
	push(v1);
	_fmul();
	sai = pop();
	memcpy(&ret, &sai, sizeof(float));
	printf("resultado: %0.3f\n", ret);
	
	/*
	 * idiv
	 * */
	printf("_idiv\n");
	push(-4);
	push(20);
	_idiv();
	printf("%s", ((int) pop() == -5) ? "OK\n" : "Falhou\n");
	/* 
	 * vai dar exit com erro (divisao por zero)
	 * e deu mesmo
	*/
	/* 
	push(0);
	push(10);
	_idiv();
	*/
	 
	/*
	 * fdiv
	 * */
	printf("_fdiv\n");
	v1f = 1.0;
	v2f = 0.0;
	memcpy(&v1, &v1f, sizeof(u4));
	memcpy(&v2, &v2f, sizeof(u4));
	push(v1);
	push(v2);
	_fdiv();
	sai = pop();
	memcpy(&ret, &sai, sizeof(float));
	printf("resultado: %0.3f\n", ret);
	
	/*
	 * irem
	 * */
	printf("_irem\n");
	push(3);
	push(20);
	_irem();
	printf("%s", ((int) pop() == 2) ? "OK\n" : "Falhou\n");
	
	/*
	 * frem
	 * */
	printf("_frem\n");
	v1f = 3.2;
	v2f = 6.5;
	memcpy(&v1, &v1f, sizeof(u4));
	memcpy(&v2, &v2f, sizeof(u4));
	push(v1);
	push(v2);
	//_frem();
	sai = pop();
	memcpy(&ret, &sai, sizeof(float));
	printf("resultado: %0.3f\n", ret);
	
	/*
	 * ineg
	 * */
	printf("_ineg\n");
	push(3);
	_ineg();
	printf("%s", ((int) pop() == -3) ? "OK\n" : "Falhou\n");
	
	/*
	 * fneg
	 * */
	printf("_fneg\n");
	v1f = 3.2;
	memcpy(&v1, &v1f, sizeof(u4));
	push(v1);
	_fneg();
	sai = pop();
	memcpy(&ret, &sai, sizeof(float));
	printf("resultado: %0.3f\n", ret);
	
	/*
	 * ishl
	 * */
	printf("_ishl\n");
	push(2);
	push(4);
	_ishl();
	printf("%s", ((int) pop() == 16) ? "OK\n" : "Falhou\n");
	
	/*
	 * ishr
	 * */
	printf("_ishr\n");
	push(2);
	push(16);
	_ishr();
	printf("%s", ((int) pop() == 4) ? "OK\n" : "Falhou\n");
	
	/*
	 * iushr
	 * */
	printf("_iushr\n");
	push(2);
	push(16);
	_iushr();
	printf("%s", ((int) pop() == 4) ? "OK\n" : "Falhou\n");
	
	/*
	 * iand
	 * */
	printf("_iand\n");
	push(8);
	push(7);
	_iand();
	printf("%s", ((int) pop() == 0) ? "OK\n" : "Falhou\n");
	
	/*
	 * ior
	 * */
	printf("_ior\n");
	push(8);
	push(7);
	_ior();
	printf("%s", ((int) pop() == 15) ? "OK\n" : "Falhou\n");
	
	/*
	 * ixor
	 * */
	printf("_ixor\n");
	push(8);
	push(12);
	_ixor();
	printf("%s", ((int) pop() == 4) ? "OK\n" : "Falhou\n");
	
	/*
	 * iinc
	 * */
	printf("_iinc\n");
	push(-2);
	_iinc();
	printf("%s", ((int) pop() == -1) ? "OK\n" : "Falhou\n");
	
	/*
	 * i2f
	 * */
	printf("_i2f\n");
	push(8);
	_i2f();
	sai = pop();
	memcpy(&ret, &sai, sizeof(float));
	printf("resultado: %0.3f \n", ret);

	/*
	 * f2i
	 * */
	printf("_f2i\n");
	v1f = 8.2;
	memcpy(&v1, &v1f, sizeof(u4)); 
	push(v1);
	//_f2i();
	printf("resultado: %d \n", pop());
	
	/*
	 * i2b
	 * */
	printf("_i2b\n");
	push(1984);
	_i2b();
	printf("resultado: %d \n", pop());
	
	/*
	 * i2c
	 * */
	printf("_i2c\n"); 
	push(97);
	_i2c();
	printf("resultado: %c \n", pop());
	
	/*
	 * i2s
	 * */
	printf("_i2s\n"); 
	push(246012);
	_i2s();
	printf("resultado: %d \n", pop());
	
	/*
	 * fcmpl
	 * */
	printf("_fcmpl\n");
	v1f = 3.2;
	v2f = 3.2;
	memcpy(&v1, &v1f, sizeof(u4));
	memcpy(&v2, &v2f, sizeof(u4));
	push(v1);
	push(v2);
	_fcmpl();
	printf("resultado: %d\n", pop());
	
	/*
	 * fcmpg
	 * */
	printf("_fcmpg\n");
	v1f = 3.2;
	v2f = 1.0/0.0;
	memcpy(&v1, &v1f, sizeof(u4));
	memcpy(&v2, &v2f, sizeof(u4));
	push(v1);
	push(v2);
	_fcmpg();
	printf("resultado: %d\n", pop());
	
	/*
	 * ifeq
	* */
	printf("_ifeq");
	push(0);
	_ifeq();
	printf("Endereço em: %d\n", (int)pop());
	
	/*
	 * ifne
	* */
	printf("_ifne");
	push(1);
	_ifne();
	printf("Endereço em: %d\n", (int)pop());
	
	/*
	 * iflt
	* */
	printf("_iflt");
	push(-1);
	_iflt();
	printf("Endereço em: %d\n", (int)pop());
	
	/*
	 * ifge
	* */
	printf("_ifge");
	push(2);
	_ifge();
	printf("Endereço em: %d\n", (int)pop());
	
	/*
	 * ifgt
	* */
	printf("_ifgt");
	push(1);
	_ifgt();
	printf("Endereço em: %d\n", (int)pop());
	
	/*
	 * ifle
	* */
	printf("_ifle");
	push(0);
	_ifle();
	printf("Endereço em: %d\n", (int)pop());
	
	/*
	 * if_icmpeq
	* */
	printf("_if_icmpeq");
	push(2);
	push(2);
	_if_icmpeq();
	printf("Endereço em: %d\n", (int)pop());
	
	/*
	 * if_icmpne
	* */
	printf("_if_icmpne");
	push(2);
	push(3);
	_if_icmpne();
	printf("Endereço em: %d\n", (int)pop());
	
	/*
	 * if_icmplt
	* */
	printf("_if_icmplt");
	push(3);
	push(2);
	_if_icmplt();
	printf("Endereço em: %d\n", (int)pop());
	
	/*
	 * if_icmpge
	* */
	printf("_if_icmpge");
	push(-9);
	push(7);
	_if_icmpge();
	printf("Endereço em: %d\n", (int)pop());
	
	/*
	 * if_icmpgt
	* */
	printf("_if_icmpgt");
	push(54);
	push(12301987);
	_if_icmpgt();
	printf("Endereço em: %d\n", (int)pop());
	
	/*
	 * if_icmple
	* */
	printf("_if_icmple");
	push(-3);
	push(0);
	_if_icmple();
	printf("Endereço em: %d\n", (int)pop());
	
	
}

void teste_primeiras_instrucoes(){
	/* stack de frames 
	 * struct struct_frame_stack_item { 
	u4 pc;
	Code_attribute *code_attribute;
	u2 variables_count;
	u4 *variable;
	op_stack_item *op_item;
	cp_info *constant_pool;
	struct struct_frame_stack_item *prox;
};
	 * */
		/*ClassFile class_file;
		Code_attribute *ca = (Code_attribute*) malloc(sizeof(Code_attribute)); 
		frame_stack = (frame_stack_item *) malloc(sizeof(frame_stack_item));
		frame_stack->constant_pool = (cp_info *)malloc(sizeof(cp_info));
		frame_stack->op_item = (op_stack_item*) malloc(sizeof(op_stack_item));
		
		ca->max_locals = ca->max_stack = 1;
	
		ca->code_length = 1;
		ca->code = (u1 *) malloc(5*sizeof(u1));
		ca->code[0] = 0x02;
		frame_stack->code_attribute = ca;
		frame_stack->pc = 0;
		execute();
		push();*/
		Code_attribute code_attribute;
		cp_info *constant_pool = (cp_info *)malloc(3*sizeof(cp_info));
		u4 jelly;
		float *f = malloc(4);
		u1 * nada = malloc(3);
		char ** str = malloc(sizeof(char *));
		float * bvetor = malloc(12);
		
		code_attribute.max_locals = code_attribute.max_stack = 1;
		constant_pool[0].tag = CONSTANT_String;
		constant_pool[0].info.string_info.string_index = 1;
		constant_pool[1].tag = CONSTANT_Utf8;
		constant_pool[1].info.utf8_info.length = 2;
		constant_pool[1].info.utf8_info.bytes = (u1 *) malloc(2);
		constant_pool[1].info.utf8_info.bytes[0] = 'c';
		constant_pool[1].info.utf8_info.bytes[1] = 'c';
		constant_pool[2].tag = CONSTANT_Integer;
		constant_pool[2].info.integer_info.bytes = -2345;
		
		
		code_attribute.code = malloc(8);
		code_attribute.code[1] = 0x10;/*bipush*/
		code_attribute.code[2] = 0x12;/*sipush*/
		code_attribute.code[3] = 0x34;/*sipush*/
		code_attribute.code[4] = 0x00;/*ldc*/
		code_attribute.code[5] = 0x00;/*ldc_w*/
		code_attribute.code[6] = 0x02;/*ldc_w*/
		code_attribute.code[7] = 0x01;/*fstore*/
		
		code_attribute.max_locals = 1;
		/* frame 0 */
		create_frame(NULL, &code_attribute, constant_pool);
		
		_fconst_1();
		jelly = pop();
		f = memcpy(f,&jelly,sizeof(u4));
		printf("fconst_1: %f\n",*f);
		
		_bipush();
		jelly = pop();
		printf("bipush: %X\n",jelly);
		
		_sipush();
		jelly = pop();
		printf("sipush: %X\n",jelly);
		
		_ldc();
		jelly = pop();
		*str = (char *) jelly;
		printf("ldc: %s\n", *(str));
		
		_ldc_w();
		jelly = pop();
		printf("ldc_w: %d\n",(int) jelly);
		
		bvetor[0] = 1.2;
		bvetor[1] = 2.3;
		bvetor[2] = 3.4;
		push((u4) bvetor);
		push(1);
		_faload();
		jelly = pop();
		f = memcpy(f,&jelly,sizeof(u4));
		printf("faload: %f\n",*f);
		
		push(jelly);
		_fstore();
		frame_stack->pc--;
		_fload();
		jelly = pop();
		f = memcpy(f,&jelly,sizeof(u4));
		printf("fstore e fload: %f\n",*f);
		
		push((u4) nada);
		push(2);
		push(0x123);
		_bastore();
		printf("bastore: %X\n", nada[2]);
		
}

void teste_ultimas_instrucoes() {
	heap_element *classe = get_heap_element("classes/Instrucoes");
	if (classe == NULL) {
		printf("erro ao chamar get_classe_carregada()");
		return;
	}
	
	

	/* stack de frames */
	Code_attribute *code_attribute = get_code(classe->classe, "testeStaticFields", "()V");

	/* frame 0 */
	create_frame(NULL, code_attribute, classe->classe->constant_pool);

	/* le System */
	_getstatic(); frame_stack->pc++;
	/* variavel estatic */
	_getstatic(); frame_stack->pc++;
	printf("putstatic/getstatic: %s\n", pop() == 123 ? "ok" : "falhou");
	frame_stack->pc++;
	
	destroy_frame(NORMAL_INST);

	
	
	/* stack de frames */
	code_attribute = get_code(classe->classe, "testeFields", "()V");

	/* frame 0 */
	create_frame(NULL, code_attribute, classe->classe->constant_pool);

	/* le System */
	_new(); frame_stack->pc++;
	/* variavel estatic */
	_dup(); frame_stack->pc++;
	_invokespecial(); frame_stack->pc++;
	printf("putfield/getfield: %s\n", pop() == 123 ? "ok" : "falhou");
	frame_stack->pc++;
	
	destroy_frame(NORMAL_INST);
}

void teste_class() {
	heap_element *classe = get_heap_element("classes/Classe2");
	printf("%s", get_class_name_classfile(classe->classe));
}

void teste() {
	init_instructions();
	init_heap();
	
	printf("\n***\nteste_stack()\n");
	//teste_stack();
	printf("\n***\nteste_heap()\n");
	//teste_heap();
	printf("\n***\nteste_primeiras_instrucoes()\n");
	//teste_primeiras_instrucoes();
	printf("\n***\nteste_instrucoes()\n");
	//teste_instrucoes();
	printf("\n***\nteste_ultimas_instrucoes()\n");
	//teste_ultimas_instrucoes();
	printf("\n***\nteste_class()\n");
	//teste_class();
	
	heap_element *classe = get_heap_element("Principal");
	boot(classe);
}
