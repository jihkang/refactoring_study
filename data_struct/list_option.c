#include "types.h"
#include <stdlib.h>
#include <stdio.h>

void	list_destroy(t_list *lst)
{
	free(lst);
	lst = NULL;
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

void	list_print_data(t_list *lst)
{
	while (lst)
	{
		printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}
}
