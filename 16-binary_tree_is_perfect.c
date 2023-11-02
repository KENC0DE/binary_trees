#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: perfect 1, otherwise 0.
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int full;
	size_t l_ht, r_ht;

	if (!tree)
		return (0);

	full = binary_tree_is_full(tree);
	l_ht = binary_tree_height(tree->left);
	r_ht = binary_tree_height(tree->right);

	return ((l_ht == r_ht) && full);
}

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

	left += binary_tree_height(tree->left);
	right += binary_tree_height(tree->right);

	return ((left > right) ? left : right);
}
