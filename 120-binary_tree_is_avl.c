#include "binary_trees.h"
#include <limits.h>

int btib_helper(const binary_tree_t *tree, int min, int max);

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
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST
 *         0 otherwise
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (btib_helper(tree, INT_MIN, INT_MAX));
}

/**
 * btib_helper - checks if a binary tree is a valid Binary Search Tree
 * @tree: a pointer to the root node of the tree to check
 * @min: Lower bound of checked nored
 * @max: Upper bound of checked nodes
 *
 * Return: 1 if tree is a valid BST
 *         0 otherwise
 */

int btib_helper(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (btib_helper(tree->left, min, tree->n - 1) &&
		btib_helper(tree->right, tree->n + 1, max));
}
/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree:  a pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise or If tree is NULL
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	int a;
	int height;

	if (!tree)
		return (0);
	a = binary_tree_is_bst((const binary_tree_t *)tree);
	height = binary_tree_height(tree->left) - binary_tree_height(tree->right);
	if (a && height > -1 && height < 2)
		return (1);
	return (0);
}
