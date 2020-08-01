#include "binary_trees.h"

/**
 * height - measures the height of a tree
 *
 * @tree: tree root
 * Return: height
 */
int height(const binary_tree_t *tree)
{
	int left = 0;
	int right = 0;

	if (tree == NULL)
		return (-1);

	left = height(tree->left);
	right = height(tree->right);

	if (left > right)
		return (left + 1);

	return (right + 1);
}

/**
 * btree_is_perfect - checks if a binary tree is perfect
 *
 * @tree: tree root
 * Return: 1 if tree is perfect, 0 otherwise
 */
int btree_is_perfect(const binary_tree_t *tree)
{
	_Bool l_ch;
	_Bool r_ch;
	int l_per;
	int r_per;

	if (tree && height(tree->left) == height(tree->right))
	{
		if (height(tree->left) == -1)
			return (1);

		l_ch = !((tree->left)->left) && !((tree->left)->right);
		r_ch = !((tree->right)->left) && !((tree->right)->right);

		if ((tree->left && l_ch) && (tree->right && r_ch))
			return (1);

		if (tree && tree->left && tree->right)
		{
			l_per = btree_is_perfect(tree->left);
			r_per = btree_is_perfect(tree->right);
			return (l_per && r_per);
		}
	}

	return (0);
}

/**
 * swap - swaps nodes when child is greater than parent
 *
 * @arg_node: parent node
 * @arg_child: child node
 * Return: no return
 */
void swap(heap_t **arg_node, heap_t **arg_child)
{
	heap_t *node, *child, *node_child, *node_left, *node_right, *parent;
	int left_right;

	node = *arg_node, child = *arg_child;
	if (child->n > node->n)
	{
		if (child->left)
			child->left->parent = node;
		if (child->right)
			child->right->parent = node;
		if (node->left == child)
			node_child = node->right, left_right = 0;
		else
			node_child = node->left, left_right = 1;
		node_left = child->left, node_right = child->right;
		if (left_right == 0)
		{
			child->right = node_child;
			if (node_child)
				node_child->parent = child;
			child->left = node;
		}
		else
		{
			child->left = node_child;
			if (node_child)
				node_child->parent = child;
			child->right = node;
		}
		if (node->parent)
		{
			if (node->parent->left == node)
				node->parent->left = child;
			else
				node->parent->right = child;
		}
		parent = node->parent, child->parent = parent;
		node->parent = child, node->left = node_left;
		node->right = node_right, *arg_node = child;
	}
}

/**
 * heap_insert - function that inserts a value in Max Binary Heap
 * @value: value to be inserted
 * @root: tree root
 * Return: pointer to the created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new;

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	if (btree_is_perfect(*root) || !btree_is_perfect((*root)->left))
	{
		if ((*root)->left)
		{
			new = heap_insert(&((*root)->left), value);
			swap(root, &((*root)->left));
			return (new);
		}
		else
		{
			new = (*root)->left = binary_tree_node(*root, value);
			swap(root, &((*root)->left));
			return (new);
		}
	}

	if ((*root)->right)
	{
		new = heap_insert(&((*root)->right), value);
		swap(root, (&(*root)->right));
		return (new);
	}
	else
	{
		new = (*root)->right = binary_tree_node(*root, value);
		swap(root, &((*root)->right));
		return (new);
	}

	return (NULL);
}
