/*
 Universidade de Brasilia
 Instituto de Ciencias Exatas
 Departamento de Ciencia da Computacao
 Software Basico
 Turma A - 02/2010

insturcoes.c: M�dulo com a implementa��o das instru��es da Virtual Machine.
 */
#include "headers/instrucoes.h"
#include "headers/debug.h"

void init_instrucoes() {
	instrucao[0x00] = _nop;
	instrucao[0x01] = _aconst_null;
	instrucao[0x02] = _iconst_m1;
	instrucao[0x03] = _iconst_0;
	instrucao[0x04] = _iconst_1;
	instrucao[0x05] = _iconst_2;
	instrucao[0x06] = _iconst_3;
	instrucao[0x07] = _iconst_4;
	instrucao[0x08] = _iconst_5;
	instrucao[0x09] = _lconst_0;
	instrucao[0x0a] = _lconst_1;
	instrucao[0x0b] = _fconst_0;
	instrucao[0x0c] = _fconst_1;
	instrucao[0x0d] = _fconst_2;
	instrucao[0x0e] = _dconst_0;
	instrucao[0x0f] = _dconst_1;
	instrucao[0x10] = _bipush;
	instrucao[0x11] = _sipush;
	instrucao[0x12] = _ldc;
	instrucao[0x13] = _ldc_w;
	instrucao[0x14] = _ldc2_w;
	instrucao[0x15] = _iload;
	instrucao[0x16] = _lload;
	instrucao[0x17] = _fload;
	instrucao[0x18] = _dload;
	instrucao[0x19] = _aload;
	instrucao[0x1a] = _iload_0;
	instrucao[0x1b] = _iload_1;
	instrucao[0x1c] = _iload_2;
	instrucao[0x1d] = _iload_3;
	instrucao[0x1e] = _lload_0;
	instrucao[0x1f] = _lload_1;
	instrucao[0x20] = _lload_2;
	instrucao[0x21] = _lload_3;
	instrucao[0x22] = _fload_0;
	instrucao[0x23] = _fload_1;
	instrucao[0x24] = _fload_2;
	instrucao[0x25] = _fload_3;
	instrucao[0x26] = _dload_0;
	instrucao[0x27] = _dload_1;
	instrucao[0x28] = _dload_2;
	instrucao[0x29] = _dload_3;
	instrucao[0x2a] = _aload_0;
	instrucao[0x2b] = _aload_1;
	instrucao[0x2c] = _aload_2;
	instrucao[0x2d] = _aload_3;
	instrucao[0x2e] = _iaload;
	instrucao[0x2f] = _laload;
	instrucao[0x30] = _faload;
	instrucao[0x31] = _daload;
	instrucao[0x32] = _aaload;
	instrucao[0x33] = _baload;
	instrucao[0x34] = _caload;
	instrucao[0x35] = _saload;
	instrucao[0x36] = _istore;
	instrucao[0x37] = _lstore;
	instrucao[0x38] = _fstore;
	instrucao[0x39] = _dstore;
	instrucao[0x3a] = _astore;
	instrucao[0x3b] = _istore_0;
	instrucao[0x3c] = _istore_1;
	instrucao[0x3d] = _istore_2;
	instrucao[0x3e] = _istore_3;
	instrucao[0x3f] = _lstore_0;
	instrucao[0x40] = _lstore_1;
	instrucao[0x41] = _lstore_2;
	instrucao[0x42] = _lstore_3;
	instrucao[0x43] = _fstore_0;
	instrucao[0x44] = _fstore_1;
	instrucao[0x45] = _fstore_2;
	instrucao[0x46] = _fstore_3;
	instrucao[0x47] = _dstore_0;
	instrucao[0x48] = _dstore_1;
	instrucao[0x49] = _dstore_2;
	instrucao[0x4a] = _dstore_3;
	instrucao[0x4b] = _astore_0;
	instrucao[0x4c] = _astore_1;
	instrucao[0x4d] = _astore_2;
	instrucao[0x4e] = _astore_3;
	instrucao[0x4f] = _iastore;
	instrucao[0x50] = _lastore;
	instrucao[0x51] = _fastore;
	instrucao[0x52] = _dastore;
	instrucao[0x53] = _aastore;
	instrucao[0x54] = _bastore;
	instrucao[0x55] = _castore;
	instrucao[0x56] = _sastore;
	instrucao[0x57] = _pop;
	instrucao[0x58] = _pop2;
	instrucao[0x59] = _dup;
	instrucao[0x5a] = _dup_x1;
	instrucao[0x5b] = _dup_x2;
	instrucao[0x5c] = _dup2;
	instrucao[0x5d] = _dup2_x1;
	instrucao[0x5e] = _dup2_x2;
	instrucao[0x5f] = _swap;
	instrucao[0x60] = _iadd;
	instrucao[0x61] = _ladd;
	instrucao[0x62] = _fadd;
	instrucao[0x63] = _dadd;
	instrucao[0x64] = _isub;
	instrucao[0x65] = _lsub;
	instrucao[0x66] = _fsub;
	instrucao[0x67] = _dsub;
	instrucao[0x68] = _imul;
	instrucao[0x69] = _lmul;
	instrucao[0x6a] = _fmul;
	instrucao[0x6b] = _dmul;
	instrucao[0x6c] = _idiv;
	instrucao[0x6d] = _ldiv;
	instrucao[0x6e] = _fdiv;
	instrucao[0x6f] = _ddiv;
	instrucao[0x70] = _irem;
	instrucao[0x71] = _lrem;
	instrucao[0x72] = _frem;
	instrucao[0x73] = _drem;
	instrucao[0x74] = _ineg;
	instrucao[0x75] = _lneg;
	instrucao[0x76] = _fneg;
	instrucao[0x77] = _dneg;
	instrucao[0x78] = _ishl;
	instrucao[0x79] = _lshl;
	instrucao[0x7a] = _ishr;
	instrucao[0x7b] = _lshr;
	instrucao[0x7c] = _iushr;
	instrucao[0x7d] = _lushr;
	instrucao[0x7e] = _iand;
	instrucao[0x7f] = _land;
	instrucao[0x80] = _ior;
	instrucao[0x81] = _lor;
	instrucao[0x82] = _ixor;
	instrucao[0x83] = _lxor;
	instrucao[0x84] = _iinc;
	instrucao[0x85] = _i2l;
	instrucao[0x86] = _i2f;
	instrucao[0x87] = _i2d;
	instrucao[0x88] = _l2i;
	instrucao[0x89] = _l2f;
	instrucao[0x8a] = _l2d;
	instrucao[0x8b] = _f2i;
	instrucao[0x8c] = _f2l;
	instrucao[0x8d] = _f2d;
	instrucao[0x8e] = _d2i;
	instrucao[0x8f] = _d2l;
	instrucao[0x90] = _d2f;
	instrucao[0x91] = _i2b;
	instrucao[0x92] = _i2c;
	instrucao[0x93] = _i2s;
	instrucao[0x94] = _lcmp;
	instrucao[0x95] = _fcmpl;
	instrucao[0x96] = _fcmpg;
	instrucao[0x97] = _dcmpl;
	instrucao[0x98] = _dcmpg;
	instrucao[0x99] = _ifeq;
	instrucao[0x9a] = _ifne;
	instrucao[0x9b] = _iflt;
	instrucao[0x9c] = _ifge;
	instrucao[0x9d] = _ifgt;
	instrucao[0x9e] = _ifle;
	instrucao[0x9f] = _if_icmpeq;
	instrucao[0xa0] = _if_icmpne;
	instrucao[0xa1] = _if_icmplt;
	instrucao[0xa2] = _if_icmpge;
	instrucao[0xa3] = _if_icmpgt;
	instrucao[0xa4] = _if_icmple;
	instrucao[0xa5] = _if_acmpeq;
	instrucao[0xa6] = _if_acmpne;
	instrucao[0xa7] = _goto;
	instrucao[0xa8] = _jsr;
	instrucao[0xa9] = _ret;
	instrucao[0xaa] = _tableswitch;
	instrucao[0xab] = _lookupswitch;
	instrucao[0xac] = _ireturn;
	instrucao[0xad] = _lreturn;
	instrucao[0xae] = _freturn;
	instrucao[0xaf] = _dreturn;
	instrucao[0xb0] = _areturn;
	instrucao[0xb1] = _return;
	instrucao[0xb2] = _getstatic;
	instrucao[0xb3] = _putstatic;
	instrucao[0xb4] = _getfield;
	instrucao[0xb5] = _putfield;
	instrucao[0xb6] = _invokevirtual;
	instrucao[0xb7] = _invokespecial;
	instrucao[0xb8] = _invokestatic;
	instrucao[0xb9] = _invokeinterface;
	/*instrucao[0xba] = _xxxunusedxxx1;*/
	instrucao[0xbb] = _new;
	instrucao[0xbc] = _newarray;
	instrucao[0xbd] = _anewarray;
	instrucao[0xbe] = _arraylength;
	instrucao[0xbf] = _athrow;
	instrucao[0xc0] = _checkcast;
	instrucao[0xc1] = _instanceof;
	instrucao[0xc2] = _monitorenter;
	instrucao[0xc3] = _monitorexit;
	instrucao[0xc4] = _wide;
	instrucao[0xc5] = _multianewarray;
	instrucao[0xc6] = _ifnull;
	instrucao[0xc7] = _ifnonnull;
	instrucao[0xc8] = _goto_w;
	instrucao[0xc9] = _jsr_w;
}

