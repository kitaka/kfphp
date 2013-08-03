#ifndef __PARSER_HEADER__
#define __PARSER_HEADER__

#include <stdlib.h>
#include "ast.h"

struct kf_parser {
  	struct kf_ast *ast;
};

struct kf_var {
  	int intvar;
};

struct kf_symbols {
  	char *key;
	struct kf_var *var;
	struct kf_symbols *head;
	struct kf_symbols *next;
};

struct kf_parser *kf_parser_init(struct kf_ast *ast);
void kf_parser_free(struct kf_parser *parser);
struct kf_var *kf_parser_var(struct kf_parser *parser, const char *var_name);

struct kf_symbols *kf_symbols_init();
void kf_symbols_free(struct kf_symbols *symbols);
int kf_symbols_add(struct kf_symbols *symbols, char *key, struct kf_var *var);
struct kf_var *kf_symbols_find(struct kf_symbols *symbols, char *key);

#endif
