#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
#include <limits>
#include <queue>

typedef struct Node
{
	Node(int);

	int data;
	Node *left;
	Node *right;
}Node;

Node::Node(int x)
	:data(x)
{}

int findMaxSumUtil(Node *root, int &res)
{
	if(root == NULL)
		return 0;

	int l = findMaxSumUtil(root->left, res);
	int r = findMaxSumUtil(root->right, res);

	int max_single = std::max(std::max(l, r) + root->data, root->data);

	// These two lines are where magic happens
	// Check if the paths at each node has the 
	// maximum sum.
	int max_top = std::max(max_single, l + r + root->data);
	res = std::max(max_top, res);

	return max_single;
}

int findMaxSum(Node *root)
{
	int res(INT_MIN);

	findMaxSumUtil(root, res);

	return res;
}

int main(int argc, char * argv[])
{
    Node *root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(10);
    root->left->left  = new Node(20);
    root->left->right = new Node(1);
    root->right->right = new Node(-25);
    root->right->right->left   = new Node(3);
    root->right->right->right  = new Node(4);
    
    std::cout << "Max path sum is " << findMaxSum(root)
    << std::endl;
    
    delete root->right->right->right;
    delete root->right->right->left;   
    delete root->right->right; 
    delete root->left->right; 
    delete root->left->left;
    delete root->right; 
    delete root->left;
    delete root;
	return 0;
}