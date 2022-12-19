#include "types.h"
#include "list.h"
#include <stdio.h>

void	link_print_data(t_link_lst *link, void (*p_func)(void *))
{
	printf("linked list run\n");
	list_print_data(link->head, p_func);
}

void	link_set_data(t_link_lst *link, void *data)
{
	list_clear_content(link->tail);
	list_create(link->tail, data);
}

t_list	*get_head(t_link_lst *lnk)
{
	return (lnk->head);
}

int	link_get_length(t_link_lst *lnk)
{
	return (lnk->len);
}

void	pop_front(t_link_lst *lnk, void (*p_func)(void *))
{
	if (lnk->len == 0)
		return ;
	lnk->head = list_pop_front(lnk->head, p_func);
	lnk->len--;
	if (lnk->len == 0)
		lnk->tail = NULL;
}
