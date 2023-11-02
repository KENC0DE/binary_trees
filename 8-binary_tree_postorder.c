#include "binary_trees.h"

/**
 * binary_tree_postorder - goes through a binary tree using postorder traversal
 * @tree: the tree to be searched.
 * @func: function pointer.
 *
 * Return: Nothing.
*/
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
