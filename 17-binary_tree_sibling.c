#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: pointer to the node to find the sibling
 *
 * Return: pointer to sibling node.
*/
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent;

	if (!node || !node->parent)
		return (NULL);
	parent = node->parent;
	if (!parent->left || !parent->right)
		return (NULL);

	if (parent->left->n == node->n)
		return (parent->right);
	return (parent->left);
}
