#include "binary_trees.h"

/**
 * binary_tree_levelorder - goes through a binary tree using
 * level-order traversal
 *
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 *
 * Return: Nothing.
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *head = malloc(sizeof(queue_t));
	queue_t *tail = NULL, *pop = NULL;

	if (!tree || !func || !head)
		return;

	head->node = (binary_tree_t *)tree;
	head->next = NULL;
	tail = pop = head;

	while (head)
	{
		func(head->node->n);
		if (head->node->left)
		{
			tail->next = malloc(sizeof(queue_t));
			if (!tail->next)
				return;
			tail = tail->next;
			tail->node = head->node->left;
			tail->next = NULL;
		}
		if (head->node->right)
		{
			tail->next = malloc(sizeof(queue_t));
			if (!tail->next)
				return;
			tail = tail->next;
			tail->node = head->node->right;
			tail->next = NULL;
		}
		head = head->next;
		free(pop);
		pop = head;
	}
}
