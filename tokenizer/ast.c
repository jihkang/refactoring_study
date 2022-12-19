#include "types.h"
#include <stdlib.h>

t_ast	*ast_malloc(void)
{
	t_ast	*ast;

	ast = (t_ast *)malloc(sizeof(t_ast));
	return (ast);
}

