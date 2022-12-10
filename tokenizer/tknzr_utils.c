#include "token.h"

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

