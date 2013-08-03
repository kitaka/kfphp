#include "ast.h"

struct kf_ast *kf_ast_init(const char *code)
{
  	struct kf_ast *ast = calloc(1, sizeof(struct kf_ast *));

	ast->code = strdup(code);

	return ast;
}

void kf_ast_free(struct kf_ast *ast)
{
  	free(ast->code);
  	free(ast);
}

void kf_ast_interpret(struct kf_ast *ast)
{
}
