#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <utility>
#include <map>
#include <queue>

// Hashtable
typedef std::map<int, std::queue<int> > Hash;

// Class for a tree node
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

// A class to represent a queue item. The queue is used to do Level
// order traversal. Every Queue item contains node and horizontal
// distance of node from root
typedef struct QItem
{
	QItem(Node *n, int d);

	int horizontalDistanceFromRoot;
	Node *node;
}QItem;

QItem::QItem(Node *n, int d)
	: node(n)
	, horizontalDistanceFromRoot(d)
{}

// Class for a Binary Tree
typedef struct Tree
{
    // Constructors
    Tree();
    Tree(Node *n);
 	
 	// Operation
    void printTopView();

	// Root
    Node *root;

    // HashTable
    Hash h;
}Tree;

Tree::Tree()
	: root(NULL)
{}

Tree::Tree(Node *n)
	: root(n)
{}

void Tree::printTopView()
{
    if(root == NULL)
    	return;

    // Create a queue and add root to it
    std::queue<QItem> Q;
    QItem q(root, 0);
    Q.push(q); // Horizontal distance of root is 0

    // Standard BFS or level order traversal loop
    while (!Q.empty())
    {
        // Remove the front item and get its details
        QItem temp = Q.front();
        Q.pop();
        int hd = temp.horizontalDistanceFromRoot;
        Node *n = temp.node;

        // If this is the first node at its horizontal distance,
        // then this node is in top view
        if (h[hd].empty())
        {
        	h[hd].push(n->data);
            std::cout << std::setw(3) << n->data;
        }

        // Enqueue left and right children of current node
        if (n->left != NULL)
        {
        	QItem qTemp(n->left, hd - 1);
            Q.push(qTemp);
        }
        if (n->right != NULL)
        {
        	QItem qTemp(n->right, hd + 1);
            Q.push(qTemp);
        }
    }
}

int main(int argc, char *argv[])
{
    /* Create following Binary Tree
         1
       /  \
      2    3
       \
        4
         \
          5
           \
            6
    */

	Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);

    Tree *t = new Tree(root);
    t->printTopView();

	return 0;
}
 

