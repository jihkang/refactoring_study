#ifndef TREE_H
# define TREE_H

typedef struct s_tree	t_tree;

/**		tree.c		 	*/
t_tree	*tree_malloc(void);
void	tree_create(t_tree *tree, int key, void *data);
void	tree_clear(t_tree *tree);
t_tree	*tree_insert(t_tree *tree, int key, void *data);
/**		tree_option.c	*/
void	tree_preorder(t_tree *tree, void (*p_func)(t_tree *));
void	tree_postorder(t_tree *tree, void (*p_func)(t_tree *));
void	tree_inorder(t_tree *tree, void (*p_func)(t_tree *));
void	tree_print_data(t_tree *tree);

#endif
