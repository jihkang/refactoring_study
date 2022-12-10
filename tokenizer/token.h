#ifndef TOKEN_H
#define TOKEN_H

#include "linked_list.h"
#include "tree.h"
#include "utils.h"

typedef int	t_bool;

typedef struct s_token
{
	char	*type;
	char	*value;
}t_token;


/*		token.c			*/
t_token	*token_malloc(void);
void	token_set(t_token *tkn, char *type, char *value);
void	token_print(void *data);
void	token_clear(t_token *tkn);
/*		tknzr_option.c	*/
int		ft_correct_input_ascii(char c);
/*		tknzr_utils.c	*/
int		token_parser_brakets(char *line, int *i, t_token *tkn);
int		token_parser_redir(char *line, int *i, t_token *tkn);
int		token_parser_pipe(char *line, int *i, t_token *tkn);
int		token_parser_and(char *line, int *i, t_token *tkn);
int		token_parser_cmd(char *line, int *i, t_token *tkn);
/*		tknzr.c			*/

#endif
