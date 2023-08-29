#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: a pointer to the parent node of the node to create
 * @value: the value to put in the new node.
 * Return: a pointer to the new node, or NULL on failure.
 */


binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (!parent)
	{
		node = (binary_tree_t *) malloc(sizeof(binary_tree_t));
		if (!node)
			return (NULL);
		node->n = value;
		node->parent = NULL;
		node->left = NULL;
		node->right = NULL;
		parent = node;
		return (parent);
	}
	if (value < parent->n)
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
	if (value > parent->n)
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
	return (NULL);
}