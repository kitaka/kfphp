#ifndef __AST_HEADER__
#define __AST_HEADER__

#include <stdlib.h>
#include <string.h>

enum kf_node_type {VariableNodeType, ValueNodeType}; 

struct kf_ast_node {
  	enum kf_node_type type;
	char *value;
	struct kf_list *children;
};

struct kf_ast {
  	char *code;
	struct kf_ast_node *parent;
};

struct kf_ast *kf_ast_init(const char *code);
void kf_ast_free(struct kf_ast *ast);
void kf_ast_interpret(struct kf_ast *ast);
void kf_remove_spaces(char *str, char *result);

struct kf_ast_node *kf_ast_node_init();
void kf_ast_node_free();

#endif
