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


 class.c: Implementa as funcoes basicas de execucao do .class como iniciacao, instanciacao e carregamento
 */
#include "headers/class.h"
#include "classfile/print_class.h"

void boot(heap_element *classe) {
	execute(classe, "main", "([Ljava/lang/String;)V", TRUE);
}

Code_attribute *get_code(heap_element **classe, char *nome, char *desc) {
	instance *obj = (*classe)->instancia_estatica;
	method_info *metodo;
	attribute_info *att;

	assert(classe != NULL);
	assert(nome != NULL);
	assert(desc != NULL);

	/* percorre hierarquia */
	while (obj != NULL) {
		(*classe) = get_heap_element(obj->nome_qualificado);
		metodo = get_metodo((*classe)->classe, nome, desc);
		if (metodo != NULL) {
			att = get_attribute("Code", (*classe)->classe->constant_pool, metodo->attributes, metodo->attributes_count);

			return &(att->info.code);
		} else {
			obj = obj->super;
		}
	}

#ifdef DEBUG
	printf("get_code(%s): Metodo nao encontrado\n", nome);
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
		nome_tmp = get_utf8_string(class_file->constant_pool, info.name_index);
		desc_tmp = get_utf8_string(class_file->constant_pool, info.descriptor_index);
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
		if (strcmp((char *) nome, (char *) get_utf8_string(cp, att[i].attribute_name_index)) == 0) {
			return &(att[i]);
		}
	}

	return NULL;
}

instance *create_instance(u1 *class_name) {
	heap_element *element;
	ClassFile *class_file;
	u1 *super;
	instance *objeto;

	assert(class_name != NULL);

#ifdef DEBUG
	printf("create_instance(): Criando instancia da classe '%s'\n", class_name);
#endif

	/* se o super for Object nao instancie */
	if (strcmp((char *) class_name, OBJECT_CLASS) == 0) {
#ifdef DEBUG
		printf("create_instance(): superclasse = Object\n");
#endif
		return NULL;
	}

	/* tenta puxar a classe do heap, se nao tiver carrega */
	element = get_heap_element(class_name);

	class_file = element->classe;

	/* cria instancia */
	objeto = (instance *) malloc(sizeof(instance));
	objeto->nome_qualificado = class_name;
	super = get_class_name(class_file->constant_pool, class_file->super_class);
#ifdef DEBUG
	printf("create_instance(): superclasse = '%s'\n", super);
#endif
	objeto->super = create_instance(super);
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
heap_element *load_class(u1 *class_name) {
	ClassFile *class_file = (ClassFile *) malloc(sizeof(ClassFile));
	heap_element *classe;
	FILE *arq;

	u1 *fn = get_modified_class_name(class_name);
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
	if (!read_class_file(arq, class_file)) {
		printf("Erro: arquivo .class invalido ou corrompido\n");
		fclose(arq);
		exit(EXIT_FAILURE);
	}
#ifdef DEBUG
	printf("load_class(): Estrutura de classe lida\n");
#endif

	classe = add_heap_element(class_file);
	classe->instancia_estatica = create_instance(class_name);

	/* inicializa classe com um pseudo-codigo */
	if (execute(classe, "<clinit>", "()V", TRUE)) {
#ifdef DEBUG
		printf("load_class(): <clinit> executado\n");
#endif
	}

	fclose(arq);

	/*
	 * carregando o .class, imprime sua informação (se o modo for ativado) para
	 * controle de estruturas em runtime
	 * */
#ifdef DEBUG
	printf_General_Information(*class_file);
#endif

	return classe;
}

u4 get_field_value(cp_info *info, instance *objeto, u2 fieldref) {
	instance *obj = objeto;
	heap_element *classe;
	u2 index;
	u1 *name;

	assert(info != NULL);
	assert(objeto != NULL);

	/* pega o nome do field */
	index = info[fieldref].info.fieldref_info.name_and_type_index;
	name = get_utf8_string(info, info[index].info.name_and_type_info.name_index);

	/* percorre hierarquia */
	while (obj != NULL) {
		classe = get_heap_element(obj->nome_qualificado);
		index = get_field_index(classe->classe, name);
		if (index < classe->classe->fields_count) {
			return obj->field[index];
		} else {
			obj = obj->super;
		}
	}

#ifdef DEBUG
	printf("Não achou fielref\n");
#endif
	return 0;
}

void put_field_value(cp_info *info, instance *objeto, u2 fieldref, u4 valor) {
	instance *obj = objeto;
	heap_element *classe;
	u2 index;
	u1 *name;

	assert(info != NULL);
	assert(objeto != NULL);

	/* pega o nome do field */
	index = info[fieldref].info.fieldref_info.name_and_type_index;
	name = get_utf8_string(info, info[index].info.name_and_type_info.name_index);

	/* percorre hierarquia */
	while (obj != NULL) {
		classe = get_heap_element(obj->nome_qualificado);
		index = get_field_index(classe->classe, name);
		if (index < classe->classe->fields_count) {
			obj->field[index] = valor;
			return;
		} else {
			obj = obj->super;
		}
	}

#ifdef DEBUG
	printf("Não achou fielref\n");
#endif
}

u2 get_field_index(ClassFile *class_file, u1 *field_name) {
	cp_info *info;
	int i;
	
	assert(class_file != NULL);

	info = class_file->constant_pool;

	for (i = 0; i < class_file->fields_count; i++) {
		u1 *name_tmp = get_utf8_string(info, class_file->fields[i].name_index);
		if (strcmp((char *) field_name, (char *) name_tmp) == 0) {
			break;
		}
	}
	return i;
}