int execute(classe_carregada *classe, char *func_nome, char *func_desc, int estatico) {
	Code_attribute *code;
	classe_carregada *cl = classe;
	int i, count = 0;
	u4 *stack;
	instancia *objref = NULL;
	int controle;
	u1 op_code;
	
	arrays = NULL;


	/* se n�o tiver o m�texecuteodo retorne com erro */
	code = get_code(&cl, func_nome, func_desc);
	if (code == NULL) {
		return 0;
	}

	/* pega quantidade de argumentos */
	if (strcmp((char *) func_nome, "main") != 0
			&& strcmp((char *) func_desc, "([Ljava/lang/String;)V") != 0) {
		count = contar_args(func_desc);
	}

	/* d� pops nos argumentos */
	stack = malloc(count * sizeof(u4));
	for (i = 0; i < count; i++) {
		stack[i] = pop();
	}

	/* pega refer�ncia da classe (se n�o for static) */
	if (estatico == FALSE) {
		objref = (instancia *) pop();
	}

	/* cria frame */
	create_frame(objref, code, cl->classe->constant_pool);

	/* d� pushs nos argumentos */
	for (i = 0; i < count; i++) {
		/* se for objeto pule a primeira vari�vel (this) */
		if (estatico == TRUE) {
			frame_stack->variable[count-i-1] = stack[i];
		} else {
			frame_stack->variable[count-i] = stack[i];
		}
	}

	while (frame_stack->pc < frame_stack->code_attribute->code_length) {
 		op_code = frame_stack->code_attribute->code[frame_stack->pc];
 		
		controle = instrucao[op_code]();
		if ((controle == POP0)||(controle == POP1)||(controle == POP2)){
			break;
		} else if (controle == DESVIO) {
			continue;
		} else if (controle == NAO_IMP) {
			printf("Instru��o 0x%x n�o implementada", op_code);
			exit(EXIT_FAILURE);
		}
		frame_stack->pc++;
	}

	destroy_frame(controle);

	return 1;
}

void invoke(int estatico) {
	u2 branch;
	cp_info *info;
	u1 *func_name;
	u1 *func_desc;
	u2 index;
	u1 *class_name;


	/*carrega o endere�o de branch*/
	branch = carrega_branch();

	info = frame_stack->constant_pool;

	/* se for da classe java/io/PrintStream, intervenha com um stub */
	index = info[branch].info.fieldref_info.class_index;
	class_name = get_class(info, index);

	/* pega nome da fun��o */
	index = info[branch].info.fieldref_info.name_and_type_index;
	func_name = get_ascii(info, info[index].info.name_and_type_info.name_index);

	/* pega par�metros da fun��o */
	index = frame_stack->constant_pool[branch].info.fieldref_info.name_and_type_index;
	func_desc = get_ascii(frame_stack->constant_pool, frame_stack->constant_pool[index].info.name_and_type_info.descriptor_index);

	if (strcmp((char *) class_name, "java/lang/Object") == 0
			&& strcmp((char *) func_name, "<init>") == 0) {

		/* pula */

	} else if (strcmp((char *) class_name, "java/io/PrintStream") == 0
			&& strcmp((char *) func_name, "println") == 0) {

		/* TODO: da pra implementar o print() tambem... */

		if (strcmp((char *) func_desc, "(C)V") == 0) {
			printf("%c\n", pop());
		} else if (strcmp((char *) func_desc, "(I)V") == 0) {
			printf("%i\n", pop());
		} else if (strcmp((char *) func_desc, "(Z)V") == 0) {
			printf(pop() ? "true\n" : "false\n");
		} else if (strcmp((char *) func_desc, "(F)V") == 0) {
			u4 valor = pop();
			float *f = (float *) malloc(sizeof(u4));
			f = (float *)memcpy(f,&valor,sizeof(u4));
			printf("%f\n", *f);
		} else if (strcmp((char *) func_desc, "(Ljava/lang/String;)V") == 0) {
			printf("%s\n", (char *) pop());
		}
	} else {
		classe_carregada *classe = get_classe_carregada(class_name);
		execute(classe, (char *) func_name, (char *) func_desc, estatico);
	}
}

