#include "types.h"
#include "list.h"
#include <stdlib.h>
#include <stdio.h>

t_link_lst	*link_malloc()
{
	t_link_lst	*link;

	link = (t_link_lst *)malloc(sizeof(t_link_lst));
	link->head = NULL;
	link->tail = NULL;
	return (link);
}

void	link_destroy(t_link_lst *link)
{
	list_clear(link->head);
	free(link);
}

void	link_create(t_link_lst *link, t_list *head, t_list *tail)
{
	link->head = head;
	link->tail = tail;
}

void	link_push_back(t_link_lst *link, void *data)
{
	link->tail = list_push_back(link->tail, data);
	if (link->head == NULL)
		link_create(link, link->tail, link->tail);
}

void	link_push_front(t_link_lst *link, void *data)
{
	link->head = list_push_front(link->head, data);
	if (link->tail == NULL)
		link_create(link, link->head, link->head);
}
