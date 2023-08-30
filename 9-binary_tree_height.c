#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree:  a pointer to the root node of the tree to measure the height.
 * Return: height of a tree or 0 If tree is NULL.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_r, height_l;

	if (!tree)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (0);
	height_r = 1 + binary_tree_height(tree->right);
	height_l = 1 + binary_tree_height(tree->left);

	return (height_r > height_l ? height_r : height_l);
}
