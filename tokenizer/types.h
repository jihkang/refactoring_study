#ifndef TYPES_H
# define TYPES_H

typedef enum e_types
{
	INIT = -1,
	DATA,
	NODE,
	TREE,
	LIST,
}t_types;

typedef int	t_bool;

typedef struct s_tree
{
	int				key;	
	struct s_tree	*left;
	struct s_tree	*right;
	void			*content;
}t_tree;

typedef struct s_list
{
	struct s_list	*next;
	struct s_list	*prev;
	void			*content;
}t_list;

typedef struct s_link_lst
{
	t_list	*head;
	t_list	*tail;
	int		len;
}t_link_lst;

typedef struct s_ast
{
	char		*type;
	char		*value;
	t_link_lst	*body;
}t_ast;

#endif
