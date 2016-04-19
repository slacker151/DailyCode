#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <iomanip>

typedef struct Node
{
	Node(int);

	int 	data;
	Node 	*left;
	Node 	*right;
}Node;

Node::Node(int a)
	: data(a)
	, left(NULL)
	, right(NULL)
{}

bool InsertBST(Node **root, Node *newNode)
{
	if(*root == NULL)
	{
		*root = newNode;
		return true;
	}

	Node *tempRoot = *root;

	while(tempRoot != NULL)
	{
		if(newNode->data <= tempRoot->data)
		{
			if(tempRoot->right != NULL && 
				tempRoot->left == NULL)
				return false;
			
			if(tempRoot->left == NULL)
			{
				tempRoot->left = newNode;
				break;
			}
			
			tempRoot = tempRoot->left;
		}
		else if(newNode->data > tempRoot->data)
		{
			if(tempRoot->right == NULL)
			{
				tempRoot->right = newNode;
				break;
			}
			
			tempRoot = tempRoot->right;
		}
	}
	return true;
}

void DeleteBST(Node *root)
{
	if(root == NULL)
		return;

	DeleteBST(root->left);
	DeleteBST(root->right);
	delete root;
}

bool canRepresentBST(int *list, int size)
{
	Node *root(NULL);

	bool res(true);

	for(int i(0); i < size; ++i)
	{
		Node *newNode = new Node(list[i]);
		if(!InsertBST(&root, newNode))
		{
			res = false;
			delete newNode;
			break;
		}
	}

	DeleteBST(root);
	return res;
}

int main(int argc, char * argv[])
{
    int pre1[] = {2, 4, 3};
    int n1 = sizeof(pre1)/sizeof(pre1[0]);
    canRepresentBST(pre1, n1) ? std::cout << "true\n":
                              std::cout << "false\n";
 
    int pre2[] = {2, 4, 1};
    int n2 = sizeof(pre2)/sizeof(pre2[0]);
    canRepresentBST(pre2, n2) ? std::cout << "true\n":
                              std::cout << "false\n";

    int pre3[] = {40, 30, 35, 80, 100};
    int n3 = sizeof(pre3)/sizeof(pre3[0]);
    canRepresentBST(pre3, n3) ? std::cout << "true\n":
                              std::cout << "false\n";

    int pre4[] = {40, 30, 35, 20, 80, 100};
    int n4 = sizeof(pre4)/sizeof(pre4[0]);
    canRepresentBST(pre4, n4) ? std::cout << "true\n":
                              std::cout << "false\n";

	return 0;
}