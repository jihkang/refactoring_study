#include "types.h"
#include <stdlib.h>
#include <stdio.h>

void	list_destroy(t_list *lst)
{
	free(lst);
	lst = NULL;
}

void	list_clear_content(t_list *lst)
{
	if (lst->content)
	{
		free(lst->content);
		lst->content = NULL;
	}
}

void	list_clear(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		list_destroy(tmp);
	}
}

void	list_print_data(t_list *lst, void (*p_func)(void *data))
{
	int	i;

	i = 0;
	while (lst)
	{
		if (lst->content)
			p_func(lst->content);
		lst = lst->next;
		++i;
	}
}
