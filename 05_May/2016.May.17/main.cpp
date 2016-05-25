#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <queue>

typedef struct minHeapNode
{
	minHeapNode(char data_, unsigned freq_);

	char 		data;
	unsigned 	freq;

	minHeapNode* 	left;
	minHeapNode* 	right;

}minHeapNode;

minHeapNode::minHeapNode(char data_, unsigned freq_)
	: data(data_)
	, freq(freq_)
	, left(NULL)
	, right(NULL)
{}

struct compare
{
	bool operator()(minHeapNode* left, minHeapNode* right)
	{
		// left > right = minHeap
		// left < right = maxHeap
		return (left->freq > right->freq);
	}
};

void printCode(minHeapNode* root, std::string str)
{
	if(root == NULL)
		return;

	if(root->data != '$')
		std::cout << root->data << ": " << str << std::endl;

	printCode(root->left, str+"0");
	printCode(root->right, str+"1");
}

void HuffmanCodes(char* data, int* freq, int size)
{	
	minHeapNode* first(NULL);
	minHeapNode* second(NULL);


	std::priority_queue<minHeapNode*, std::vector<minHeapNode*>, compare> minHeap;
	for(int i(0); i < size; ++i)
	{
		minHeap.push(new minHeapNode(data[i], freq[i]));
	}

	while(minHeap.size() != 1)
	{
		first = minHeap.top();
		minHeap.pop();
		second = minHeap.top();
		minHeap.pop();

		minHeapNode* newNode = new minHeapNode('$', first->freq + second->freq);
		newNode->left = first;
		newNode->right = second;

		minHeap.push(newNode);
	}

	printCode(minHeap.top(), "");
}

int main(int argc, char const *argv[])
{
	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(arr) / sizeof(arr[0]);
 
    HuffmanCodes(arr, freq, size);
	return 0;
}
