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
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if not perfect or 0 if not or tree is null
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!binary_tree_balance(tree) && binary_tree_is_full(tree))
		return (1);
	return (0);
}
