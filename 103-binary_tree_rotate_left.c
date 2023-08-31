#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: a pointer to the root node of the tree to rotate
 * Return: er to the new root node of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *node;

	if (!tree)
		return (NULL);
	node = tree->right;
	tree->right = node->left;
	if (node->left)
		node->left->parent = tree;
	node->left = tree;
	node->parent = tree->parent;
	tree->parent = node;
	return (node);
}
