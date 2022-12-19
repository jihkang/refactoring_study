#include "types.h"
#include "utils.h"

t_list	*list_pop_front(t_list *lst, void (*p_func)(void *))
{
	t_list	*tmp;

	tmp = lst->next;
	p_func(lst->content);
	safety_free((void **)&(lst));
	tmp->prev = NULL;
	return (tmp);
}
