#include "parser.h"

struct kf_parser *kf_parser_init(struct kf_ast *ast)
{
  	struct kf_parser *parser = calloc(1, sizeof(struct kf_parser));

	parser->ast = ast;

	return parser;
}

void kf_parser_free(struct kf_parser *parser)
{
  	kf_ast_free(parser->ast);
	free(parser);
}

struct kf_var *kf_parser_var(struct kf_parser *parser, const char *var_name)
{
  	struct kf_var *var = calloc(1, sizeof(struct kf_var));

	return var;
}


struct kf_symbols *kf_symbols_init()
{
  	struct kf_symbols *symbols = calloc(1, sizeof(struct kf_symbols));

	return symbols;
}

void kf_symbols_free(struct kf_symbols *symbols)
{
  	free(symbols->key);
  	free(symbols);
}

int kf_symbols_add(struct kf_symbols *symbols, char *key, struct kf_var *var)
{
  	if (symbols == NULL) return -1;
	if (symbols->head == NULL) symbols->head = symbols;

	if (symbols->head->key != NULL) {
	  	symbols->head->next = kf_symbols_init();
		symbols->head = symbols->next;
	}

	symbols->head->key = key;
	symbols->head->var = var;

	return 0;
}

struct kf_var *kf_symbols_find(struct kf_symbols *symbols, char *key)
{
  	if (symbols == NULL) return NULL;

	if (strcmp(symbols->key, key) == 0) return symbols->var;

  	if (symbols->next == NULL) return NULL;
	kf_symbols_find(symbols->next, key);

	return NULL;
}