/*
 * sub-rotina para encontrar o endereco de branch extraindo os dois branchbytes
 * do code
 * */
u2 carrega_branch() {
	u2 b1, b2;

	frame_stack->pc++;
	b1 = (u2)frame_stack->code_attribute->code[frame_stack->pc];
	frame_stack->pc++;
	b2 = (u2)frame_stack->code_attribute->code[frame_stack->pc];
	return ((b1<<8)|b2);
}

void add_multiarray(u4 ** ponteiro, u4 * tamanhos, u4 dimensoes ){
	int i, j;
	if(dimensoes == 0){
		return;
	}
	i = tamanhos[dimensoes-1];
	*ponteiro = (u4 *)malloc(i*sizeof(u4 *));
	//add_array(*ponteiro, i);
	for(j = 0; j < i; j++){
		printf("criado array: %i %i %x\n", i, j, ponteiro);
		add_multiarray(&(ponteiro[j]), tamanhos, dimensoes-1);
	}
}

/*
 * funcoes para DEBUG: se a flag for acionada (compilacao com define DEBUG ativo)
 * ira executar essas impressoes para visualizar as operacoes.
 */
#ifdef DEBUG
void printdbg_iconst(int valor) {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
#ifdef DEBUG
	printf("Elemento inserido na pilha: %d\n", valor);
#endif
}
void printdbg_fconst(float valor) {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
#ifdef DEBUG
	printf("Elemento inserido na pilha: %f\n", valor);
#endif
}
#endif

/* instru��es */
int _nop() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	return NORMAL_INST;
}

int _aconst_null() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
#ifdef DEBUG
	printf("Elemento inserido na pilha: NULL\n");
#endif
	push(0);
	return NORMAL_INST;
}

int _iconst_m1() {
#ifdef DEBUG
	printdbg_iconst(-1);
#endif
	push(-1);
	return NORMAL_INST;
}

int _iconst_0() {
#ifdef DEBUG
	printdbg_iconst(0);
#endif
	push(0);
	return NORMAL_INST;
}

int _iconst_1() {
#ifdef DEBUG
	printdbg_iconst(1);
#endif
	push(1);
	return NORMAL_INST;
}

int _iconst_2() {
#ifdef DEBUG
	printdbg_iconst(2);
#endif
	push(2);
	return NORMAL_INST;
}

int _iconst_3() {
#ifdef DEBUG
	printdbg_iconst(3);
#endif
	push(3);
	return NORMAL_INST;
}

int _iconst_4() {
#ifdef DEBUG
	printdbg_iconst(4);
#endif
	push(4);
	return NORMAL_INST;
}

int _iconst_5() {
#ifdef DEBUG
	printdbg_iconst(5);
#endif
	push(5);
	return NORMAL_INST;
}

int _lconst_0() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _lconst_1() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _fconst_0() {
	u4 *valor = (u4 *)malloc(sizeof(u4));
	float f = 0.0;
#ifdef DEBUG
	printdbg_fconst(f);
#endif
	valor = (u4 *)memcpy(valor,&f,sizeof(u4));
	push(*valor);
	return NORMAL_INST;
}

int _fconst_1() {
	u4 *valor = (u4 *)malloc(sizeof(u4));
	float f = 1.0;
#ifdef DEBUG
	printdbg_fconst(f);
#endif
	valor = (u4 *)memcpy(valor,&f,sizeof(u4));
	push(*valor);
	return NORMAL_INST;
}

int _fconst_2() {
	u4 *valor = (u4 *)malloc(sizeof(u4));
	float f = 2.0;
#ifdef DEBUG
	printdbg_fconst(f);
#endif
	valor = (u4 *)memcpy(valor,&f,sizeof(u4));
	push(*valor);
	return NORMAL_INST;
}

int _dconst_0() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _dconst_1() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _bipush() {
	u1 byte;
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	frame_stack->pc++;
	byte = frame_stack->code_attribute->code[frame_stack->pc];
#ifdef DEBUG
	printf("Elemento inserido na pilha: %x\n", byte);
#endif
	push((u4)byte);
	return NORMAL_INST;
}

int _sipush() {
	u2 valor;
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	valor = carrega_branch();
#ifdef DEBUG
	printf("Elemento inserido na pilha: %x\n", valor);
#endif
	push(valor);
	return NORMAL_INST;
}

int _ldc() {
	u1 indice;
	void * valor;
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	frame_stack->pc++;
	indice = frame_stack->code_attribute->code[frame_stack->pc];
	switch(frame_stack->constant_pool[indice].tag){
	case CONSTANT_Integer:
	case CONSTANT_Float:
		push(frame_stack->constant_pool[indice].info.integer_info.bytes);
#ifdef DEBUG
		printf("Elemento inserido na pilha: %x\n", frame_stack->constant_pool[indice].info.integer_info.bytes);
#endif
		break;
	case CONSTANT_String:
		valor = get_ascii(frame_stack->constant_pool, frame_stack->constant_pool[indice].info.string_info.string_index);
#ifdef DEBUG
		printf("Elemento inserido na pilha: %s\n", (char *)valor);
#endif
		push((u4) valor);
		break;
	default:
		printf("ldc(%d): Operando inv�lido!!!!",frame_stack->pc);
		exit(EXIT_FAILURE);
	}
	return NORMAL_INST;
}

