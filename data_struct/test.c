#include "tree.h"
#include "linked_list.h"
#include <stdio.h>

void	test()
{
	t_link_lst	*link;

	link = link_malloc();
	link_push_back(link, "MALLANG");
	link_push_back(link, "COOGI");	
	link_push_back(link, "IS");
	link_push_back(link, "DIED!");
	link_push_front(link, "HOHO");
	link_print_data(link);
	link_destroy(link);
	t_tree	*tree;
	tree = tree_insert(tree = NULL, 15, "TREE");
	tree_insert(tree, 20, "RIGHT");
	tree_insert(tree, 10, "LEFT");
	tree_insert(tree, 13, "LEFT-RIGHT");
	printf("preorder\n");
	tree_preorder(tree, tree_print_data);
	printf("inorder\n");
	tree_inorder(tree, tree_print_data);
	printf("postorder\n");
	tree_postorder(tree, tree_print_data);
}

int main()
{
	test();
}
