#ifndef __AST_HEADER__
#define __AST_HEADER__

#include <stdlib.h>
#include <string.h>

struct kf_ast {
  	char *code;
};

struct kf_ast *kf_ast_init(const char *code);
void kf_ast_free(struct kf_ast *ast);
void kf_ast_interpret(struct kf_ast *ast);

#endif
