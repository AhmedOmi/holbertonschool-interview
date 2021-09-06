#include "binary_trees.h"

/**
 * ls - check if contains only values less than n
 * @tree: tree
 * @n: value
 * @F: flag 1 or 0
 * Return: 1 if true, otherwise 0
 *
 */

int ls(int n, const binary_tree_t *tree, int F)
{
	int R_L = 1, R_R = 1;

	if (tree->left)
		R_L = ls(n, tree->left, F);
	if (tree->right)
		R_R = ls(n, tree->right, F);

	if (F && tree->n >= n)
		return (0);
	else if (!F && tree->n <= n)
		return (0);

	return (R_L * R_R);
}
/**
 * bntr_bst - check is Binary search tree
 * @tree: tree
 * Return: 1 if true, otherwise 0
 */
int bntr_bst(const binary_tree_t *tree)
{
	int R_L = 1, R_R = 1;

	if (!tree)
		return (0);

	if (tree->left)
	{
		if (!ls(tree->n, tree->left, 1))
			return (0);
		R_L = bntr_bst(tree->left);
	}
	else
		return (1);

	if (tree->right)
	{
		if (!ls(tree->n, tree->right, 0))
			return (0);
		R_R = bntr_bst(tree->right);
	}
	else
		return (1);

	return (R_R * R_L);
}

/**
 * height -  calculate the height of the tree
 * @tree: tree
 * Return: the height of the tree
 */

size_t height(const binary_tree_t *tree)
{
	size_t height_left = 0, height_right = 0;

	if (tree->left)
		height_left = height(tree->left);
	if (tree->right)
		height_right = height(tree->right);
	return ((height_left > height_right) ? height_left + 1 : height_right + 1);
}

/**
 * balance_bn - calculate the balance of the tree
 * @tree: tree
 * Return: the height, 0  otherwise
 */
int balance_bn(const binary_tree_t *tree)
{
	int lt = 0, rt = 0;

	if (tree)
	{
		if (tree->left)
			lt = height(tree->left);
		if (tree->right)
			rt = height(tree->right);
		return (lt - rt);
	}
	else
		return (0);
}

/**
 * binary_tree_is_avl - check if a binary tree is a valid AVLTree
 * @tree: tree
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int left = 1, right = 1;

	if (!tree)
		return (0);
	if (!bntr_bst(tree))
		return (0);
	if (balance_bn(tree) != 1 && balance_bn(tree) != 0 && balance_bn(tree) != -1)
		return (0);
	if (tree->left)
		left = binary_tree_is_avl(tree->left);
	if (tree->right)
		right = binary_tree_is_avl(tree->right);

	return (left * right);
}