#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: pointer to the node to find the uncle
 *
 * Return: pointer to the uncle node.
*/
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *child_parent, *uncle_parent;

	if (!node)
		return (NULL);

	child_parent = node->parent;
	if (child_parent)
		uncle_parent = child_parent->parent;
	else
		return (NULL);

	if (!uncle_parent || !uncle_parent->left || !uncle_parent->right)
		return (NULL);

	if (uncle_parent->right->n == child_parent->n)
		return (uncle_parent->left);
	return (uncle_parent->right);
}
