#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: a pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *node;

	if (!tree)
		return (NULL);
	node = tree->left;
	tree->left = node->right;
	if (node->right)
		node->parent->parent = tree;
	node->right = tree;
	node->parent = tree->parent;
	tree->parent = node;
	return (node);
}
