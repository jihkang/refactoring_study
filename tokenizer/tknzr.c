#include <stdio.h>
#include <stdlib.h>
#include "token.h"

void	tknzr(t_link_lst *lnk, char *line)
{
	int		i;
	t_token	*tkn;

	i = 0;
	while (line[i])
	{
		while (line[i] == ' ')
			++i;
		tkn = token_malloc();
		link_push_back(lnk, tkn);
		if (token_parser_brakets(line, &i, tkn))
			continue ;
		if (token_parser_redir(line, &i, tkn))
			continue ;
		if (token_parser_pipe(line, &i, tkn))
			continue ;
		if (token_parser_and(line, &i, tkn))
			continue ;
		if (token_parser_cmd(line, &i, tkn))
			continue ;
		++i;
	}
}
/*	tknzr_test	*/
void	tknzr_test()
{
	t_link_lst	*lnk;
	char		*line = "asa<sdfff>asdf'qwerrrrr(qwer)'|&&(asdf)";

	lnk = link_malloc();
	tknzr(lnk, line);
	link_print_data(lnk, token_print);
}
