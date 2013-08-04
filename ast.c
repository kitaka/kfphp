#include "ast.h"

struct kf_ast *kf_ast_init(const char *code)
{
  	struct kf_ast *ast = calloc(1, sizeof(struct kf_ast *));

	ast->code = strdup(code);
	ast->parent = kf_ast_node_init();

	return ast;
}

void kf_ast_free(struct kf_ast *ast)
{
  	free(ast->code);
	free(ast->parent);
  	free(ast);
}

struct kf_ast_node *kf_ast_node_init()
{
  	struct kf_ast_node *node = calloc(1, sizeof(struct kf_ast_node));

	return node;
}

void kf_ast_node_free(struct kf_ast_node *node)
{
  	free(node->value);
	free(node);
}

void kf_remove_spaces(char *str, char *result)
{
  	int i, j, len = (int)strlen(str);

	for (i = 0, j = 0; i < len; i++) {
		if (str[i] != ' ') {
		  	result[j] = str[i];
			j++;
		}	  
	}

	result[j] = '\0';
}

void kf_strchrrep(char *str, char *result, char old, char new)
{
  	int i, j;
  	ssize_t len = strlen(str);

	for (i = 0, j = 0; i < len; i++) {
		if (str[i] == old) result[j++] = new;
		else result[j++] = str[i];
	}

	result[j] = '\0';
}
  
void kf_ast_interpret(struct kf_ast *ast)
{
  	char *pos;
	char *code_copy, *to_free;

       	to_free = code_copy = malloc(100 * sizeof(char));

	kf_remove_spaces(ast->code, code_copy);

	pos = strchr(code_copy, '=');
	if (pos != NULL) {
		ast->parent->type = VariableNodeType;
		ast->parent->value = strsep(&code_copy, "=");
	}

	free(to_free);
}
