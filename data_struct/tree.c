#include "types.h"
#include <stdlib.h>

t_tree	*tree_malloc(void)
{
	t_tree	*tree;

	tree = (t_tree *)malloc(sizeof(t_tree));
	tree->left = NULL;
	tree->right = NULL;
	tree->key = INIT;
	return (tree);
}

void	tree_destroy(t_tree *tree)
{
	free(tree);
}

void	tree_create(t_tree *tree, int key, void *data)
{
	tree->key = key;
	tree->content = data;
}

t_tree	*tree_insert(t_tree *tree, int key, void *data)
{
	if (tree == NULL)
	{
		tree = tree_malloc();
		tree_create(tree, key, data);
		return (tree);
	}
	if (key < tree->key)
		tree->left = tree_insert(tree->left, key, data);
	else if (key >= tree->key)
		tree->right = tree_insert(tree->right, key, data);
	return (tree);
}

void	tree_clear(t_tree *tree)
{
	if (tree)
	{
		tree_clear(tree->left);
		tree_clear(tree->right);
		tree_destroy(tree);
		tree = NULL;
	}
}
