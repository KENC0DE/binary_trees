#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: the tree to be measured.
 *
 * Return: the height of the tree.
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left = 1, right = 1;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (0);

	left += binary_tree_height(tree->left);
	right += binary_tree_height(tree->right);

	return ((left > right) ? left : right);
}
