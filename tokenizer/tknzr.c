#include "linked_list.h"
#include "list.h"
#include "token.h"
#include <stdio.h>
#include <stdlib.h>

t_token	*token_malloc(void)
{
	t_token	*tkn;

	tkn = (t_token *)malloc(sizeof(t_token));
	tkn->type = NULL;
	tkn->value = NULL;
	return (tkn);
}

void	token_set(t_token *tkn, char *type, char *value)
{
	tkn->type = type;
	tkn->value = value;
}

void	token_print(void *data)
{
	t_token	*tkn;

	tkn = data;
	printf("type : %s\n", tkn->type);
	printf("value : %s\n", tkn->value);
	printf("\n\n");
}

int	ft_correct_input_ascii(char c)
{
	return ((c >= 'a' && c <= 'z') || \
			(c >= 'A' && c <= 'Z') || \
			(c == '\'' || c == '\"' || c == '$'));
}

int	token_parser_brakets(char *line, int *i, t_token *tkn)
{
	if (line[*i] == '(')
	{
		tkn->type = ft_strdup("paren");
		tkn->value = ft_strdup("(");
		++(*i);
		return (1);
	}
	if (line[*i] == ')')
	{
		tkn->type = ft_strdup("paren");
		tkn->value = ft_strdup(")");
		++(*i);
		return (1);
	}
	return (0);
}

int	token_parser_redir(char *line, int *i, t_token *tkn)
{
	int	j;

	if (line[*i] == '<')
	{
		tkn->type = ft_strdup("redir");
		j = *i;
		while (line[j] == '<')
			j++;
		tkn->value = ft_substr(line, *i, j);
		*i = j;
		return (1);
	}
	if (line[*i] == '>')
	{
		tkn->type = ft_strdup("redir");
		j = *i;
		while (line[j] == '>')
			++j;
		tkn->value = ft_substr(line, *i, j);
		*i = j;
		return (1);
	}
	return (0);
}

int	token_parser_pipe(char *line, int *i, t_token *tkn)
{
	int	j;

	if (line[*i] == '|')
	{
		j = *i + 1;
		if (line[j] == line[*i])
			tkn->type = ft_strdup("or");
		else
			tkn->type = ft_strdup("pipe");
		while (line[j] == '|')
				++j;
		tkn->value = ft_substr(line, *i, j);
		*i = j;
		return (1);
	}
	return (0);
}

int	token_parser_and(char *line, int *i, t_token *tkn)
{
	int	j;

	if (line[*i] == '&')
	{
		j = *i + 1;
		if (line[*i] == line[j])
			tkn->type = ft_strdup("and");
		else
			tkn->type = ft_strdup("bits");
		while (line[j] == '&')
			++j;
		tkn->value = ft_substr(line, *i, j);
		(*i) = j;
		return (1);
	}
	return (0);
}

int	token_parser_cmd(char *line, int *i, t_token *tkn)
{
	int	j;
	int	flag;

	flag = 0;
	if (ft_correct_input_ascii(line[*i]))
	{
		j = *i;
		flag = 0;
		while (ft_correct_input_ascii(line[j]) || flag)
		{
			if (line[j] == '\'' || line[j] == '\"')
				flag = !flag;
			++j;
		}
		tkn->type = ft_strdup("cmd");
		tkn->value = ft_substr(line, *i, j);
		*i = j;
		if (flag == 0)
			return (-1);
		return (1);
	}
	return (0);
}

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

int	main()
{
	t_link_lst	*lnk;
	char		*line = "asa<sdfff>asdf'qwerrrrr(qwer)'|&&(asdf)";

	lnk = link_malloc();
	tknzr(lnk, line);
	link_print_data(lnk, token_print);
	return (0);
}
