#ifndef LINKED_LIST_H
# define LINKED_LIST_H

#include "list.h"

typedef struct s_link_lst	t_link_lst;
typedef struct s_list		t_list;

t_link_lst	*link_malloc();
void		link_create(t_link_lst *link, t_list *head, t_list *tail);
void		link_destroy(t_link_lst *link);
void		link_push_back(t_link_lst *link, void *data);
void		link_push_front(t_link_lst *link, void *data);
void		link_print_data(t_link_lst *link, void (*p_func)(void *data));
void		link_set_data(t_link_lst *link, void *data);
t_list		*get_head(t_link_lst *link);
void		pop_front(t_link_lst *lnk);

#endif
