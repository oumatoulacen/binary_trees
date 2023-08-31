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

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if it is full and 0 if not or tree is NULL
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (tree->left && tree->right)
		return (binary_tree_is_full(tree->left) &&
			binary_tree_is_full(tree->right));
	return (0);

}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if the tree is complete 0 otherwise or tree is NULL
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (tree->left && !tree->right && !tree->left->left)
		return (1);
	if (!tree->left && tree->right)
		return (0);
	if (tree->left->right)
	{
		if (tree->left->right->right && !tree->left->right->left)
			return (0);
	}
	return (binary_tree_is_complete(tree->left) &&
			binary_tree_is_full(tree->right) &&
			(binary_tree_height(tree->left) -
			 binary_tree_height(tree->right) < 2));
}
