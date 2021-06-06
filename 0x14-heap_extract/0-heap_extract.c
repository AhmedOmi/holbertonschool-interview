#include <stdio.h>
#include "binary_trees.h"

/**
 * length - length of the tree
 * @root: first element.
 * Return: the length of the tree
 **/
int length(heap_t *root)
{
	int left = 0;
	int right = 0;

	if (root == NULL)
		return (0);

	left = length(root->left);
	right = length(root->right);

	if (left > right)
		return (left + 1);
	else
		return (right + 1);
}

/**
 * leaf - last element
 * @root: first element
 * Return: last element
 **/
heap_t *leaf(heap_t *root)
{
	if (root == NULL)
		return (NULL);
	if (!root->right && !root->left)
		return (root);

	if (length(root->left) > length(root->right))
		return (leaf(root->left));
	if (length(root->right) > length(root->left))
		return (leaf(root->right));
	return (leaf(root->right));
}
/**
 * sn - swap nodes
 * @parent: first
 * @child: second
 **/
void sn(heap_t *parent, heap_t *child)
{
	int tmp = child->n;

	child->n = parent->n;
	parent->n = tmp;
}
/**
 * sd - fix
 * @parent: first
 **/
void sd(heap_t **parent)
{
	heap_t *target = (*parent);

	while ((target->left && target->n < target->left->n) ||
			(target->right && target->n < target->right->n))
	{
		if (target->right && target->left)
			target = target->left->n > target->right->n ? target->left : target->right;
		if (target->right && target->right->n > target->n)
			target = target->right;
		else if (target->left && target->left->n > target->n)
			target = target->left;

		sn(target->parent, target);
	}
}
/**
 * heap_extract - extract tree
 * @root: first
 * Return: parameter
 **/
int heap_extract(heap_t **root)
{
	heap_t *l, *tmp;
	int val;

	if ((*root) == NULL)
		return (0);

	val = (*root)->n;
	if (!(*root)->left && !(*root)->right)
	{
		free((*root));
		*root = NULL;
		return (val);
	}
	l = leaf((*root));

	if (l == NULL)
		return (0);
	tmp = (*root);
	if (tmp->left)
	{
		tmp->left->parent = l;
		l->left = tmp->left;
	}
	if (tmp->right)
	{
		tmp->right->parent = l;
		l->right = tmp->right;
	}
	if (l->parent->left && l->parent->left == l)
		l->parent->left = NULL;
	else if (l->parent->right && l->parent->right == l)
		l->parent->right = NULL;

	l->parent = tmp->parent;
	(*root) = l;

	free(tmp);
	sd(root);

	return (val);
}
