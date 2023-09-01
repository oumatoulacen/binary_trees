#include "binary_trees.h"

/**
 * bst_find_min - Finds the node with the minimum value in a BST.
 * @node: A pointer to the root node of the subtree to search.
 * Return: A pointer to the node with the minimum value.
 */

bst_t *bst_find_min(bst_t *node)
{
	while (node->left != NULL)
		node = node->left;
	return (node);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree (BST).
 * @root: A pointer to the root node of the tree.
 * @value: The value to remove from the tree.
 * Return: A pointer to the new root node of the tree after removal.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *min_successor, *temp, *tmp;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			tmp = root->left;
			free(root);
			return (tmp);
		}

		min_successor = bst_find_min(root->right);
		root->n = min_successor->n;
		root->right = bst_remove(root->right, min_successor->n);
	}
	return (root);
}
