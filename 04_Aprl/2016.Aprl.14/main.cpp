#include <iostream>
#include <cstdlib>
#include <algorithm>
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
{}

typedef struct qItem
{
	Node 	*node;
	int 	depth;
}qItem;

int GetMinDepthDFT(Node *root)
{
	//Base Condition
	if(root == NULL)
		return 0;

	//Regular Condition
	int leftLength = 1 + GetMinDepthDFT(root->left);
	int rightLength = 1 + GetMinDepthDFT(root->right);

	int res = std::min(leftLength, rightLength);

	return res;
}

int GetMinDepthBFT(Node *root)
{
	int res(0);

	std::queue<qItem> BFTStorage;
	qItem r;
	r.node = root;
	r.depth = 1;

	BFTStorage.push(r);

	while(!BFTStorage.empty())
	{
		qItem qTemp = BFTStorage.front();
		BFTStorage.pop();

		Node *nTemp = qTemp.node;

		//Base Case
		if(nTemp->left == NULL && nTemp->right == NULL)
		{
			res = qTemp.depth;
			break;
		}
		else
		{
			if(nTemp->left != NULL)
			{
				qItem newLeft;
				newLeft.node = nTemp->left;
				newLeft.depth = qTemp.depth + 1;
				BFTStorage.push(newLeft);
			}
			if(nTemp->right != NULL)
			{
				qItem newRight;
				newRight.node = nTemp->right;
				newRight.depth = qTemp.depth + 1;
				BFTStorage.push(newRight);
			}	
		}
	}
	return res;
}

int main(int argc, char * argv[])
{
    Node *root        = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);

    int minDepthDFT = GetMinDepthDFT(root);
    std::cout << "The minimum depth: ";
    std::cout << minDepthDFT << std::endl;

    int minDepthBFT = GetMinDepthBFT(root);
    std::cout << "The minimum depth: ";
    std::cout << minDepthBFT << std::endl;

    delete root->left->left;
    delete root->left->right;
    delete root->left;       
    delete root->right;      
    delete root;       

	return 0;
}