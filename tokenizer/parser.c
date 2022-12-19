#include "tknzr.h"
#include "ast.h"

void	node_push_back()
{

}

void	ast_push_back(t_ast *ast, t_link_lst *tkn, int *idx)
{
	int	cur;

	cur = *idx;
	*idx = cur;
}

t_ast	*tknzr_parser(t_link_lst *tkn)
{
	t_list	*cur;
	t_ast	*ast;
	int		i;

	i = 0;
	ast = ast_malloc();
	cur = get_head(tkn);
	if (cur == NULL)
		return (ast);
	while (i < link_get_length(tkn))
	{
		ast_push_back(ast, tkn, &i);
		++i;
	}
	return (ast);
}

int	main()
{
//	t_link_lst	*lnk;
//	char		*line;

//	lnk = link_malloc();
//	tknzr(lnk, line);
//	tknzr_parser(lnk);
	tknzr_test();
	return (0);
}
