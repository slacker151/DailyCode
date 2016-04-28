#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <queue>

typedef struct Node
{
	Node(int);

	int data;
	Node *left;
	Node *right;
}Node;

Node::Node(int data)
	: data(data)
	, left(NULL)
	, right(NULL)
{}

Node* removeShortPathNodesUtil(Node *root, int depth, int k)
{
	if(root == NULL)
		return NULL;

	root->left = removeShortPathNodesUtil(root->left, depth + 1, k);
	root->right = removeShortPathNodesUtil(root->right, depth + 1, k);

	if(root->left == NULL && root->right == NULL && depth < k)
	{
		delete root;
		return NULL;
	}

	return root;
}

Node *removeShortPathNodes(Node *root, int k)
{
	return removeShortPathNodesUtil(root, 1, k);
}

void printInorder(Node *root)
{
	if(root)
	{
		printInorder(root->left);
		std::cout << std::setw(3) << root->data;
		printInorder(root->right);	
	}
}


int main(int argc, char const *argv[])
{
    int k = 4;
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(7);
    root->right->right = new Node(6);
    root->right->right->left = new Node(8);

    std::cout << "Inorder Traversal of Original tree" << std::endl;
    printInorder(root);
    std::cout << std::endl;
    
    std::cout << "Inorder Traversal of Modified tree" << std::endl;
    Node *res = removeShortPathNodes(root, k);
    printInorder(res);
    std::cout << std::endl;

	return 0;
}