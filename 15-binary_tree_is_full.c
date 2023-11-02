#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: root node to be checked.
 *
 * Return: `1` for full `0` atherwise.
*/
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);

	return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
}
