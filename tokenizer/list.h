#ifndef LIST_H
# define LIST_H

typedef struct s_list	t_list;

t_list	*list_malloc(void);
void	list_create(t_list *lst, void *data);
t_list	*list_push(t_list *lst, void *data);
t_list	*list_push_back(t_list *lst, void *data);
t_list	*list_push_front(t_list *lst, void *data);
void	list_destroy(t_list *lst);
void	list_clear(t_list *lst);
void	list_clear_content(t_list *lst);
void	list_print_data(t_list *lst, void (*p_func)(void *data));

#endif
