#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: a pointer to the node to insert the right-child in
 * @value: the value to store in the new node
 * Return: a pointer to the created node, or NULL on
 * failure or if parent is NULL
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node, *right;

	if (!parent)
		return (NULL);
	if (!parent->right)
	{
		node = (binary_tree_t *) malloc(sizeof(binary_tree_t));
		if (!node)
			return (NULL);
		node->n = value;
		node->parent = parent;
		node->left = NULL;
		node->right = NULL;
		parent->right = node;
		return (node);
	}
	else
	{
		right = parent->right;
		node = (binary_tree_t *) malloc(sizeof(binary_tree_t));
		if (!node)
			return (NULL);
		node->n = value;
		node->left = NULL;
		right->parent = node;
		node->right = right;
		node->parent = parent;
		parent->right = node;
		return (node);
	}
}
