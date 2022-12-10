#include "types.h"

t_ast	*ast_malloc(void)
{
	t_ast	*ast;

	ast = (t_ast *)malloc(sizeof(t_ast));
	ast->body = list_malloc();
	return (ast);
}