int _ldc_w() {
	void * string;
	u2 indice;
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	indice = carrega_branch();
	switch(frame_stack->constant_pool[indice].tag){
	case CONSTANT_Integer:
	case CONSTANT_Float:
		push(frame_stack->constant_pool[indice].info.integer_info.bytes);
#ifdef DEBUG
		printf("Elemento inserido na pilha: %x\n", frame_stack->constant_pool[indice].info.integer_info.bytes);
#endif
		break;
	case CONSTANT_String:
		string = get_ascii(frame_stack->constant_pool, frame_stack->constant_pool[indice].info.string_info.string_index);
#ifdef DEBUG
		printf("Elemento inserido na pilha: %s\n", (char *)string);
#endif
		push((u4) string);
		break;
	default:
		printf("ldc(%d): Operando inv�lido!!!!",frame_stack->pc);
		exit(1);
	}
	return NORMAL_INST;
}

int _ldc2_w() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _iload() {
	u1 indice;
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	frame_stack->pc++;
	indice = frame_stack->code_attribute->code[frame_stack->pc];
#ifdef DEBUG
	printf("Elemento inserido na pilha: %x\n", frame_stack->variable[indice]);
#endif
	push(frame_stack->variable[indice]);
	return NORMAL_INST;
}

int _lload() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _fload() {
	u1 indice;
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	frame_stack->pc++;
	indice = frame_stack->code_attribute->code[frame_stack->pc];
#ifdef DEBUG
	printf("Elemento inserido na pilha: %x\n", frame_stack->variable[indice]);
#endif
	push(frame_stack->variable[indice]);
	return NORMAL_INST;
}

int _dload() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _aload() {
	u1 indice;
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	frame_stack->pc++;
	indice = frame_stack->code_attribute->code[frame_stack->pc];
#ifdef DEBUG
	printf("Elemento inserido na pilha: %x\n", frame_stack->variable[indice]);
#endif
	push(frame_stack->variable[indice]);
	return NORMAL_INST;
}

int _iload_0() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	push(frame_stack->variable[0]);
	return NORMAL_INST;
}

int _iload_1() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	push(frame_stack->variable[1]);
	return NORMAL_INST;
}

int _iload_2() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	push(frame_stack->variable[2]);
	return NORMAL_INST;
}

int _iload_3() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	push(frame_stack->variable[3]);
	return NORMAL_INST;
}

int _lload_0() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _lload_1() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _lload_2() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _lload_3() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _fload_0() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	push(frame_stack->variable[0]);
	return NORMAL_INST;
}

int _fload_1() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	push(frame_stack->variable[1]);
	return NORMAL_INST;
}

int _fload_2() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	push(frame_stack->variable[2]);
	return NORMAL_INST;
}

int _fload_3() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	push(frame_stack->variable[3]);
	return NORMAL_INST;
}

int _dload_0() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _dload_1() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _dload_2() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _dload_3() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _aload_0() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	push(frame_stack->variable[0]);
	return NORMAL_INST;
}

int _aload_1() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	push(frame_stack->variable[1]);
	return NORMAL_INST;
}

int _aload_2() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	push(frame_stack->variable[2]);
	return NORMAL_INST;
}

int _aload_3() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	push(frame_stack->variable[3]);
	return NORMAL_INST;
}

/*NOTA: O vetor � de ints, mas aqui ele pode ser interpretado como u4 pois n�o estamos
 * interessados no significado dos bits, mas apenas em copia-los*/
int _iaload() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	u4 indice = pop();
	u4 **vetor = malloc(sizeof(u4 *));
	u4 referencia = pop();
	*vetor = (u4 *)referencia;
#ifdef DEBUG
	printf("Elemento inserido na pilha: %x\n", *(*vetor+indice));
#endif
	push(*(*vetor+indice));
	return NORMAL_INST;
}

int _laload() {
	/*N�o implementado.*/
	return NAO_IMP;
}

/*NOTA: O vetor � de floats, mas aqui ele pode ser interpretado como u4 pois N�o estamos
 * interessados no significado dos bits, mas apenas em copia-los*/
int _faload() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	u4 indice = pop();
	u4 **vetor = malloc(sizeof(u4 *));
	u4 referencia = pop();
	*vetor = (u4 *)referencia;
#ifdef DEBUG
	printf("Elemento inserido na pilha: %x\n", *(*vetor+indice));
#endif
	push(*(*vetor+indice));
	return NORMAL_INST;
}

int _daload() {
	/*N�o implementado.*/
	return NAO_IMP;
}

/*NOTA: O vetor � de referencias, mas aqui ele pode ser interpretado como u4 pois N�o estamos
 * interessados no significado dos bits, mas apenas em copia-los*/
int _aaload() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	u4 indice = pop();
	u4 **vetor = malloc(sizeof(u4 *));
	u4 referencia = pop();
	*vetor = (u4 *)referencia;
#ifdef DEBUG
	printf("Elemento inserido na pilha: %x\n", *(*vetor+indice));
#endif
	push(*(*vetor+indice));
	return NORMAL_INST;
}

int _baload() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	u4 indice = pop();
	u1 **vetor = malloc(sizeof(u1 *));
	u4 referencia = pop();
	*vetor = (u1 *) referencia;
#ifdef DEBUG
	printf("Elemento inserido na pilha: %x\n", *(*vetor+indice));
#endif
	push(*(*vetor+indice));
	return NORMAL_INST;
}

int _caload() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	u4 indice = pop();
	u1 **vetor = malloc(sizeof(u1 *));
	u4 referencia = pop();
	*vetor = (u1 *) referencia;
#ifdef DEBUG
	printf("Elemento inserido na pilha: %x\n", *(*vetor+indice));
#endif
	push(*(*vetor+indice));
	return NORMAL_INST;
}

int _saload() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	u4 indice = pop();
	u2 **vetor = malloc(sizeof(u2 *));
	u4 referencia = pop();
	*vetor = (u2 *) referencia;
#ifdef DEBUG
	printf("Elemento inserido na pilha: %x\n", *(*vetor+indice));
#endif
	push(*(*vetor+indice));
	return NORMAL_INST;
}

int _istore() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	u1 indice;
	frame_stack->pc++;
	indice = frame_stack->code_attribute->code[frame_stack->pc];
	frame_stack->variable[indice] = pop();
	return NORMAL_INST;
}

int _lstore() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _fstore() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	u1 indice;
	frame_stack->pc++;
	indice = frame_stack->code_attribute->code[frame_stack->pc];
	frame_stack->variable[indice] = pop();
	return NORMAL_INST;
}

int _dstore() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _astore() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	u1 indice;
	frame_stack->pc++;
	indice = frame_stack->code_attribute->code[frame_stack->pc];
	frame_stack->variable[indice] = pop();
	return NORMAL_INST;
}

