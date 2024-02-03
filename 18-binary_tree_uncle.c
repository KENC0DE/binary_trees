#include "binary_trees.h"
/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: a binary tree node
 *
 * Return: pointer to the uncle of a node
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *grand_parent;

	if (!node || !node->parent || !node->parent->parent)
		return (NULL);

	grand_parent = node->parent->parent;

	if (!grand_parent->left || !grand_parent->right)
		return (NULL);

	return (grand_parent->left == node->parent ?
		grand_parent->right : grand_parent->left);
}
