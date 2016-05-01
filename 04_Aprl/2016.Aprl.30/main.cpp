#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <vector>

int Index = 0;

typedef struct Node
{
	Node(char);

	char data;
	Node* left;
	Node* right;
}Node;

Node::Node(char c)
	: data(c)
	, left(NULL)
	, right(NULL)
{}

void InOrderTraverse(Node* root)
{
	if(root != NULL)
	{
		InOrderTraverse(root->left);
		std::cout << std::setw(3) << root->data;
		InOrderTraverse(root->right);
	}
}

void ArchiveOddLvlNodes(Node* root, std::vector<char>& n, int depth)
{
	if(root != NULL)
	{
		ArchiveOddLvlNodes(root->left, n, depth + 1);
		if(depth % 2 != 0) // Odd depth
		{
			n.push_back(root->data);
		}
		ArchiveOddLvlNodes(root->right, n, depth + 1);
	}
}

void InjectOddLvlNodes(Node* root, std::vector<char> n, int depth)
{
	if(root != NULL)
	{
		InjectOddLvlNodes(root->left, n, depth + 1);
		if(depth % 2 != 0) // Odd depth
		{
			root->data = n[Index++];
		}
		InjectOddLvlNodes(root->right, n, depth + 1);
	}
}

void ReverseAlternateLevelNodes(Node* root)
{
	std::vector<char> n;
	ArchiveOddLvlNodes(root, n, 0);

	std::reverse(n.begin(), n.end());

	for(int i(0); i < n.size(); ++i)
	{
		std::cout << std::setw(3) << n[i];
	}
	std::cout << std::endl;

	InjectOddLvlNodes(root, n, 0);
}

int main(int argc, char const *argv[])
{
	Node *root = new Node('a');
    root->left = new Node('b');
    root->right = new Node('c');
    root->left->left = new Node('d');
    root->left->right = new Node('e');
    root->right->left = new Node('f');
    root->right->right = new Node('g');
    root->left->left->left = new Node('h');
    root->left->left->right = new Node('i');
    root->left->right->left = new Node('j');
    root->left->right->right = new Node('k');
    root->right->left->left = new Node('l');
    root->right->left->right = new Node('m');
    root->right->right->left = new Node('n');
    root->right->right->right = new Node('o');

    InOrderTraverse(root);
    std::cout << std::endl;

   	ReverseAlternateLevelNodes(root);

    InOrderTraverse(root);
    std::cout << std::endl;

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
	delete root->left->right;
	delete root->left->left;
	delete root->right;
	delete root->left;
	delete root;
	return 0;
}