int _istore_0() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	frame_stack->variable[0] = pop();
	return NORMAL_INST;
}

int _istore_1() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	frame_stack->variable[1] = pop();
	return NORMAL_INST;
}

int _istore_2() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	frame_stack->variable[2] = pop();
	return NORMAL_INST;
}

int _istore_3() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	frame_stack->variable[3] = pop();
	return NORMAL_INST;
}

int _lstore_0() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _lstore_1() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _lstore_2() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _lstore_3() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _fstore_0() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	frame_stack->variable[0] = pop();
	return NORMAL_INST;
}

int _fstore_1() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	frame_stack->variable[1] = pop();
	return NORMAL_INST;
}

int _fstore_2() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	frame_stack->variable[2] = pop();
	return NORMAL_INST;
}

int _fstore_3() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	frame_stack->variable[3] = pop();
	return NORMAL_INST;
}

int _dstore_0() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _dstore_1() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _dstore_2() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _dstore_3() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _astore_0() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	frame_stack->variable[0] = pop();
	return NORMAL_INST;
}

int _astore_1() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	frame_stack->variable[1] = pop();
	return NORMAL_INST;
}

int _astore_2() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	frame_stack->variable[2] = pop();
	return NORMAL_INST;
}

int _astore_3() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	frame_stack->variable[3] = pop();
	return NORMAL_INST;
}

int _iastore() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	u4 valor = pop();
	u4 indice = pop();
	u4 referencia = pop();
	int ** vetor = malloc(sizeof(int *));
	*vetor = (int *) referencia;
	*(*vetor+indice) = (int) valor;
	return NORMAL_INST;
}

int _lastore() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _fastore() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	u4 valor = pop();
	u4 indice = pop();
	u4 referencia = pop();
	float ** vetor = malloc(sizeof(float *));
	*vetor = (float *) referencia;
	memcpy((*vetor+indice),&valor, sizeof(u4));
	return NORMAL_INST;
}

int _dastore() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _aastore() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	u4 valor = pop();
	u4 indice = pop();
	u4 referencia = pop();
	u4 ** vetor = malloc(sizeof(u4 *));
	*vetor = (u4 *) referencia;
	*(*vetor+indice) = valor;
	return NORMAL_INST;
}

int _bastore() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	u4 valor = pop();
	u4 indice = pop();
	u4 referencia = pop();
	u1 ** vetor = malloc(sizeof(u1 *));
	*vetor = (u1 *) referencia;
	*(*vetor+indice) = (u1) valor;
	return NORMAL_INST;
}

int _castore() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	u4 valor = pop();
	u4 indice = pop();
	u4 referencia = pop();
	u1 ** vetor = malloc(sizeof(u1 *));
	*vetor = (u1 *) referencia;
	*(*vetor+indice) = (u2) valor;
	return NORMAL_INST;
}

int _sastore() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	u4 valor = pop();
	u4 indice = pop();
	u4 referencia = pop();
	u2 ** vetor = malloc(sizeof(u2 *));
	*vetor = (u2 *) referencia;
	*(*vetor+indice) = (u2) valor;
	return NORMAL_INST;
}

int _pop() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	pop();
	return NORMAL_INST;
}

int _pop2() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	pop();
	pop();
	return NORMAL_INST;
}

int _dup() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	u4 valor = pop();
	push(valor);
	push(valor);
	return NORMAL_INST;
}

int _dup_x1() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	u4 valor1 = pop();
	u4 valor2 = pop();
	push(valor1);
	push(valor2);
	push(valor1);
	return NORMAL_INST;
}

int _dup_x2() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	u4 valor1 = pop();
	u4 valor2 = pop();
	u4 valor3 = pop();
	push(valor1);
	push(valor3);
	push(valor2);
	push(valor1);
	return NORMAL_INST;
}

int _dup2() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	u4 valor1 = pop();
	u4 valor2 = pop();
	push(valor2);
	push(valor1);
	push(valor2);
	push(valor1);
	return NORMAL_INST;
}

int _dup2_x1() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	u4 valor1 = pop();
	u4 valor2 = pop();
	u4 valor3 = pop();
	push(valor2);
	push(valor1);
	push(valor3);
	push(valor2);
	push(valor1);
	return NORMAL_INST;
}

int _dup2_x2() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	u4 valor1 = pop();
	u4 valor2 = pop();
	u4 valor3 = pop();
	u4 valor4 = pop();
	push(valor2);
	push(valor1);
	push(valor4);
	push(valor3);
	push(valor2);
	push(valor1);
	return NORMAL_INST;
}

int _swap() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	u4 valor1 = pop();
	u4 valor2 = pop();
	push(valor1);
	push(valor2);
	return NORMAL_INST;
}

int _iadd() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	int valor1, valor2;
	valor1 = (int) pop();
	valor2 = (int) pop();
	push((u4)(valor1 + valor2));
	return NORMAL_INST;
}

int _ladd() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _fadd() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	float valor1_f, valor2_f, retorno_f;
	u4 v1, v2, retorno;

	v1 = pop();
	v2 = pop();

	memcpy(&valor1_f,&v1,sizeof(float));
	memcpy(&valor2_f,&v2,sizeof(float));

	retorno_f = (valor2_f) + (valor1_f);
	memcpy(&retorno, &retorno_f, sizeof(u4));

	push(retorno);
	return NORMAL_INST;
}

int _dadd() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _isub() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	int valor1, valor2;
	valor1 = (int) pop();
	valor2 = (int) pop();
	push((u4)(valor1 - valor2));
	return NORMAL_INST;
}

int _lsub() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _fsub() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	float valor1_f, valor2_f, retorno_f;
	u4 v1, v2, retorno;

	v1 = pop();
	v2 = pop();

	memcpy(&valor1_f,&v1,sizeof(float));
	memcpy(&valor2_f,&v2,sizeof(float));

	retorno_f = (valor2_f) - (valor1_f);
	memcpy(&retorno, &retorno_f, sizeof(u4));

	push(retorno);
	return NORMAL_INST;
}

int _dsub() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _imul() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	int valor1, valor2;
	valor1 = (int) pop();
	valor2 = (int) pop();
	push((u4)(valor1 * valor2));
	return NORMAL_INST;
}

int _lmul() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _fmul() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	float valor1_f, valor2_f, retorno_f;
	u4 v1, v2, retorno;

	v1 = pop();
	v2 = pop();

	memcpy(&valor1_f,&v1,sizeof(float));
	memcpy(&valor2_f,&v2,sizeof(float));

	retorno_f = (valor2_f) * (valor1_f);
	memcpy(&retorno, &retorno_f, sizeof(u4));

	push(retorno);
	return NORMAL_INST;
}

