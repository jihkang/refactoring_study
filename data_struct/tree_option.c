#include "types.h"
#include <stdio.h>

void	tree_preorder(t_tree *tree, void (*p_func)(t_tree *))
{
	if (tree)
	{
		p_func(tree);
		tree_preorder(tree->left, p_func);
		tree_preorder(tree->right, p_func);
	}
}

void	tree_postorder(t_tree *tree, void (*p_func)(t_tree *))
{
	if (tree)
	{
		tree_postorder(tree->left, p_func);
		tree_postorder(tree->right, p_func);
		p_func(tree);
	}
}

void	tree_inorder(t_tree *tree, void (*p_func)(t_tree *))
{
	if (tree)
	{
		tree_inorder(tree->left, p_func);
		p_func(tree);
		tree_inorder(tree->right, p_func);
	}
}

void	tree_print_data(t_tree *tree)
{
	if (!tree)
		return ;
	printf("key : %d\n", tree->key);
	printf("value : %s\n", (char *)tree->content);
}
