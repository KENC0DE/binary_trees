#include "binary_trees.h"

/**
 * find_ancestor - findes the ancestor of low and high.
 * @low: the lowest node of the two.
 * @high: the highest node of the two.
 *
 * Return: the ancestor.
*/
binary_tree_t *find_ancestor(const binary_tree_t *low,
	const binary_tree_t *high)
{
	if (!low || !high)
		return (NULL);
	if (low->n == high->n ||
		(low->left && low->left->n == high->n) ||
		(low->right && low->right->n == high->n))
	{
		return ((binary_tree_t *)low);
	}

	return (find_ancestor(low->parent, high));
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: fist node.
 * @second: second node.
 *
 * Return: pointer to the lowest common ancestor node of the two given nodes
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
	const binary_tree_t *second)
{
	size_t depth_1st, depth_2nd;
	const binary_tree_t *low, *high;

	if (!first || !second)
		return (NULL);

	depth_1st = binary_tree_depth(first);
	depth_2nd = binary_tree_depth(second);

	if (depth_1st > depth_2nd)
	{
		low = first;
		high = second;
	}
	else
	{
		low = second;
		high = first;
	}

	return (find_ancestor(low, high));
}

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
