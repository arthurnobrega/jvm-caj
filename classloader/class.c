/*
 Universidade de Brasilia
 Instituto de Ciencias Exatas
 Departamento de Ciencia da Computacao
 Software Basico
 Turma A - 02/2010

 class.c: Implementa as funcoes basicas de execucao do .class como iniciacao, instanciacao e carregamento
 */
#include "headers/class.h"
#include "headers/print_class.h"

void boot(classe_carregada *classe) {
	execute(classe, "main", "([Ljava/lang/String;)V", TRUE);
}

Code_attribute *get_code(classe_carregada **classe, char *nome, char *desc) {
	instancia *obj = (*classe)->instancia_estatica;
	method_info *metodo;
	attribute_info *att;

	assert(classe != NULL);
	assert(nome != NULL);
	assert(desc != NULL);

	/* percorre hierarquia */
	while (obj != NULL) {
		(*classe) = get_classe_carregada(obj->nome_qualificado);
		metodo = get_metodo((*classe)->classe, nome, desc);
		if (metodo != NULL) {
			att = get_attribute("Code", (*classe)->classe->constant_pool, metodo->attributes, metodo->attributes_count);

			return &(att->info.code);
		} else {
			obj = obj->super;
		}
	}

#ifdef DEBUG
	printf("Metodo n�o encontrado\n");
#endif

	return NULL;
}

method_info *get_metodo(ClassFile *class_file, char *nome, char *desc) {
	u1 *nome_tmp, *desc_tmp;
	method_info info;
	u2 i;

	assert(class_file != NULL);

	for (i = 0; i < class_file->methods_count; i++) {
		/* verifica se eh um metodo */
		info = class_file->methods[i];

		/* verifica se o nome do metodo */
		nome_tmp = get_ascii(class_file->constant_pool, info.name_index);
		desc_tmp = get_ascii(class_file->constant_pool, info.descriptor_index);
		if (strcmp((char *) nome, (char *) nome_tmp) == 0
				&& strcmp((char *) desc, (char *) desc_tmp) == 0) {
			return &(class_file->methods[i]);
		}
	}

	return NULL;
}

attribute_info *get_attribute(char *nome, cp_info *cp, attribute_info *att, u2 count) {
	u2 i;

	for (i = 0; i < count; i++) {
		/* verifica se eh um metodo */
		if (strcmp((char *) nome, (char *) get_ascii(cp, att[i].attribute_name_index)) == 0) {
			return &(att[i]);
		}
	}

	return NULL;
}

instancia *criar_instancia(u1 *class_name) {
	classe_carregada *classe;
	ClassFile *class_file;
	u1 *super;
	instancia *objeto;

	assert(class_name != NULL);

#ifdef DEBUG
	printf("criar_instancia(): Criando instancia da classe '%s'\n", class_name);
#endif

	/* se o super for Object nao instancie */
	if (strcmp((char *) class_name, OBJECT_CLASS) == 0) {
#ifdef DEBUG
		printf("criar_instancia(): superclasse = Object\n");
#endif
		return NULL;
	}

	/* tenta puxar a classe do heap, se nao tiver carrega */
	classe = get_classe_carregada(class_name);
	if (classe == NULL) {
		classe = load_class(class_name);
	}
	class_file = classe->classe;

	/* cria instancia */
	objeto = (instancia *) malloc(sizeof(instancia));
	objeto->nome_qualificado = class_name;
	super = get_class(class_file->constant_pool, class_file->super_class);
#ifdef DEBUG
	printf("criar_instancia(): superclasse = '%s'\n", super);
#endif
	objeto->super = criar_instancia(super);
	objeto->fields_count = class_file->fields_count;
	objeto->field = (u4 *) malloc(sizeof(u4) * objeto->fields_count);

	return objeto;
}

