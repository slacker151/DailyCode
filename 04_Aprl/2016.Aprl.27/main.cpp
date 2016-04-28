#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <string>

typedef struct Node
{
	Node(char);

	char 	data;
	Node* 	left;
	Node* 	right;
}Node;

Node::Node(char c)
	: data(c)
	, left(NULL)
	, right(NULL)
{}

void GetPreOrderSeq(Node* root, std::string seq)
{
	if(root != NULL)
	{
		seq.push_back(root->data);
		GetPreOrderSeq(root->left, seq);
		GetPreOrderSeq(root->right, seq);
	}
	return;
}

void GetInOrderSeq(Node *root, std::string seq)
{
	if(root != NULL)
	{
		GetPreOrderSeq(root->left, seq);
		seq.push_back(root->data);
		GetPreOrderSeq(root->right, seq);
	}
	return;
}

bool isSubtree(Node* T, Node* S)
{
	std::string T_Pre;
		GetPreOrderSeq(T, T_Pre);
	std::string T_In;
		GetInOrderSeq(T, T_In);

	std::string S_Pre;
		GetPreOrderSeq(S, S_Pre);
	std::string S_In;
		GetPreOrderSeq(S, S_In);

	if(std::strstr(T_Pre.c_str(), S_Pre.c_str()) != NULL &&
		std::strstr(T_In.c_str(), S_In.c_str()) != NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main(int argc, char const *argv[])
{
	Node *T = new Node('a');
    T->left = new Node('b');
    T->right = new Node('d');
    T->left->left = new Node('c');
    T->right->right = new Node('e');
 
    Node *S = new Node('a');
    S->left = new Node('b');
    S->left->left = new Node('c');
    S->right = new Node('d');
 
    if (isSubtree(T, S))
        std::cout << "Yes: S is a subtree of T" << std::endl;
    else
        std::cout << "No: S is NOT a subtree of T"<< std::endl;
	
    delete T->right->right;
    delete T->left->left;
    delete T->right;
    delete T->left;
	delete T;

    delete S->right;
    delete S->left->left;
    delete S->left;
	delete S;

	return 0;
}