#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: the tree.
 *
 * Return: number of nodes with at least one child.
*/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return ((tree->left || tree->right ? 1 : 0) +
		 binary_tree_nodes(tree->left) +
		 binary_tree_nodes(tree->right));
}
