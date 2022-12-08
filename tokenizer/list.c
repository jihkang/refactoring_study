#include "types.h"
#include <stdlib.h>

t_list	*list_malloc(void)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	list->content = NULL;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

void	list_create(t_list *lst, void *data)
{
	lst->content = data;
}

t_list	*list_push(t_list *lst, void *data)
{
	lst = list_malloc();
	list_create(lst, data);
	return (lst);
}

t_list	*list_push_back(t_list *lst, void *data)
{
	if (lst == NULL)
		return (list_push(lst, data));
	lst->next = list_malloc();
	list_create(lst->next, data);
	lst->next->prev = lst;
	return (lst->next);
}

t_list	*list_push_front(t_list *lst, void *data)
{
	if (lst == NULL)
		return (list_push(lst, data));
	lst->prev = list_malloc();
	list_create(lst->prev, data);
	lst->prev->next = lst;
	return (lst->prev);
}
