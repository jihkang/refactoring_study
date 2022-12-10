#include "token.h"

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

void	token_clear(t_token *tkn)
{
	safety_free(&(tkn->type));
	safety_free(&(tkn->value));
	safety_free(&tkn);
}