int _dmul() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _idiv() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	int valor1, valor2;
	valor1 = (int) pop();
	valor2 = (int) pop();
	/*se valor2 = 0, aborta o programa por causa da operacao ilegal*/
	if (valor2 == 0) {
		/*erro - divis�o inteira por zero*/
		exit(DIV_ZERO);
	}
	push((u4)(valor1 / valor2));
	return NORMAL_INST;
}

int _ldiv() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _fdiv() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	float valor1_f, valor2_f, retorno_f;
	u4 v1, v2, retorno;

	v1 = pop();
	v2 = pop();

	memcpy(&valor1_f,&v1,sizeof(float));
	memcpy(&valor2_f,&v2,sizeof(float));

	retorno_f = (valor2_f) / (valor1_f);
	memcpy(&retorno, &retorno_f, sizeof(u4));

	push(retorno);
	return NORMAL_INST;
}

int _ddiv() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _irem() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	int valor1, valor2;
	valor1 = (int) pop();
	valor2 = (int) pop();
	/*retorno = parametro1�(parametro1 / parametro2) * parametro2*/
	push((u4)(valor1 - (valor1 /valor2) * valor2));
	return NORMAL_INST;
}

int _lrem() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _frem() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	float valor1_f, valor2_f, retorno_f;
	u4 v1, v2, retorno;

	v1 = pop();
	v2 = pop();

	memcpy(&valor1_f,&v1,sizeof(float));
	memcpy(&valor2_f,&v2,sizeof(float));

	retorno_f = fmodf(valor1_f, valor2_f);
	memcpy(&retorno, &retorno_f, sizeof(u4));

	push(retorno);
	return NORMAL_INST;
}

int _drem() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _ineg() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	int valor;
	valor = (int) pop();
	push((u4)(~valor + 1));
	return NORMAL_INST;
}

int _lneg() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _fneg() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	u4 valor, retorno;
	float retorno_f, valor_f;

	valor = pop();

	memcpy(&valor_f,&valor,sizeof(float));

	retorno_f = -(valor_f);
	memcpy(&retorno, &retorno_f, sizeof(u4));

	push(retorno);
	return NORMAL_INST;
}

int _dneg() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _ishl() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	int valor1, valor2;
	valor1 = (int) pop();
	valor2 = (int) pop();

	/*o valor2 eh supostamente um valor valido entre 0 e 31*/
	valor2 &= MASK_SHIFT;

	push((u4) (valor1 << valor2));
	return NORMAL_INST;
}

int _lshl() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _ishr() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	int valor1, valor2;
	valor1 = (int) pop();
	valor2 = (int) pop();

	/*o valor2 eh supostamente um valor valido entre 0 e 31*/
	valor2 &= MASK_SHIFT;

	push((u4) (valor1 >> valor2));
	return NORMAL_INST;
}

int _lshr() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _iushr() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	int valor1, valor2;
	valor1 = (int) pop();
	valor2 = (int) pop();

	/*o valor2 eh supostamente um valor valido entre 0 e 31*/
	valor2 &= MASK_SHIFT;

	/*
	 * Caso parametro1 seja positivo, a opera��o retorno = parametro1 >> s � realizada e o
	 * resultado (retorno) colocado na pilha. Caso seja negativo, a opera��o retorno = (parametro1 >> s) (
	 * 2 << ~s) � realizada e o resultado (retorno) colocado na pilha.
	 */
	if (valor1 >= 0)
		push((u4) (valor1 >> valor2));
	else
		push((u4) ((valor1 >> valor2)-(2 << ~valor2)));

	return NORMAL_INST;
}

int _lushr() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _iand() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	int valor1, valor2;
	valor1 = (int) pop();
	valor2 = (int) pop();

	push((u4) (valor1 & valor2));
	return NORMAL_INST;
}

int _land() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _ior() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	int valor1, valor2;
	valor1 = (int) pop();
	valor2 = (int) pop();

	push((u4) (valor1 | valor2));
	return NORMAL_INST;
}

int _lor() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _ixor() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	int valor1, valor2;
	valor1 = (int) pop();
	valor2 = (int) pop();

	push((u4) (valor1 ^ valor2));
	return NORMAL_INST;
}

int _lxor() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _iinc() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	u1 index;
	char cons;

	frame_stack->pc++;
	index = frame_stack->code_attribute->code[frame_stack->pc];
	frame_stack->pc++;
	cons = (char) frame_stack->code_attribute->code[frame_stack->pc];
	
	frame_stack->variable[index] += cons;

	return NORMAL_INST;
}

int _i2l() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _i2f() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	int valor;
	float ret_f;
	u4 ret_u4;

	valor = (int) pop();
	ret_f = (float) valor;
	memcpy(&ret_u4, &ret_f, sizeof(u4));

	push(ret_u4);
	return NORMAL_INST;
}

int _i2d() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _l2i() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _l2f() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _l2d() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _f2i() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	int valor;
	float valor_f;
	int retorno;

	valor = (int) pop();

	memcpy(&valor_f, &valor, sizeof(float));

	/*caso especial de valor == NaN*/
	if (fpclassify(valor_f) == FP_NAN)
		retorno = 0;
	else
		retorno = (int)(valor_f);

	push((u4) retorno);
	return NORMAL_INST;
}

int _f2l() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _f2d() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _d2i() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _d2l() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _d2f() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _i2b() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	int valor1;
	u1 retorno;

	valor1 = (int) pop();
	retorno = (u1) valor1;

	push((u4)retorno);
	return NORMAL_INST;
}

int _i2c() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	int valor1;
	char retorno;

	valor1 = (int) pop();
	retorno = (char) valor1;

	push((u4)retorno);
	return NORMAL_INST;
}

int _i2s() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	int valor1;
	u2 retorno;

	valor1 = (int) pop();
	retorno = (u2) valor1;

	push((u4)retorno);
	return NORMAL_INST;
}

int _lcmp() {
	/*N�o implementado.*/
	return NAO_IMP;
}

/*
 * Detalhe: para tornar poss�vel a compara��o de ponto flutuante, assume-se o valor
 * inteiro da �rea de mem�ria referenciada pelo ponteiro float para compara��o.
 * */
