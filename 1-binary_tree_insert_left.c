#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: a pointer to the node to insert the left-child in
 * @value: the value to store in the new node
 * Return: a pointer to the created node, or NULL on
 * failure or if parent is NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node, *left;

	if (!parent)
		return (NULL);
	if (!parent->left)
	{
		node = (binary_tree_t *) malloc(sizeof(binary_tree_t));
		if (!node)
			return (NULL);
		node->n = value;
		node->parent = parent;
		node->left = NULL;
		node->right = NULL;
		parent->left = node;
		return (node);
	}
	else
	{
		left = parent->left;
		node = (binary_tree_t *) malloc(sizeof(binary_tree_t));
		if (!node)
			return (NULL);
		node->n = value;
		node->left = left;
		left->parent = node;
		node->right = NULL;
		node->parent = parent;
		parent->left = node;
		return (node);
	}
}
