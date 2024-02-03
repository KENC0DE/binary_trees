#include "binary_trees.h"

/**
 * binary_tree_height - calculates the height of a tree
 * @tree: a binary tree
 *
 * Return: the height of a tree
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

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of a binary tree
 *
 * Return: 1 if perfect, else 0
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (!tree)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (!tree->left && !tree->right)
		return (1);

	return (binary_tree_is_perfect(tree->left) && binary_tree_is_perfect(tree->right) && left_height == right_height);
}