int _fcmpl() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	float f1, f2;
	u4 v1, v2;

	/*testa o caso NaN*/
	memcpy(&f1, &v1, sizeof(float));
	memcpy(&f2, &v2, sizeof(float));
	if ((isnan(f1) == 0)||(isnan(f2) == 0)) {
		push(-1);
		return NORMAL_INST;
	}

	v1 = pop();
	v2 = pop();

	if (v1 > v2)
		push(1);
	else if (v1 < v2)
		push(-1);
	else
		push(0);

	return NORMAL_INST;
}

int _fcmpg() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	float f1, f2;
	u4 v1, v2;

	/*testa o caso NaN*/
	memcpy(&f1, &v1, sizeof(float));
	memcpy(&f2, &v2, sizeof(float));
	if ((isnan(f1) == 0)||(isnan(f2) == 0)) {
		push(1);
		return NORMAL_INST;
	}

	v1 = pop();
	v2 = pop();

	if (v1 > v2)
		push(1);
	else if (v1 < v2)
		push(-1);
	else
		push(0);

	return NORMAL_INST;
}

int _dcmpl() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _dcmpg() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _ifeq() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	int p1;
	short branch;

	p1 = pop();

	/*carrega o endere�o de branch*/
	branch = carrega_branch();

	/*s� d� branch se parametro for igual a zero*/
	if (p1 == 0) {
		frame_stack->pc += (int) (branch -2);

		return DESVIO;
	} else {
		return NORMAL_INST;
	}
}

int _ifne() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	int p1;
	short branch;

	p1 = pop();

	/*carrega o endere�o de branch*/
	branch = carrega_branch();

	/*s� d� branch se parametro for diferente de zero*/
	if (p1 != 0) {
		frame_stack->pc += (int) (branch -2);

		return DESVIO;
	} else {
		return NORMAL_INST;
	}

	return DESVIO;
}

int _iflt() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	int p1;
	short branch;

	p1 = pop();

	/*carrega o endere�o de branch*/
	branch = carrega_branch();

	/*s� d� branch se parametro for menor que zero*/
	if (p1 < 0) {
		frame_stack->pc += (int) (branch -2);

		return DESVIO;
	} else {
		return NORMAL_INST;
	}
}

int _ifge() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	int p1;
	short branch;

	p1 = pop();

	/*carrega o endere�o de branch*/
	branch = carrega_branch();

	/*s� d� branch se parametro for maior ou igual a zero*/
	if (p1 >= 0) {
		frame_stack->pc += (int) (branch -2);

		return DESVIO;
	} else {
		return NORMAL_INST;
	}

}

int _ifgt() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	int p1;
	short branch;

	p1 = pop();

	/*carrega o endere�o de branch*/
	branch = carrega_branch();

	/*s� d� branch se parametro for maior que zero*/
	if (p1 > 0) {
		frame_stack->pc += (int) (branch -2);

		return DESVIO;
	} else {
		return NORMAL_INST;
	}

}

int _ifle() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	int p1;
	short branch;

	p1 = pop();

	/*carrega o endere�o de branch*/
	branch = carrega_branch();

	/*s� d� branch se parametro for menor ou igual a zero*/
	if (p1 <= 0) {
		frame_stack->pc += (int) (branch -2);

		return DESVIO;
	} else {
		return NORMAL_INST;
	}

}

int _if_icmpeq() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	int p1, p2;
	short branch;

	p1 = (int) pop();
	p2 = (int) pop();

	/*carrega o endere�o de branch*/
	branch = carrega_branch();

	/*s� d� branch se parametro1 for igual a parametro2*/
	if (p1 == p2) {
		frame_stack->pc += (int) (branch -2);

		return DESVIO;
	} else {
		return NORMAL_INST;
	}
	
}

int _if_icmpne() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	int p1, p2;
	short branch;

	p1 = (int) pop();
	p2 = (int) pop();

	/*carrega o endere�o de branch*/
	branch = carrega_branch();

	/*s� d� branch se parametro1 for diferente de parametro2*/
	if (p1 != p2) {
		frame_stack->pc += (int) (branch -2);

		return DESVIO;
	} else {
		return NORMAL_INST;
	}
}

int _if_icmplt() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	int p1, p2;
	short branch;

	p1 = (int) pop();
	p2 = (int) pop();

	/*carrega o endere�o de branch*/
	branch = carrega_branch();

	/*s� d� branch se parametro1 for menor que parametro2*/
	if (p2 < p1) {
		frame_stack->pc += (int) (branch -2);

		return DESVIO;
	} else {
		return NORMAL_INST;
	}
}

int _if_icmpge() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	int p1, p2;
	short branch;

	p1 = (int) pop();
	p2 = (int) pop();

	/*carrega o endere�o de branch*/
	branch = carrega_branch();

	/*s� d� branch se parametro1 for maior ou igual a parametro2*/
	if (p2 >= p1) {
		frame_stack->pc += (int) (branch -2);

		return DESVIO;
	} else {
		return NORMAL_INST;
	}
}

int _if_icmpgt() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	int p1, p2;
	short branch;

	p1 = (int) pop();
	p2 = (int) pop();

	/*carrega o endere�o de branch*/
	branch = carrega_branch();

	/*s� d� branch se parametro1 for maior do que parametro2*/
	if (p2 > p1) {
		frame_stack->pc += (int) (branch -2);

		return DESVIO;
	} else {
		return NORMAL_INST;
	}
}

int _if_icmple() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	int p1, p2;
	short branch;

	p1 = (int) pop();
	p2 = (int) pop();

	/*carrega o endere�o de branch*/
	branch = carrega_branch();

	/*s� d� branch se parametro1 for menor ou igual a parametro2*/
	if (p2 <= p1) {
		frame_stack->pc += (int) (branch -2);

		return DESVIO;
	} else {
		return NORMAL_INST;
	}
}

int _if_acmpeq() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	int p1, p2;
	short branch;

	p1 = (int) pop();
	p2 = (int) pop();

	/*carrega o endere�o de branch*/
	branch = carrega_branch();

	/*s� d� branch se parametro1 for igual a parametro2*/
	if (p1 == p2) {
		frame_stack->pc += (int) (branch -2);

		return DESVIO;
	} else {
		return NORMAL_INST;
	}
}

int _if_acmpne() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	int p1, p2;
	short branch;

	p1 = (int) pop();
	p2 = (int) pop();

	/*carrega o endere�o de branch*/
	branch = carrega_branch();

	/*s� d� branch se parametro1 for diferente de parametro2*/
	if (p1 != p2) {
		frame_stack->pc += (int) (branch -2);

		return DESVIO;
	} else {
		return NORMAL_INST;
	}
}