/*
 * Descricao: carrega o classfile correspondente ao parametro class_name, adicionando
 * ele ao vetor de classes carregadas (via adc_class), criando uma instancia dele para
 * uso estatico (via pegar_instancia) e finalmente executando o pseudo-codigo <clinit>,
 * onde ha a inicializacao de atributos estaticos.
 * 
 */
classe_carregada *load_class(u1 *class_name) {
	ClassFile *class_file = (ClassFile *) malloc(sizeof(ClassFile));
	classe_carregada *classe;
	FILE *arq;

	u1 *fn = c2f(class_name);
#ifdef DEBUG
	printf("load_class(): Carregando classe '%s'\n", fn);
#endif

	/* abre arquivo para leitura */
	arq = fopen((char *) fn, "rb");
#ifdef DEBUG
	printf("load_class(): Arquivo aberto\n");
#endif

	/* verifica arquivo */
	if (arq == NULL) {
		printf("Erro: nao foi possivel abrir o arquivo\n");
		exit(EXIT_FAILURE);
	}

	/* le arquivo .class */
	if (!lerClass(arq, class_file)) {
		printf("Erro: arquivo .class invalido ou corrompido\n");
		fclose(arq);
		exit(EXIT_FAILURE);
	}
#ifdef DEBUG
	printf("load_class(): Estrutura de classe lida\n");
#endif

	classe = adc_class(class_file);
	classe->instancia_estatica = criar_instancia(class_name);

	/* inicializa classe com um pseudo-codigo */
	if (execute(classe, "<clinit>", "()V", TRUE)) {
#ifdef DEBUG
		printf("load_class(): <clinit> executado\n");
#endif
	}

	fclose(arq);

	/*
	 * carregando o .class, imprime sua informa��o (se o modo for ativado) para
	 * controle de estruturas em runtime
	 * */
#ifdef DEBUG
	printf("CLASSE CARREGADA:\n");
	printf_General_Information(*class_file);
	printf("\n---------------\n");
#endif

	return classe;
}

u4 get_field_value(cp_info *info, instancia *objeto, u2 fieldref) {
	instancia *obj = objeto;
	classe_carregada *classe;
	u2 index;
	u1 *name;

	assert(info != NULL);
	assert(objeto != NULL);

	/* pega o nome do field */
	index = info[fieldref].info.fieldref_info.name_and_type_index;
	name = get_ascii(info, info[index].info.name_and_type_info.name_index);

	/* percorre hierarquia */
	while (obj != NULL) {
		classe = get_classe_carregada(obj->nome_qualificado);
		index = get_field_index(classe->classe, name);
		if (index < classe->classe->fields_count) {
			return obj->field[index];
		} else {
			obj = obj->super;
		}
	}

#ifdef DEBUG
	printf("N�o achou fielref\n");
#endif
	return 0;
}

void put_field_value(cp_info *info, instancia *objeto, u2 fieldref, u4 valor) {
	instancia *obj = objeto;
	classe_carregada *classe;
	u2 index;
	u1 *name;

	assert(info != NULL);
	assert(objeto != NULL);

	/* pega o nome do field */
	index = info[fieldref].info.fieldref_info.name_and_type_index;
	name = get_ascii(info, info[index].info.name_and_type_info.name_index);

	/* percorre hierarquia */
	while (obj != NULL) {
		classe = get_classe_carregada(obj->nome_qualificado);
		index = get_field_index(classe->classe, name);
		if (index < classe->classe->fields_count) {
			obj->field[index] = valor;
			return;
		} else {
			obj = obj->super;
		}
	}

#ifdef DEBUG
	printf("N�o achou fielref\n");
#endif
}

u2 get_field_index(ClassFile *class_file, u1 *field_name) {
	cp_info *info;
	int i;
	
	assert(class_file != NULL);

	info = class_file->constant_pool;

	for (i = 0; i < class_file->fields_count; i++) {
		u1 *name_tmp = get_ascii(info, class_file->fields[i].name_index);
		if (strcmp((char *) field_name, (char *) name_tmp) == 0) {
			break;
		}
	}
	return i;
}
