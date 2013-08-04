#include "tests.h"


void test_that_interpreter_can_add_two_numbers()
{
  	const char *code = "$x = 1 + 2;";
	struct kf_ast *ast;
	struct kf_parser *parser;
	struct kf_var *var;

	ast = (struct kf_ast *)kf_ast_init(code);
	kf_ast_interpret(ast);

	parser = (struct kf_parser *)kf_parser_init(ast);
	var = kf_parser_var(parser, "x");

	assert(var->intvar == 3);
}

void test_that_value_can_be_added_to_symbols()
{
  	struct kf_symbols *symbols;
	struct kf_var var;
	struct kf_symbols *result;

	symbols = kf_symbols_init();
	var.intvar = 33;

	kf_symbols_add(symbols, "x", &var);
	result = kf_symbols_find(symbols, "x");

	assert((result != NULL) && result->var->intvar == var.intvar);
}

void debug(const char *str)
{
  	printf("[%s]\n", str);
}

void test_that_code_can_be_interpreted_into_ast()
{
  	const char *code = "$x = 1 + 2;";
  	struct kf_ast *ast;

	ast = (struct kf_ast *)kf_ast_init(code);
	kf_ast_interpret(ast);

	assert((ast->parent != NULL) && ast->parent->type == VariableNodeType);
	assert((ast->parent != NULL && ast->parent->value != NULL) && (strcmp(ast->parent->value, "$x") == 0));

}

void test_that_can_remove_spaces()
{
	char text[100] = "$x = 1 + 2 ;";
	char result[100];
	kf_remove_spaces(text, result);
	
	assert(strcmp(result, "$x=1+2;") == 0);	
}

void tests_run() 
{
  	test_that_code_can_be_interpreted_into_ast();
	test_that_can_remove_spaces();
	test_that_interpreter_can_add_two_numbers();
	test_that_value_can_be_added_to_symbols();
}