int _goto() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	short branch;

	/*carrega o endere�o de branch*/
	branch = carrega_branch();

	frame_stack->pc += (int) (branch -2);

	return DESVIO;
}

int _jsr() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _ret() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _tableswitch() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _lookupswitch() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _ireturn() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	return POP1;
}

int _lreturn() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _freturn() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	return POP1;
}

int _dreturn() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _areturn() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	return POP1;
}

int _return() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	return POP0;
}

int _getstatic() {
	classe_carregada *classe;
	u4 valor;

#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	u2 branch = carrega_branch();

	/* retorna o nome da classe */
	u2 index = frame_stack->constant_pool[branch].info.fieldref_info.class_index;
	u1 *class_name = get_class(frame_stack->constant_pool, index);
	if (strcmp((char *) class_name, "java/lang/System") == 0) {
		/* se for da classe System ignore. trataremos com stubs as suas chamadas */
		return NORMAL_INST;
	}
	classe = get_classe_carregada(class_name);

	valor = get_field_value(frame_stack->constant_pool, classe->instancia_estatica, branch);

	push(valor);

	return NORMAL_INST;
}

int _putstatic() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	u2 branch = carrega_branch();

	/* retorna o nome da classe */
	u2 index = frame_stack->constant_pool[branch].info.fieldref_info.class_index;
	u1 *class_name = get_class(frame_stack->constant_pool, index);
	classe_carregada *classe = get_classe_carregada(class_name);

	u4 valor = pop();
	put_field_value(frame_stack->constant_pool, classe->instancia_estatica, branch, valor);

	return NORMAL_INST;
}

int _getfield() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	u2 branch = carrega_branch();
	u4 objref = pop();

	u4 valor = get_field_value(frame_stack->constant_pool, (instancia *) objref, branch);

	push(valor);

	return NORMAL_INST;
}

int _putfield() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	u2 branch = carrega_branch();
	u4 valor = pop();
	u4 objref = pop();

	put_field_value(frame_stack->constant_pool, (instancia *) objref, branch, valor);

	return NORMAL_INST;
}

int _invokevirtual() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	invoke(FALSE);
	return NORMAL_INST;
}

int _invokespecial() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	invoke(FALSE);
	return NORMAL_INST;
}

int _invokestatic() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	invoke(TRUE);
	return NORMAL_INST;
}

int _invokeinterface() {
	/*N�o implementado.*/
	return NAO_IMP;
}

/*int _xxxunusedxxx1() {
	printf("porn instruction");
	return NORMAL_INST;
}*/

int _new() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	u2 branch = carrega_branch();
	u1 *class_name = get_class(frame_stack->constant_pool, branch);
	instancia *objref = criar_instancia(class_name);

	push((u4) objref);
	return NORMAL_INST;
}

int _newarray() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	u1 tipo;
	u4 tamanho = pop();
	void * vetor;
	assert( ((int)tamanho) >0 );
	frame_stack->pc++;
	tipo = frame_stack->code_attribute->code[frame_stack->pc];
	switch(tipo){
	case T_BOOLEAN:
	case T_BYTE:
	case T_CHAR:
		vetor = (char *) calloc(tamanho,sizeof(char));
		break;
	case T_SHORT:
		vetor = (short *) calloc(tamanho,sizeof(short));
		break;
	case T_INT:
		vetor = (int *) calloc(tamanho,sizeof(int));
		break;
	case T_FLOAT:
		vetor = (float *) calloc(tamanho,sizeof(float));
		break;
	case T_LONG:
	case T_DOUBLE:
		/*N�o implementado.*/
		return NAO_IMP;
	default:
		printf("newarray(%d): Tipo de array inv�lido!!!!",frame_stack->pc);
		exit(EXIT_FAILURE);
	}
	add_array(vetor, tamanho);
	push((u4) vetor);
	return NORMAL_INST;
}

int _anewarray() {
	u4 tamanho;
	void * vetor; 

#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	carrega_branch();
	tamanho = pop();
	vetor = calloc(tamanho,sizeof(void *));
	add_array(vetor, tamanho);
	push((u4) vetor);
	return NORMAL_INST;
}

int _arraylength() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	u4 referencia = pop();
	arrays_struct *descritor_vetor = get_array((void *) referencia);
	push(descritor_vetor->tamanho);
	return NORMAL_INST;
}

int _athrow() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _checkcast() {
	/*N�o implementado
	 * TODO pode vir a ser*/
	return NAO_IMP;
}

int _instanceof() {
	/*N�o implementado
	 * TODO pode vir a ser*/
	return NAO_IMP;
}

int _monitorenter() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _monitorexit() {
	/*N�o implementado.*/
	return NAO_IMP;
}

int _wide() {
	/*N�o implementado
	 * TODO pode vir a ser*/
	return NAO_IMP;
}

int _multianewarray() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	u1 dimensoes, i;
	u4 * tamanhos = NULL;
	u4 ** vetor = malloc(sizeof(u4 *));
	carrega_branch();

	frame_stack->pc++;
	dimensoes = frame_stack->code_attribute->code[frame_stack->pc];
	tamanhos = (u4 *) malloc(dimensoes*sizeof(u4));
	for(i = 0; i < dimensoes; i++){
		tamanhos[i] = pop();
	}
	add_multiarray(vetor, tamanhos, dimensoes);
	push((u4) vetor);
	return NORMAL_INST;
}

int _ifnull() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	u4 referencia = pop();
	short branch = carrega_branch();
	if(referencia == 0){
		frame_stack->pc += (int) branch -2;
	}

	return DESVIO;
}

int _ifnonnull() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	u4 referencia = pop();
	short branch = carrega_branch();
	if(referencia != 0){
		frame_stack->pc += (int) branch -2;
	}

	return DESVIO;
}

int _goto_w() {
#ifdef DEBUG
	printf("Instru��o 0x%x executada\n", (u1)frame_stack->code_attribute->code[frame_stack->pc]);
#endif
	short branch_word1 = carrega_branch();
	short branch_word2 = carrega_branch();
	int branch = (branch_word1 << 16)|branch_word2;
	frame_stack->pc += (int) branch -4;
	return NORMAL_INST;
}

int _jsr_w() {
	/*N�o implementado.*/
	return NAO_IMP;
}
