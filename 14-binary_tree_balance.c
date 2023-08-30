#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree + 1
 * @tree:  a pointer to the root node of the tree to measure the height.
 * Return: height + 1 of a tree or 0 If tree is NULL.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_r, height_l;

	if (!tree)
		return (0);

	height_r = 1 + binary_tree_height(tree->right);
	height_l = 1 + binary_tree_height(tree->left);

	return (height_r > height_l ? height_r : height_l);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree:  a pointer to the root node of the tree to
 * measure the balance factor
 * Return: the balance factor of a tree or 0 If tree is NULL
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int height_r, height_l;

	if (!tree)
		return (0);

	height_r = 1 + binary_tree_height(tree->right);
	height_l = 1 + binary_tree_height(tree->left);

	return (height_l - height_r);
}
