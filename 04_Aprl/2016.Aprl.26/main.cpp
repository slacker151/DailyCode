#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <iomanip>

typedef struct Node
{
	Node(int);

	int data;
	Node *left;
	Node *right;
}Node;

Node::Node(int d)
	: data(d)
	, left(NULL)
	, right(NULL)
{}

Node* lca_recursive(Node *root, int child1, int child2)
{
	if(root->data >= child1 && root->data >= child2)
	{
		return lca_recursive(root->left, child1, child2);
	}
	else if(root->data < child1 && root->data < child2)
	{
		return lca_recursive(root->right, child1, child2);
	}
	else
	{
		return root;
	}
}

Node* lca_iterative(Node *root, int child1, int child2)
{
	while(root != NULL)
	{
		if(root->data >= child1 && root->data >= child2)
		{
			root = root->left;
		}
		else if(root->data < child1 && root->data < child2)
		{
			root = root->right;
		}
		else
		{
			break;
		}
	}
	return root;
}

int main(int argc, char const *argv[])
{
    Node *root        		 = new Node(20);
    root->left               = new Node(8);
    root->right              = new Node(22);
    root->left->left         = new Node(4);
    root->left->right        = new Node(12);
    root->left->right->left  = new Node(10);
    root->left->right->right = new Node(14);
 
    int n1 = 10, n2 = 14;
    Node *t = lca_iterative(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
 
    n1 = 14, n2 = 8;
    t = lca_iterative(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
 
    n1 = 10, n2 = 22;
    t = lca_iterative(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
 
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->left->right; 
    delete root->left->left;  
    delete root->right;       
    delete root->left;        
    delete root;        		 

	return 0;
}