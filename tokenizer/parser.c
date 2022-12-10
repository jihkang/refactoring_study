#include "tknzr.h"
#include "ast.h"

void	*walk(t_ast *ast, t_link_lst *tkn)
{
	
}

t_link_lst	*tknzr_parser(t_link_lst *tkn)
{
	t_list	*cur;
	t_ast	*ast;
	int		i;

	i = 0;
	ast = ast_malloc();
	cur = get_head(tkn);
	if (cur == NULL)
		return (ast);
	while (i < tkn->len)
	{
		++i;
	}
	return (ast);
}

int	main()
{
	t_link_lst	*lnk;
	char		*line;

	lnk = link_malloc();
	tknzr(lnk, line);
	tknzr_parser(lnk);
	return (0);
}
