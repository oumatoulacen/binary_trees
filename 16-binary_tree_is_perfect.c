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
	if (!tree->left && !tree->right)
		return (0);
	height_r = 1 + binary_tree_height(tree->right);
	height_l = 1 + binary_tree_height(tree->left);

	return (height_r > height_l ? height_r : height_l);
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: a pointer to the root node of the tree to measure the size
 * Return: the size of a tree or 0 If tree is NULL
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (!tree)
		return (0);

	size += binary_tree_size(tree->left);
	size++;
	size += binary_tree_size(tree->right);

	return (size);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if not perfect or 0 if not or tree is null
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t size, height;

	if (!tree)
		return (0);

	size = binary_tree_size(tree);
	height = binary_tree_height(tree);

	return (size == (size_t)((1 << (height + 1)) - 1));
}
