#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree.
 * @tree: nood to be measured.
 *
 * Return: Depth measured.
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 1;

	if (!tree)
		return (0);
	if (!tree->parent)
		return (0);

	depth += binary_tree_depth(tree->parent);

	return (depth);
}
