#include "types.h"

t_list	*list_pop_front(t_list *lst)
{
	t_list	*tmp;

	tmp = lst->next;
	safety_free(&(lst->value));
	safety_free(&(lst->type));
	safety_free(&(lst));
	tmp->prev = NULL;
	return (tmp);
}
