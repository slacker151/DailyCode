#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <queue>

typedef struct Node
{
	Node(int);

	int 	data;
	Node 	*left;
	Node 	*right;
}Node;

Node::Node(int x)
	: data(x)
	, left (NULL)
	, right (NULL)
{}

bool isFullTree(Node *root)
{
	if(root == NULL)
		return false;

	std::queue<Node*> T;
	T.push(root);

	while(!T.empty())
	{
		Node *tempNode = T.front();
		T.pop();
		
		if((tempNode->left != NULL && tempNode->right == NULL)||
			(tempNode->left == NULL && tempNode->right != NULL))
		{
			return false;	
		}
		if(tempNode->left != NULL)
			T.push(tempNode->left);
		if(tempNode->right != NULL)
			T.push(tempNode->right);
	}
	return true;
}

int main(int argc, char * argv[])
{
    Node *root = new Node(10);
   	
  	root->left = new Node(20);
    root->right = new Node(30);
 
    root->left->right = new Node(40);
    root->left->left = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(70);
 
    root->left->left->left = new Node(80);
    root->left->left->right = new Node(90);
    root->left->right->left = new Node(80);
    root->left->right->right = new Node(90);
    root->right->left->left = new Node(80);
    root->right->left->right = new Node(90);
    root->right->right->left = new Node(80);
    root->right->right->right = new Node(90);
 
    if (isFullTree(root))
        printf("The Binary Tree is full\n");
    else
        printf("The Binary Tree is not full\n");

    delete root->right->right->right;
    delete root->right->right->left;
    delete root->right->left->right;
    delete root->right->left->left;
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->left->left->right;
    delete root->left->left->left;
    delete root->right->right;
    delete root->right->left;
    delete root->left->left;
    delete root->left->right;
    delete root->right;
  	delete root->left;
    delete root;
	return 0;
}