#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "binary_tree.h"

void main()
{
	char			c;
	int				n;
	tree_pointer	t;

	t = build_simple_tree();

	printf("************* Command ************\n");
	printf("C: Count tree, A: Sum tree data    \n");
	printf("H: Heigh of tree, S: Show preorder \n");
	printf("F: Free tree, Q: Quit              \n");
	printf("**********************************\n");

	while (1) {
		printf("\nCommand> ");
		c = getch();
		//getch();
		putch(c);
		c = toupper(c);

		switch (c) {
		case 'C':
			n = bt_count(t);
			printf("\n Total number of node = %d \n", n);
			break;
		case 'A':
			n = bt_sum(t);
			printf("\n Sum of tree data = %d \n", n);
			break;
		case 'H':
			n = bt_height(t);
			printf("\n Height of tree = %d \n", n);
			break;
		case 'S':
			printf("\n");
			bt_show_preorder(t);
			printf("\n");
			break;
		case 'F':
			printf("\n");
			free_bt(t);
			printf("\n");
			break;
		case 'Q':
			printf("\n");
			exit(1);
		default: break;
		}
	}
}

tree_pointer build_simple_tree()
{
	tree_pointer n1 = (tree_pointer)malloc(sizeof(tree_node));
	tree_pointer n2 = (tree_pointer)malloc(sizeof(tree_node));
	tree_pointer n3 = (tree_pointer)malloc(sizeof(tree_node));
	tree_pointer n4 = (tree_pointer)malloc(sizeof(tree_node));
	tree_pointer n5 = (tree_pointer)malloc(sizeof(tree_node));
	tree_pointer n6 = (tree_pointer)malloc(sizeof(tree_node));
	tree_pointer n7 = (tree_pointer)malloc(sizeof(tree_node));

	n1->data = 10;
	n1->left = n2;
	n1->right = n3;

	n2->data = 20;
	n2->left = n4;
	n2->right = n5;

	n3->data = 30;
	n3->left = n6;
	n3->right = n7;

	n4->data = 40;
	n4->left = NULL;
	n4->right = NULL;

	n5->data = 50;
	n5->left = NULL;
	n5->right = NULL;

	n6->data = 60;
	n6->left = NULL;
	n6->right = NULL;

	n7->data = 70;
	n7->left = NULL;
	n7->right = NULL;

	return n1;
}

int bt_count(tree_pointer ptr)
{
	if (ptr == NULL)
		return 0;

	return (1 + bt_count(ptr->left) + (bt_count(ptr->right)));
}

int bt_sum(tree_pointer ptr)
{
	if (ptr == NULL)
		return 0;
	return ptr->data + bt_sum(ptr->right) + bt_sum(ptr->left);
}

int bt_height(tree_pointer ptr)
{
	if (ptr == NULL)
		return 0;

	int left_height = bt_height(ptr->left) + 1;
	int right_height = bt_height(ptr->right) + 1;

	return MAX(left_height, right_height);
}

int MAX(int i, int j)
{
	if (i >= j) return i;
	else return j;
}

void bt_show_preorder(tree_pointer ptr)
{
	if (ptr)
	{
		printf("%d ", ptr->data);
		bt_show_preorder(ptr->left);
		bt_show_preorder(ptr->right);
	}
}

void free_bt(tree_pointer ptr)
{
	if (ptr)
	{
		free_bt(ptr->left);
		free_bt(ptr->right);
		printf("free node with item %d ...\n", ptr->data);
		free(ptr);
	}
}