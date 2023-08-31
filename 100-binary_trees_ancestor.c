#include "binary_trees.h"

int binary_tree_is_ancestor(const binary_tree_t *ancestor, const binary_tree_t *node);

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first:  a pointer to the first node
 * @second: a pointer to the second node
 * Return: a pointer to the lowest common ancestor node of the two given
 * nodes or NULL If no common ancestor was found
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	const binary_tree_t *ancestor;

	if (first == NULL || second == NULL)
		return (NULL);

	ancestor = first;
	while (ancestor != NULL)
	{
		if (binary_tree_is_ancestor(ancestor, second))
			return (ancestor);
		ancestor = ancestor->parent;
	}
	return (NULL);
}

/**
 * binary_tree_is_ancestor - Checks if a node is an ancestor of another node
 * @ancestor: A pointer to the potential ancestor node.
 * @node: A pointer to the node to check.
 * Return: 1 if @ancestor is an ancestor of @node, 0 otherwise.
 */

int binary_tree_is_ancestor(const binary_tree_t *ancestor, const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if (ancestor == node)
		return (1);
	return (binary_tree_is_ancestor(ancestor, node->parent));
}
