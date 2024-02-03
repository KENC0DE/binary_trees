#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: a binary tree node
 *
 * Return: the sibling of a node
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent;

	if (!node || !node->parent)
		return (NULL);

	parent = node->parent;

	if (!parent->left || !parent->right)
		return (NULL);

	return (parent->left == node ? parent->right : parent->left);
}
