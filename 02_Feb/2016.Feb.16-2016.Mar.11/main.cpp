//-----------------------------------------------------------------------Feb 17th 2016 Code

// #include <iostream>
// #include <algorithm>
// #include <ctime>
// #include <cstdlib>
// #include <iomanip>

// //recursive factorial algo
// //-------------------------------------------------------
// // recursion
// template<int N>
// class Factorial
// {
// public:
// 	enum{value = N * Factorial<N-1>::value};
// 	int GetValue(){return value;}
// };

// //base condition
// template<>
// class Factorial<1>
// {
// public:
// 	enum{value = 1};
// };

// #define VALUE 4
// //-------------------------------------------------------

// //bubbleSort
// //-------------------------------------------------------
// //normal bubbleSort
// void bubbleSort(int *a, int size)
// {
// 	for(unsigned i (size - 1); i > 0; --i)
// 	{
// 		for(unsigned j(0); j < i; ++j)
// 		{
// 			//ascending order
// 			if(a[j] > a[j+1])
// 				std::swap(a[j], a[j+1]);
// 		}
// 	}
// }

// //tmp bubbleSort
// template<int i, int j>
// class IntBubbleSortLoop
// {
// public:
// 	static inline void loop(int *data)
// 	{
// 		if(data[i] > data[i+1])
// 			std::swap(data[i], data[i+1]);
// 		IntBubbleSortLoop< go ? i+1 : 0, go ? j : 0>::loop(data);
// 	}
// private:
// 	enum{go = i < j};
// };

// template<>
// class IntBubbleSortLoop<0, 0>
// {
// public:
// 	static inline void loop(int *data){}
// };

// template<int N>
// class IntBubbleSort 
// {
// public:
//     static inline void sort(int *data)
//     {
//         IntBubbleSortLoop<0, N>::loop(data);
//         IntBubbleSort<N - 1>::sort(data);
//     }
// };

// template<>
// class IntBubbleSort<0> 
// {
// public:
//     static inline void sort(int *data){}
// };

// #define SIZE 10
// //-------------------------------------------------------


// int main(int argc, char* argv[])
// {
// 	//Factorial Algo
// 	Factorial<VALUE> a;
// 	std::cout << a.GetValue() << std::endl;
	
// 	//BubbleSort Algo normal
// 	srand(static_cast<unsigned>(time(NULL)));
// 	int size(10);
// 	int list[size];

// 	for(int i(0); i < size; ++i)
// 		list[i] = rand() % 10;

// 	bubbleSort(list, size);

// 	for(int i(0); i < size; ++i)
// 		std::cout << std::setw(4) << list[i];

// 	std::cout << "\n";

// 	//BubbleSort Algo tmp
// 	int list1[size];
// 	for(int i(0); i < size; ++i)
// 		list1[i] = rand() % 10;

// 	IntBubbleSort<SIZE> tmpBubbleSort;
// 	tmpBubbleSort.sort(list1);

// 	for(int i(0); i < size; ++i)
// 		std::cout << std::setw(4) << list1[i];

// 	std::cout << std::endl;

// 	return 0;
// }


//-----------------------------------------------------------------------Feb 18th 2016 Code
// #include <iostream>
// #include <iomanip>
// #include <assert.h>

// //singly linked-list simply put
// typedef struct IntElement
// {
// 	IntElement 		*next;
// 	int 			data;
// }IntElement;

// IntElement* InsertInFront(IntElement *head, int data)
// {
// 	IntElement *newHead = new IntElement;
// 	newHead->next = head;
// 	newHead->data = data;

// 	assert(newHead !=NULL);
// 	return newHead;
// }


// int main(int argc, char* argv[])
// {
// 	//Initializing the head of LL
// 	IntElement *head = new IntElement;
// 	head->next = NULL;
// 	head->data = 1;
	
// 	//Inserting elements to LL
// 	for(int i(2); i < 5; ++i)
// 		head = InsertInFront(head, i);

// 	//Traversing through the LL
// 	IntElement *tempHead = head;
// 	while(tempHead != NULL)
// 	{		
// 		std::cout << std::setw(4) << tempHead->data;
// 		tempHead = tempHead->next;
// 	}

// 	//Memory releasing
// 	while (head != NULL)
// 	{
// 		IntElement *tempHead = head;
// 		head = head->next;
// 		delete tempHead;
// 	}

// 	std::cout << std::endl;
// 	return 0;
// }



//-----------------------------------------------------------------------Feb 19th 2016 Code
// #include <iostream>
// #include <assert.h>
// #include <iomanip>
// #include <algorithm>
// #include <ctime>
// #include <cstdlib>

// //Basic LL
// typedef struct Node
// {
// 	Node 	*next;
// 	int 	data;
// }Node;

// //Insert
// bool Insert(Node **head, int data)
// {
// 	Node *newNode = new Node;
// 	newNode->next = *head;
// 	newNode->data = data;

// 	if(!newNode) return false;

// 	*head = newNode;

// 	return true;
// }

// //Delete
// bool Delete(Node **head, Node *nodeToBeDeleted)
// {
// 	Node* tempHead = *head;

// 	if(*head == nodeToBeDeleted)
// 	{
// 		*head = nodeToBeDeleted->next;
// 		delete nodeToBeDeleted;
// 		return true;
// 	}

// 	while(tempHead != NULL && tempHead != nodeToBeDeleted)
// 	{
// 		if(tempHead->next == nodeToBeDeleted)
// 		{
// 			Node * deletingNode = tempHead->next;
// 			tempHead->next = deletingNode->next;
// 			delete deletingNode;
// 			return true;
// 		}
// 		tempHead = tempHead->next;
// 	}

// 	return false;
// }

// //Traverse
// void Traverse(Node **head)
// {
// 	Node *tempHead = *head;
// 	while(tempHead != NULL)
// 	{
// 		std::cout << std::setw(4) << tempHead->data;
// 		tempHead = tempHead->next;
// 	}
// 	std::cout << std::endl;
// }

// bool Clean(Node **head)
// {
// 	Node *tempNode = *head;
// 	while(tempNode != NULL)
// 	{
// 		Node* temp = tempNode;
// 		tempNode = tempNode->next;
// 		delete temp;
// 	}	
// 	if(tempNode == NULL) return true;
// 	return false;
// }


// //Object-oriented linked-list stack implementation 
// class Stack
// {
// public:
// 	Stack(); //ctor
// 	~Stack(); //dtor
// 	void push(void *data);
// 	void *pop();
// 	void display();

// protected:	
// 	typedef struct Node
// 	{
// 		Node 	*next;
// 		void  	*data;
// 	}Node;

// private:
// 	Node *head;
// };

// Stack::Stack()
// {
// 	head = NULL;
// }

// Stack::~Stack()
// {
// 	while(head)
// 	{
// 		Node * tempHead = head;
// 		head = head->next;
// 		delete tempHead;
// 	}
// }

// void Stack::push(void *data)
// {
// 	Node *newNode = new Node;
// 	newNode->data = data;
// 	newNode->next = head;
// 	assert(newNode != NULL);

// 	head = newNode;
// }

// void *Stack::pop()
// {
// 	assert(head != NULL);

// 	Node *tempHead = head;
// 	void *data = tempHead->data;
// 	head = head->next;

// 	delete tempHead;

// 	return data;
// }

// void Stack::display()
// {
// 	Node *tempHead = head;

// 	while(tempHead)
// 	{
// 		std::cout << std::setw(4) << tempHead->data;
// 		tempHead = tempHead->next;
// 	}
// 	std::cout << std::endl;
// }

// int main(int argc, char*argv[])
// {
// 	Node *head = new Node;
// 	head->next = NULL;
// 	head->data = 1;

// 	//insert
// 	for(int i(2); i <= 5; ++i)
// 		assert(Insert(&head, i) == true);

// 	//Traverse
// 	Traverse(&head);

// 	//delete
// 	assert(Delete(&head, head->next->next) == true);

// 	//Traverse
// 	Traverse(&head);

// 	//clean
// 	Clean(&head);


// 	Stack s;
// 	for(int i(0); i < 10; ++i)
// 	{
// 		s.push(reinterpret_cast<void *>(i));
// 	}

// 	s.display();


// 	return 0;
// }



//-----------------------------------------------------------------------Feb 20th 2016 Code
// #include <iostream>
// #include <limits.h>
// #include <assert.h>

// //	N = NumOfItem 	
// //	M = NumOfShop
// int N, M;

// int **tempPriceMatrix;
// int **tempDiscountMatrix; 	

// bool CreatePriceList(int ***PriceMatrix, int NumOfItem, int NumOfShop)
// {
// 	int row(NumOfItem);
// 	int col(NumOfShop);

// 	int **tempPriceMatrix = new int*[row];

// 	for(int i(0); i < row; ++i)
// 		tempPriceMatrix[i] = new int[col];

// 	for(int i(0); i < row; ++i)
// 	{
// 		for(int j(0); j < col; ++j)
// 		{
// 			std::cin >> tempPriceMatrix[i][j];
// 		}
// 	}

// 	*PriceMatrix = tempPriceMatrix;

// 	return true;
// }

// bool CreateDiscountList(int ***DiscountMatrix, int NumOfItem, int NumOfShop)
// {
// 	int row(NumOfItem);
// 	int col(NumOfShop);

// 	int **tempDiscountMatrix = new int*[row];

// 	for(int i(0); i < row; ++i)
// 		tempDiscountMatrix[i] = new int[col];

// 	for(int i(0); i < row; ++i)
// 	{
// 		for(int j(0); j < col; ++j)
// 		{
// 			std::cin >> tempDiscountMatrix[i][j];
// 		}
// 	}

// 	*DiscountMatrix = tempDiscountMatrix;

// 	return true;
// }

// int GetMin(int row, int col, int parentCol)
// {
// 	//Min value declaration
// 	int Min(9999);

// 	//Discount cal
// 	int discount (0);

// 	if (row > 0 && col == parentCol)
// 	{
// 		discount = tempDiscountMatrix[row - 1][col] <= tempPriceMatrix[row][col] ?
// 				   tempDiscountMatrix[row - 1][col] : tempPriceMatrix[row][col]; 
// 	}

// 	//Last row - stopping condition
// 	if (row >= N - 1)
// 		return tempPriceMatrix[row][col] - discount;

// 	//Recursion
// 	for (int j(0); j < ::M; ++j)
// 	{
// 		int result = GetMin(row + 1, j, col) - discount;
// 		if(row >= 0)
// 			result +=  tempPriceMatrix[row][j];

// 		Min = result < Min ? result : Min;
// 	}

// 	return Min;
// }

// int GetMinCost(int *ItemShop, int ***PriceMatrix, int ***DiscountMatrix)
// {
// 	::tempPriceMatrix 	 	= *PriceMatrix;		//Price
// 	::tempDiscountMatrix 	= *DiscountMatrix;	//Discount

// 	::N = ItemShop[0];	//Item
// 	::M = ItemShop[1];	//Shop	

// 	return GetMin(-1, 0, 0);
// }

// int main(int argc, char* argv[])
// {
// 	int NumOfTest(0);
// 	std::cin >> NumOfTest;

// 	//Creation
// 	int **ItemShopMatrix = new int* [NumOfTest];
// 	int ***PriceMatrices = new int** [NumOfTest];
// 	int ***DiscountMatrices = new int** [NumOfTest];

// 	//Initialization
// 	for (int i(0); i < NumOfTest; ++i)
// 	{
// 		//Getting NumOfItems and NumOfShops
// 		ItemShopMatrix[i] = new int[2];
// 		std::cin >> ItemShopMatrix[i][0] >> ItemShopMatrix[i][1];

// 		//Getting price matrix
// 		CreatePriceList(&PriceMatrices[i], ItemShopMatrix[i][0], ItemShopMatrix[i][1]);

// 		//Getting discount matrix
// 		CreateDiscountList(&DiscountMatrices[i], ItemShopMatrix[i][0], ItemShopMatrix[i][1]);
// 	}

// 	//Process
// 	for (int i(0); i < NumOfTest; ++i)
// 	{
// 		int result = GetMinCost(ItemShopMatrix[i], &PriceMatrices[i], &DiscountMatrices[i]);
// 		std::cout << "The minimum cost in test" << i+1 << " : " << result << std::endl;
// 	}

// 	//Destruction
// 	for (int k(0); k < NumOfTest; ++k)
// 	{
// 		//ItemShop
// 		int row(ItemShopMatrix[k][0]);
// 		int col(ItemShopMatrix[k][1]);
// 		delete [] ItemShopMatrix[k];
// 		ItemShopMatrix[k] = NULL;

// 		//Price 
// 		for (int i(0); i < row; ++i)
// 		{
// 			for(int j(0); j < col; ++j)
// 			{
// 				PriceMatrices[k][i][j] = 0;
// 			}		
// 			delete [] PriceMatrices[k][i];
// 			PriceMatrices[k][i] = NULL;
// 		}
// 		delete [] PriceMatrices[k];
// 		PriceMatrices[k] = NULL;


// 		//Discount
// 		for (int i(0); i < row; ++i)
// 		{
// 			for(int j(0); j < col; ++j)
// 			{
// 				DiscountMatrices[k][i][j] = 0;	
// 			}
// 			delete [] DiscountMatrices[k][i];
// 			DiscountMatrices[k][i] = NULL;
// 		}
// 		delete [] DiscountMatrices[k];
// 		DiscountMatrices[k] = NULL;
// 	}

// 	delete [] ItemShopMatrix;
// 	ItemShopMatrix = NULL;
// 	delete [] PriceMatrices;
// 	PriceMatrices = NULL;
// 	delete [] DiscountMatrices;
// 	DiscountMatrices = NULL;

// 	return 0;
// }

//-----------------------------------------------------------------------Feb 21st 2016 Code
// #include <iostream>

// typedef struct Node
// {
// 	Node 	*next;
// 	char 	data;
// }Node;



// //Mth-to-last element
// Node *GetMthToLast(Node **head, int m)
// {
// 	//error checking
// 	if (!*head)
// 	{
// 		return NULL;
// 	}

// 	Node *MthToLast = *head;
// 	Node *tempHead 	= *head;
// 	int counter(0);

// 	while(tempHead)
// 	{
// 		if(counter > m)
// 			MthToLast = MthToLast->next;
// 		counter++;
// 		tempHead = tempHead->next;
// 	}

// 	if (counter <= m)
// 	{
// 		return NULL;
// 	}

// 	return MthToLast;
// }


// int main(int argc, char* argv[])
// {
// 	//Initialization
// 	Node *head = new Node;
// 	head->next = NULL;
// 	head->data = static_cast<char>(65);

// 	//Creation
// 	Node *tempHead = head;
// 	for(int i(66); i < 80; ++i)
// 	{
// 		Node *newNode = new Node;
// 		newNode->next = NULL;
// 		newNode->data = static_cast<char>(i);
// 		tempHead->next = newNode;
// 		tempHead = newNode;
// 	}

// 	//Process
// 	Node *MthToLast = GetMthToLast(&head, 3);
// 	if(MthToLast)
// 	{
// 		std::cout << "3rd-to-last : " << MthToLast->data << std::endl;
// 	}
// 	else
// 	{
// 		std::cout << "list is too short" << std::endl;	
// 	}
	
// 	//Destruction
// 	while (head)
// 	{
// 		Node *DeletingNode = head;
// 		std::cout << DeletingNode->data << " ";
// 		head = head->next;
// 		delete DeletingNode;
// 	}

// 	std::cout << std::endl;

// 	return 0;
// }

// NULL-terminated or cycle linked-list
// #include <iostream>
// #include <iomanip>
// #include <algorithm>
// #include <assert.h>
// #include <ctime>
// #include <cstdlib>

// typedef struct Node 
// {
// 	Node *next;

// 	int data;
// }Node;

// bool AcyclicOrCyclic_Method_One(Node *head) 
// // The reason for *head and not **head is because I am not allowed to modify the list
// {
// 	//true 	= cyclic
// 	//false = acyclic

// 	//First approach
// 	// for each element, compare its next node with all its previous nodes
// 	// time order for this approach is O(n^2)
// 	Node *tempHead = head;
// 	while(tempHead->next)
// 	{
// 		Node *tempTempHead = head;
// 		while(tempTempHead != tempHead)
// 		{
// 			if(tempTempHead == tempHead->next)
// 				return true;
// 			tempTempHead = tempTempHead->next;
// 		}

// 		tempHead = tempHead->next;
// 	}

// 	return false;
// }

// bool AcyclicOrCyclic_Method_Two(Node *head) 
// // The reason for *head and not **head is because I am not allowed to modify the list
// {
// 	//true 	= cyclic
// 	//false = acyclic

// 	//Second approach
// 	// with two iterating pointers, slow and fast, we will be able to determine whether
// 	// the Linked-list is cyclic or acyclic. This is because the fast iterator would 
// 	// always catch up to the slow iterator if the linked list is cyclic.
// 	// time order for this approach is O(n) despite of the existance of an infinite loop
// 	Node *slow;
// 	Node *fast;

// 	if(head != NULL && head->next != NULL)
// 	{
// 		slow = head;
// 		fast = head->next;
// 	}
// 	else
// 	{
// 		return false;
// 	}

// 	while(true)
// 	{
// 		if(fast == NULL || fast->next == NULL)
// 			return false;
// 		else if(fast == slow || fast->next == slow)
// 			return true;
// 		else
// 		{
// 			slow = slow->next;
// 			fast = fast->next->next;
// 		}
// 	}
// }

// int main(int argc, char* argv[])
// {
// 	Node *head = NULL;
// 	Node *tempHead = NULL;

// 	for (int i(0); i < 10; ++i)
// 	{
// 		Node * newNode = new Node;
// 		newNode->next = NULL;
// 		newNode->data = i;

// 		if(head == NULL)
// 			head = newNode;

// 		if(tempHead == NULL)
// 			tempHead = newNode;
// 		else
// 		{
// 			tempHead->next = newNode;
// 			tempHead = newNode;
// 		}
// 	}

// 	//Modifying the LL into a cyclic LL 
// 	// Node *tail = NULL;
// 	// tempHead = head;
// 	//
// 	// while(tempHead->next)
// 	// {
// 	// 	tempHead = tempHead->next;
// 	// }
// 	//
// 	// tail = tempHead;
// 	// assert(tempHead->next == NULL);
// 	// tail->next = head->next->next;

// 	//Process
// 	assert(AcyclicOrCyclic_Method_Two(head) == false);

// 	while(head)
// 	{
// 		std::cout << std::setw(4) << head->data;
// 		Node *deletingNode = head;
// 		head = head->next;
// 		delete deletingNode;
// 	}

// 	std::cout << std::endl;

// 	return 0;
// }

//-----------------------------------------------------------------------Feb 22nd 2016 Code

// #include <iostream>
// #include <iomanip>

// class BTree
// {
// public:
// 	//tors
// 	BTree(BTree *, BTree *, int);
// 	~BTree();

// 	//accessors	
// 	BTree *	GetLeftChild();
// 	BTree *	GetRightChild();
// 	int 	GetData();

// protected:
// private:
// 	BTree *leftChild;
// 	BTree *rightChild;

// 	int data;
// };

// BTree::BTree(BTree *left, BTree *right, int value)
// 	:leftChild(left)
// 	,rightChild(right)
// 	,data(value)
// {
// }

// BTree::~BTree()
// {
// 	if(leftChild)
// 		delete leftChild;
// 	if(rightChild)
// 		delete rightChild;
// }

// BTree *BTree::GetLeftChild()
// {
// 	return leftChild;
// }

// BTree *BTree::GetRightChild()
// {
// 	return rightChild;
// }

// int BTree::GetData()
// {
// 	return data;
// }

// class BST
// {
// public:
// 	//ctors
// 	BST()
// 		:data(0)
// 		,leftChild(NULL)
// 		,rightChild(NULL)
// 	{}
	
// 	BST(int value, BST *L, BST *R)
// 	:data(value)
// 	,leftChild(L)
// 	,rightChild(R)
// 	{}

// 	~BST()
// 	{
// 		if(leftChild)
// 			delete leftChild;
// 		if(rightChild)
// 			delete rightChild;
// 	}

// 	//accessors
// 	int 	GetData(){return data;}
// 	BST 	*GetLeftChild(){return leftChild;}
// 	BST 	*GetRightChild(){return rightChild;}

// 	//Look up - time order = O(log(n))
// 	BST  	*FindNode(BST *root, int value)
// 	{
// 		if (root == NULL)
// 			return NULL;
// 		if (root->GetData() == value)
// 			return root;
// 		else if (root->data <= value)
// 			return FindNode(root->GetLeftChild(), value);
// 		else
// 			return FindNode(root->GetRightChild(), value);
// 	}

// protected:
// private:
// 	int 	data;
// 	BST 	*leftChild;
// 	BST 	*rightChild;
// };


// int main(int argc, char* argv[])
// {
// 	BST *root = new BST(10, NULL, NULL);

// 	BST *tempNode = root->FindNode(root, 10);

// 	delete root;

// 	return 0;
// }



//-----------------------------------------------------------------------Feb 23rd 2016 Code
// #include <iostream>
// #include <iomanip>

// class BST
// {
// public:
// 	BST()
// 		:data(0)
// 		,left(NULL)
// 		,right(NULL)
// 	{}
// 	~BST()
// 	{
// 		if (left)
// 			delete left;
// 		if (right)
// 			delete right;
// 	}

// 	int data;
// 	BST *left;
// 	BST *right;
// };

// void PreorderTraversal(BST *head)
// {
// 	BST *root = head;
// 	while(root->left != NULL)
// 	{
// 		root = root->left;
// 	}
// }

// int main(int argc, char *argv[])
// {
// 	//head
// 	BST *head;
// 	head = new BST;
// 	head->data = 100;

// 	//left subtree
// 	head->left = new BST;
// 	head->left->data = 50;

// 	head->left->left = new BST;
// 	head->left->left->data = 25;
	
// 	head->left->right = new BST;
// 	head->left->right->data = 75;

// 	//right subtree
// 	head->right = new BST;
// 	head->right->data = 150;
	
// 	head->right->left = new BST;
// 	head->right->left->data = 125;
	
// 	head->right->right = new BST;
// 	head->right->right->data = 175;

// 	head->right->left->left = new BST;
// 	head->right->left->left->data = 110;

// 	PreorderTraversal(head);

// 	return 0;
// }

// #include <iostream>

// int main()
// {
// 	int list[10];

// 	for (int i(0); i < 10; ++i)
// 	{
// 		list[i] = i;
// 	}

// 	list[12] = 5;

// 	return 0;
// }


//-----------------------------------------------------------------------Feb 24th 2016 Code
// #include <iostream>
// #include <assert.h>
// #include <iomanip>
// #include <cstdlib>
// #include <string>
// #include <ctime>

// char GetFirstNonrepeatingChar(std::string str)
// {
// 	char c;

// 	//First and intuitive solution:
// 	//	For each element in the string starting from the first, compare with every other 
// 	//	element in the string. Do this till we reach that character. Time order = O(n^2).

// 	//Second and more sophisticated solution:
// 	//	For each element we increment the count (or have a different number for more 
// 	//	than one)in a hashtable. one loop = O(n)
// 	//	For each element, find the first count = 1 in the hashtable. one loop = O(n)
// 	// 	Therefore, the time order is equal to O(2n) = O(n)

// 	int hashTable[128] = {0};

// 	for (int i(0); i < str.size(); ++i)
// 	{
// 		hashTable[str[i]]++;
// 	}

// 	for(int i(0); i < str.size(); ++i)
// 	{
// 		if(hashTable[str[i]] == 1)
// 		{
// 			c = str[i];
// 			break;
// 		}
// 	}

// 	return c;
// }

// int main(int argc, char *argv[])
// {
// 	std::string str("totally");

// 	char c = GetFirstNonrepeatingChar(str);

// 	std::cout << c << std::endl;

// 	return 0;
// }


// #include <iostream>
// #include <iomanip>
// #include <assert.h>
// #include <cstdlib>
// #include <ctime>
// #include <string>

// std::string RemoveSpecificChar(std::string str,std::string rm)
// {
// 	bool hashTable[128] = {false};
// 	char *string = new char[str.size()];
// 	memcpy(string, str.c_str(), str.size());

// 	for(int i(0); i < rm.size(); ++i)
// 	{
// 		hashTable[rm[i]] = true;
// 	}

// 	int src(0);
// 	int dst(0);

// 	while(src < str.size())
// 	{
// 		if(!hashTable[string[src]])
// 		{
// 			string[dst] = string[src];
// 			dst++;
// 		}
// 		src++;
// 	}

// 	char *result = new char[dst];

// 	for (int i(0); i < dst; ++i)
// 	{
// 		result[i] = string[i];
// 	}

// 	std::string res(result);

// 	delete [] result;
// 	delete [] string;
// 	return res;
// }


// int main(int argc, char *argv[])
// {
// 	std::string str ("This is the input string. Show me what you got");
// 	std::string rm ("sort");

// 	std::string res = RemoveSpecificChar(str, rm);

// 	std::cout << str << std::endl;
// 	std::cout << rm << std::endl;
// 	std::cout << res << std::endl;

// 	return 0;
// }

//-----------------------------------------------------------------------Feb 25th 2016 Code


// #include <iostream>
// #include <algorithm>
// #include <iomanip>
// #include <assert.h>
// #include <cstdlib>
// #include <string>
// #include <ctime>

// //ReverseWords 
// //Write a function that reverses the order of the words in a string. For example, your
// //function should transform the string “Do or do not, there is no try.” to “try. no is
// //there not, do or Do”.
// void reverseString(char **str, int start, int end)
// {
// 	char *string = *str;
// 	while(end > start)
// 	{
// 		std::swap(string[start++], string[end--]);
// 	}
// }

// std::string ReverseWords(std::string str)
// {
// 	// Two solution: one obvious, one elegant

// 	// First one, tokenize the string with spaces, stuff substrings into a string stack
// 	// after it is done, concatenate all the substrings into a string seperated with ' '


// 	// Second one, write a function called reverse string that takes in a string, start,
// 	// and a stop. Then with in main function, first call reverseString on the whole 
// 	// string. Then for each tokenized word, call reverseString on that word based on
// 	// its start and end indeces.
// 	std::string result;
// 	char *string = new char [str.size()];
// 	memcpy(string, str.c_str(), str.size());

// 	int start = 0;
// 	int end = 0;

// 	reverseString(&string, start, str.size() - 1);

// 	while(end != str.size())
// 	{
// 		end = start + 1;
// 		while(string[end] != ' ' && end != str.size())
// 		{
// 			end++;
// 		}

// 		reverseString(&string, start, end-1);
// 		start = end + 1;
// 	}

// 	for(int i(0); i < str.size(); ++i)
// 	{
// 		std::cout << string[i];
// 	}
// 	std::cout << std::endl;

// 	delete [] string;
// 	return result;
// }

// int main(int argc, char *argv[])
// {
// 	std::string str("what the fuck mother fucker");
// 	ReverseWords(str);


// 	return 0;
// }



//-----------------------------------------------------------------------Feb 28th 2016 Code
// #include <iostream>
// #include <assert.h>
// #include <iomanip>
// #include <algorithm>
// #include <ctime>
// #include <cstdlib>
// #include <string>

// void strToInt(std::string str)
// {
// 	int 	num(0);
// 	int 	it(0);
// 	bool 	negFlag(false);
// 	int 	len(str.size());

// 	if(str[it] == '-')
// 	{
// 		negFlag = true;
// 		it++;
// 	}

// 	while(it < len)
// 	{
// 		num = num * 10;
// 		num += str[it] - '0';
// 		it++;
// 	}

// 	if(num && negFlag)
// 	{
// 		num *= -1;
// 	}

// 	std::cout << "The number is " << num << std::endl;
// }

// void IntToStr(int num)
// {
// 	std::string result;
// 	char *numArray = new char[20];
// 	bool negFlag (false);
// 	int it(0);

// 	if(num < 0)
// 	{
// 		num *= -1;
// 		negFlag = true;
// 	}

// 	while(num != 0)
// 	{
// 		numArray[it] = static_cast<char>(num % 10 + '0');
// 		num /= 10;
// 		it++;
// 	}

// 	if(negFlag && it)
// 	{
// 		result.push_back('-');
// 	}

// 	for (int i(it-1); i >= 0; --i)
// 	{
// 		result.push_back(numArray[i]);
// 	}

// 	std::cout << result << std::endl;
// }

// int main(int argc, char *argv[])
// {
// 	std::string str("-11234");

// 	strToInt(str);

// 	int num (-1234);

// 	IntToStr(num);

// 	return 0;
// }


// #include <iostream>
// #include <iomanip>
// #include <algorithm>
// #include <ctime>
// #include <cstdlib>
// #include <assert.h>

// //Most Classic Dynamic programming Questions
// // Memoization
// // Tabulation

// //Longest Increasing Subsequence


// //Dynamic Programming - O(n^2)
// int LIS_dp_raw(int *arr, int size)
// {
// 	int MaxLength(1);
// 	int *DP = new int [size];

// 	for (int i(1); i < size; ++i)
// 	{
// 		DP[i] = 1;
// 		for(int j(0); j < i; ++j)
// 		{
// 			if (arr[j] < arr[i] && DP[i] < DP[j] + 1)
// 			{
// 				DP[i] = DP[j] + 1;
// 			}
// 		}
// 	}

// 	for (int i(0); i < 6; ++i)
// 	{
// 		MaxLength = MaxLength > DP[i] ? MaxLength : DP[i];
// 	}

// 	delete [] DP;
// 	return MaxLength;
// }


// //Longest Common Subsequence


// int main(int argc, char * argv[])
// {
// 	int list[]= {4,2,1,5,6,4};

// 	int res = LIS_dp_raw(list, 6);

// 	std::cout << res << std::endl;

// 	return 0;
// }



//-----------------------------------------------------------------------Feb 29th 2016 Code
// #include <iostream>
// #include <iomanip>
// #include <assert.h>
// #include <algorithm>
// #include <string>
// #include <cstdlib>

// // Longest Common Subsequence
// char s1[] = "AGGTAB";
// char s2[] = "GXTXAYB";
// const int M = strlen(s1);
// const int N = strlen(s2);

// int LCS_recursive(int index1, int index2)
// {
// 	if(index1 == -1 || index2 == -1)
// 	{
// 		return 0;
// 	}	
// 	else if(s1[index1] == s2[index2])
// 	{
// 		return (1 + LCS_recursive(index1-1, index2-1));
// 	}
// 	else
// 	{
// 		int result = LCS_recursive(index1-1, index2) > LCS_recursive(index1, index2-1) ?
// 					 LCS_recursive(index1-1, index2) : LCS_recursive(index1, index2-1);
// 		return result;
// 	}
// }

// int **DP = NULL;

// int LCS_DP(int index1, int index2)
// {
// 	for (int i(0); i <= M; ++i)
// 	{
// 		for (int j(0); j <= N; ++j)
// 		{
// 			if(i == 0 || j == 0)
// 			{
// 				DP[i][j] = 0;
// 			}
// 			else if (s1[i-1] == s2[j-1])
// 			{
// 				DP[i][j] = 1 + DP[i-1][j-1];
// 			}
// 			else
// 			{
// 				int result = DP[i-1][j] > DP[i][j-1] ?
// 							 DP[i-1][j] : DP[i][j-1];
// 				DP[i][j] = result;
// 			}
// 		}
// 	}
// 	return DP[M][N];
// }

// int LCS_rawDP(int index1, int index2)
// {
// 	if (index1 == 0 || index2 == 0)
// 	{
// 		DP[index1][index2] = 0;
// 	}
// 	else if (s1[index1-1] == s2[index2-1])
// 	{
// 		DP[index1][index2] = 1 + LCS_rawDP(index1-1, index2-1);
// 	}
// 	else
// 	{	
// 		int result = LCS_rawDP(index1, index2-1) > LCS_rawDP(index1-1, index2) ?
// 					 LCS_rawDP(index1, index2-1) : LCS_rawDP(index1-1, index2);
// 		DP[index1][index2] = result;
// 	}

// 	return DP[index1][index2];
// }

// int main(int argc, char* argv[])
// {
// 	std::cout << LCS_recursive(M - 1, N - 1) << std::endl;

// 	DP = new int *[M + 1];
// 	for(int i(0); i < M + 1; ++i)
// 	{
// 		DP[i] = new int [N + 1];
// 	}

// 	std::cout << LCS_rawDP(M, N) << std::endl;

// 	return 0;
// }



//-----------------------------------------------------------------------Mar 1st 2016 Code
// #include <iostream>
// #include <iomanip>
// #include <algorithm>
// #include <assert.h>
// #include <cstdlib>
// #include <string>

// int a[] = {10, 22, 9, 10, 11, 31, 80, 21, 50, 41, 60, 80};
// const int M = sizeof(a) / sizeof(a[0]);
// int maximumValue(1);

// int LIS_recursive(int size)
// {
// 	// base case
// 	if(size == 1)
// 		return 1;

// 	int maxLength(1);

// 	for(int i(1); i < size; ++i)
// 	{
// 		int res = LIS_recursive(i);
// 		if(a[size - 1] > a[i-1] && res + 1 > maxLength)
// 			maxLength = res + 1;
// 	}

// 	maximumValue = maximumValue > maxLength ? maximumValue : maxLength;

// 	return maxLength;
// }

// int DP_raw[M+1];


// int LIS_DP_raw(int size)
// {
// 	if(size == 1)
// 	{
// 		DP_raw[size] = 1;
// 		return DP_raw[size];
// 	}

// 	int maxLength(1);

// 	for(int i(1); i < size; ++i)
// 	{
// 		int res(0);
// 		if(DP_raw[i] > 0)
// 		{
// 			res = DP_raw[i];
// 		}
// 		else
// 		{
// 			res = LIS_DP_raw(i);
// 		}
// 		if(a[size - 1] > a[i - 1] && res + 1 > maxLength)
// 			maxLength = res + 1;
// 	}

// 	maximumValue = maximumValue > maxLength ? maximumValue : maxLength;

// 	DP_raw[size] = maxLength;
// 	return DP_raw[size];
// }

// int LIS_DP(int size)
// {
// 	int DP[M];
// 	std::fill_n(DP, M, 1);

// 	for (int i(1); i < M; ++i)
// 	{
// 		for (int j(0); j < i; ++j)
// 		{
// 			if(a[i] > a[j] && DP[j] + 1 > DP[i])
// 			{
// 				DP[i] = DP[j] + 1;
// 			}
// 		}
// 	}

// 	int max(0);
// 	for(int i(0); i < M; ++i)
// 	{
// 		max = DP[i] > max ? DP[i] : max;
// 	}
	
// 	return max;
// }

// int main(int argc, char* argv[])
// {	
// 	std::cout << LIS_recursive(M) << std::endl;

// 	std::fill_n(DP_raw, M+1, -1);
// 	std::cout << LIS_DP_raw(M) << std::endl;

// 	std::cout << LIS_DP(M) << std::endl;

// 	return 0;
// }


//-----------------------------------------------------------------------Mar 2nd 2016 Code
// #include <iostream>
// #include <iomanip>
// #include <cstdlib>
// #include <assert.h>
// #include <algorithm>
// #include <string>
// #include <utility>
// #include <map>
// #include <iterator>
// #include <ctime>

// char s1[] = "adsfkjahsdfkdfd";
// char s2[] = "adskjfhakadfesad";

// int M = strlen(s1);
// int N = strlen(s2);

// int GetMin(int a, int b, int c)
// {
// 	return std::min(std::min(a,b), c);
// }

// int ED_Recursive(int size1, int size2)
// {
// 	// if(size1 == 0 && size2 == 0)
// 	// {
// 	// 	return 0;
// 	// }

// 	// if((size1 == 0 && size2 != 0) ||
// 	// 	(size1 != 0 && size2 == 0))
// 	// {
// 	// 	if(size1 != 0) return 1 + ED_Recursive(size1-1, size2);
// 	// 	if(size2 != 0) return 1 + ED_Recursive(size1, size2-1);
// 	// }

// 	// ↑ algorithm can be improved into something ↓
// 	if(size1 == 0) return size2;
// 	if(size2 == 0) return size1;

// 	if(s1[size1-1] == s2[size2-1])
// 	{
// 		return ED_Recursive(size1-1, size2-1);
// 	}
// 	else
// 	{
// 		int op1 = 1 + ED_Recursive(size1, size2-1); //Insert
// 		int op2 = 1 + ED_Recursive(size1-1, size2); //Remove
// 		int op3 = 1 + ED_Recursive(size1-1, size2-1); //Replace

// 		return GetMin(op1, op2, op3);
// 	}
// }

// typedef std::pair<int, int> Coord;
// std::map<Coord, int> Memo;
// std::map<Coord, int>::iterator it;

// int ED_DP_Memo(int size1, int size2)
// {
// 	Coord p(size1, size2);

// 	if(size1 == 0) 
// 	{
// 		Memo[p] = size2;
// 		return size2;
// 	}
// 	if(size2 == 0) 
// 	{
// 		Memo[p] = size1;
// 		return size1;
// 	}

// 	if(s1[size1-1] == s2[size2-1])
// 	{
// 		Coord Nextp(size1-1, size2-1);
// 		it = Memo.find(Nextp);
// 		if(it != Memo.end())
// 		{
// 			Memo[p] = it->second;
// 		}
// 		else
// 		{
// 			Memo[p] = ED_DP_Memo(size1-1, size2-1);		
// 		}

// 		return Memo[p];
// 	}
// 	else
// 	{
// 		int op1 = 1 + ED_DP_Memo(size1, size2-1);
// 		int op2 = 1 + ED_DP_Memo(size1-1, size2);
// 		int op3 = 1 + ED_DP_Memo(size1-1, size2-1);

// 		Memo[p] = GetMin(op1, op2, op3);

// 		return GetMin(op1, op2, op3);
// 	}
// }

// int ED_DP_Tabulation(int size1, int size2)
// {
// 	int DP[M+1][N+1];

// 	for (int i(0); i <= size1; ++i)
// 	{
// 		for (int j(0); j <= size2; ++j)
// 		{
// 			if (i == 0)
// 			{
// 				DP[i][j] = j;				
// 			}
// 			else if (j == 0)
// 			{
// 				DP[i][j] = i;
// 			}
// 			else if(s1[i-1] == s2[j-1])
// 			{
// 				DP[i][j] = DP[i-1][j-1];
// 			}
// 			else
// 			{
// 				DP[i][j] = 1 + GetMin(DP[i][j-1], DP[i-1][j], DP[i-1][j-1]);
// 			}
// 		}
// 	}

// 	return DP[M][N];
// }

// int main(int argc, char *argv[])
// {
// 	std::clock_t start, end;	
// 	double duration;
    


//     start = std::clock();

// 	std::cout << ED_Recursive(M, N) << std::endl;
    
//     end = std::clock();
    
//    	duration = ( end - start ) / (double) CLOCKS_PER_SEC;
//    	std::cout << "Recursive duration: " << duration << std::endl;


//     start = std::clock();

// 	std::cout << ED_DP_Memo(M, N) << std::endl;
    
//     end = std::clock();
    
//    	duration = ( end - start ) / (double) CLOCKS_PER_SEC;
//    	std::cout << "Memoization duration: " << duration << std::endl;



//    	start = std::clock();

// 	std::cout << ED_DP_Tabulation(M, N) << std::endl;
    
//     end = std::clock();
    
//    	duration = ( end - start ) / (double) CLOCKS_PER_SEC;
//    	std::cout << "Tabulation duration: " << duration << std::endl;

// 	return 0;
// }



//-----------------------------------------------------------------------Mar 3rd 2016 Code
// #include <iostream>
// #include <iomanip>
// #include <algorithm>
// #include <ctime>
// #include <assert.h>
// #include <string>
// #include <cstdlib>

// int a[] = {3, 3, 3, 3, 4, 5, 6, 3};
// int M = sizeof(a) / sizeof(a[0]);

// int MP_Recursive (int size)
// {
// 	if(size == 1)
// 	{
// 		return a[0];
// 	}
// 	else
// 	{
// 		return std::min(std::abs(a[size-1] + MP_Recursive(size-1)), 
// 						std::abs(a[size-1] - MP_Recursive(size-1)));
// 	}
// }

// int MP_DP_BottomUp (int size)
// {
// 	int DP[size+1];
// 	std::fill_n(DP, size+1, 0);

// 	for(int i(1); i <= size; ++i)
// 	{
// 		if(i == 1)
// 			DP[i] = a[i-1];
// 		else
// 		{
// 			DP[i] = std::min(std::abs(a[i-1] + DP[i-1]), 
// 							 std::abs(a[i-1] - DP[i-1]));
// 		}
// 	}

// 	return DP[size];
// }


// int main(int argc, char *argv[])
// {
// 	std::clock_t 	start, end;
// 	double 			duration(0);

// 	start = std::clock();
// 	std::cout << MP_Recursive(M) << std::endl;
// 	end = std::clock();

// 	duration = ( end - start ) / (double) CLOCKS_PER_SEC;
//    	std::cout << "Recursion duration: " << duration << std::endl;

// 	start = std::clock();
// 	std::cout << MP_DP_BottomUp(M) << std::endl;
// 	end = std::clock();

// 	duration = ( end - start ) / (double) CLOCKS_PER_SEC;
//    	std::cout << "DP duration: " << duration << std::endl;


// 	return 0;
// }



//-----------------------------------------------------------------------Mar 5th 2016 Code
// #include <iostream>
// #include <assert.h>
// #include <iomanip>
// #include <cstdlib>
// #include <algorithm>
// #include <string>
// #include <ctime>

// //Minimum difference partition

// int arr[] = {3, 3, 3, 3, 4, 5, 6, 3};
// int M = sizeof(arr) / sizeof(arr[0]);
// int sum(0);


// int MP_Recursion(int xIndex, int sum1)
// {
// 	if(xIndex == -1)
// 	{
// 		return std::abs(sum1*2 - sum);
// 	}
// 	else
// 	{
// 		int res = std::min(MP_Recursion(xIndex-1, sum1),
// 							MP_Recursion(xIndex-1, sum1 + arr[xIndex]));
// 		return res;
// 	}
// }

// // The Dynamic programming approach is bit confusing, need to move on
// // int MP_DP_BottomUp()
// // {
// // 	int DP[M+1][sum+1];

// // 	for(int i(0); i < sum + 1; ++i)
// // 	{
// // 		DP[0][i] = std::abs(i*2 - sum);
// // 	}

// // 	for (int i(1); i < M + 1; ++i)
// // 	{

// // 	}

// // }

// int main(int argc, char *argv[])
// {
// 	for (int i(0); i < M; ++i)
// 	{
// 		sum += arr[i];
// 	}

// 	std::clock_t start, end;
// 	double duration(0);

// 	//Recursive Method
// 	start = std::clock();
// 	std::cout << MP_Recursion(M-1, 0) << std::endl;
// 	end = std::clock();
// 	duration = (end - start) / static_cast<double>(CLOCKS_PER_SEC);
// 	std::cout << "Recursive MP : " << duration << std::endl;


// 	//DP Bottom-up Method
// 	start = std::clock();

// 	end = std::clock();
// 	duration = (end - start) / static_cast<double>(CLOCKS_PER_SEC);
// 	std::cout << "MP bottom-up : " << duration << std::endl;



// 	return 0;
// }


// #include <iostream>
// #include <iomanip>
// #include <cstdlib>
// #include <assert.h>
// #include <algorithm>
// #include <string>

// int distance(4);

// int CD(int sum)
// {
// 	if(sum > distance)
// 	{
// 		return 0;
// 	}

// 	if(sum == distance)
// 	{
// 		return 1;
// 	}


// 	int res(0);
// 	for(int i(1); i <= 3; ++i)
// 	{
// 		res += CD(sum + i);
// 	}

// 	return res;
// }

// // This method is quite interesting
// // it is base on its corresponding recursive algo:
// // This algo is completely opposite version of my recursive method.

// int CP_Recursive(distance)
// {
// 	if(distance < 0)
// 		return 0;
// 	if(distance == 0)
// 		return 1;
// 	else
// 		return CP_Recursive(distance-1)+ // 1-step
// 			   CP_Recursive(distance-2)+ // 2-step
// 			   CP_Recursive(distance-3); // 3-step
// }


// int CP_DP()
// {
// 	int DP[distance + 1];

// 	DP[0] = 1; DP[1] = 1; DP[2] = 2;

// 	for(int i(3); i <= distance; ++i)
// 	{
// 		DP[i] = DP[i-1] + DP[i-2] + DP[i-3];
// 	}
// 	return DP[distance];
// }

// int main(int argc, char *argv[])
// {
// 	std::cout << CD(0) << std::endl;
// 	std::cout << CP_DP() << std::endl;
// 	return 0;
// }

// #include <iostream>
// #include <iomanip>
// #include <assert.h>
// #include <cstdlib>
// #include <algorithm>
// #include <string>

// #define N 3
// int mat[N][N] = {
// 					{1, 2, 9},
//                 	{5, 3, 8},
//                 	{4, 6, 7}
//                 };
// int max(1);


// void LP(int iIndex, int jIndex)
// {
// 	if(iIndex < N)
// 	{

// 	}

// 	for(int j(0); j < N; ++j)
// 	{
// 		LP(iIndex-1, j); // From bottom row to top
// 	}
// }


// int main(int argc, char *argv[])
// {
// 	std::cout << mat[-1][-1] << std::endl;
// 	return 0;
// }



//-----------------------------------------------------------------------Mar 6th 2016 Code
// #include <iostream>
// #include <iomanip>
// #include <assert.h>
// #include <cstdlib>
// #include <string>
// #include <ctime>

// int arr[] = {3, 12, 123, 245, 56, 34, 12, 45, 3, 4, 5, 7, 8, 32, 48};
// int M = sizeof(arr) / sizeof(arr[0]);
// int sum = 62;

// //Subset Sum = SS(int xIndex, int sum);

// bool SS_Recursive(int xIndex, int thisSum)
// {
// 	if(xIndex == -1)
// 		return thisSum == sum;

// 	bool res(false);
// 	res = SS_Recursive(xIndex-1, thisSum) || SS_Recursive(xIndex-1, thisSum + arr[xIndex]);
// 	return res;
// }

// bool SS_DP()
// {
// 	bool DP[sum+1][M+1];

// 	//if there is zero element in array
// 	for (int i(0); i <= sum; ++i)
// 		DP[i][0] = false;

// 	//if the sum is zero 
// 	for (int j(1); j <= M; ++j)
// 		DP[0][j] = true;

// 	//build up the DP
// 	for(int i(1); i <= sum; ++i)
// 	{
// 		for(int j(1); j <= M; ++j)
// 		{
// 			//if not adding arr[j-1] to the sum
// 			DP[i][j] = DP[i][j-1];
// 			//if the arr[j-1] is smaller or equal to the desired sum
// 			if(i >= arr[j-1])
// 			{
// 				DP[i][j] = DP[i][j-1] || DP[i-arr[j-1]][j-1];
// 			}
// 		}
// 	}

// 	return DP[sum][M];
// }

// int main(int argc, char *argv[])
// {
// 	std::clock_t start, end;
// 	double duration(0);

// 	start = std::clock();
// 	std::cout << SS_Recursive(M-1, 0) << std::endl;
// 	end = std::clock();
// 	duration = (end - start) / static_cast<double>(CLOCKS_PER_SEC);
// 	std::cout << "Recursive alogrithm : " << duration << std::endl;

// 	start = std::clock();
// 	std::cout << SS_DP() << std::endl;
// 	end = std::clock();
// 	duration = (end - start) / static_cast<double>(CLOCKS_PER_SEC);
// 	std::cout << "DP algorithm : " << duration << std::endl;

// 	return 0;
// }


//-----------------------------------------------------------------------Mar 7th 2016 Code
// #include <iostream>
// #include <iomanip>
// #include <assert.h>
// #include <cstdlib>
// #include <ctime>
// #include <string>

// int arr[] = {20, 30, 2, 2, 2, 10};
// int size = sizeof(arr) / sizeof(arr[0]);

// int OS(int i, int j)
// {
// 	if(j - i == 1)
// 	{
// 		return std::max(arr[i], arr[j]);
// 	}

// 	int left 	= arr[i] + std::min(OS(i+2, j),   OS(i+1, j-1));
// 	int right 	= arr[j] + std::min(OS(i+1, j-1), OS(i, j-2)); 

// 	return std::max(left, right);
// }


// int main(int argc, char *argv[])
// {	
// 	std::cout << OS(0, size-1) << std::endl;
// 	return 0;
// }



//-----------------------------------------------------------------------Mar 8th 2016 Code
// #include <iostream>
// #include <iomanip>
// #include <algorithm>
// #include <assert.h>
// #include <cstdlib>
// #include <string>
// #include <ctime>

// int val[] = {60, 100, 120};
// int wt[] = {10, 20, 30};
// int W = 50;
// int M = sizeof(val) / sizeof(val[0]);

// int Knapsack(int cap, int xIndex)
// {
// 	if(cap <= 0) return 0;
// 	if(xIndex <= -1) return 0;

// 	if(wt[xIndex] > cap) return Knapsack(cap, xIndex-1);

// 	return std::max(
// 			val[xIndex] + Knapsack(cap - wt[xIndex], xIndex-1),
// 			0 			+ Knapsack(cap, xIndex-1)
// 		);
// }

// int Knapsack_DP()
// {
// 	int DP[W+1][M+1];

// 	for (int i(0); i <= W; ++i)
// 	{
// 		DP[i][0] = 0;
// 	}

// 	for(int j(0); j <= M; ++j)
// 	{
// 		DP[0][j] = 0;
// 	}

// 	for(int i(1); i <= W; ++i)
// 	{
// 		for(int j(1); j <= M; ++j)
// 		{
// 			if(i < wt[j-1])
// 			{
// 				DP[i][j] = DP[i][j - 1];
// 			}
// 			else
// 			{
// 				DP[i][j] = std::max(val[j-1] + DP[i - wt[j-1]][j - 1], DP[i][j-1]);
// 			}
// 		}
// 	}
// 	return DP[W][M];
// }

// int main(int argc, char *argv[])
// {
// 	std::cout << Knapsack(W, M-1) << std::endl;
// 	std::cout << Knapsack_DP() << std::endl;
// 	return 0;
// }



//-----------------------------------------------------------------------Mar 9th 2016 Code
// #include <iostream>
// #include <iomanip>
// #include <assert.h>
// #include <cstdlib>
// #include <string>
// #include <algorithm>

// char symb[] = "TFT";
// char optr[] = "^&";

// int M = strlen(symb);
// int N = strlen(optr);

// //Boolean Parenthesization
// int BP(int symbSize, int symbolIndex)
// {
// 	switch(optr[operatorIndex])
// 	{
// 	case '&':

// 		break;

// 	case '|':
		
// 		break;
	
// 	case '^':
	
// 		break;
// 	}
// 	return 0;
// }

// int main(int argc, char *argv[])
// {
	
// 	return 0;
// }

// #include <iostream>
// #include <cstdlib>
// #include <string>
// #include <cstdlib>
// #include <algorithm>
// #include <assert.h>
// #include <limits.h>

// int arr[] = {2, 3, 4, 10, 40};
// int size = sizeof(arr) / sizeof(arr[0]);

// int LinearSearch(int n)
// {
// 	for(int i(0); i < size; ++i)
// 	{
// 		if(arr[i] == n)
// 			return i;
// 	}
// 	return -1;
// }

// int BinarySearch(int n, int start, int end)
// {
// 	if(end >= 1 && start != end)
// 	{
// 		int mid = (start + (end-1)) / 2;

// 		if(arr[mid] == n)
// 			return mid;
		
// 		if(arr[mid] > n)
// 			return BinarySearch(n, start, mid - 1);
		
// 		return BinarySearch(n, mid+1, end);
// 	}
// 	else if (start == end)
// 	{
// 		if(arr[start] == n)
// 			return start;
// 		else
// 			return -1;
// 	}
// 	return -1;
// }

// int BinarySearch_while(int n, int start, int end)
// {
// 	while(start < end)
// 	{
// 		int mid = (start + end-1) / 2;
// 		if(arr[mid] == n) return mid;
// 		if (arr[mid] > n) end = mid - 1;
// 		start = mid + 1;
// 	}
// 	if (arr[start] == n)
// 		return start;
// 	return -1;
// }

// int main(int argc, char *argv[])
// {
// 	std::cout << LinearSearch(10) << std::endl; 
// 	std::cout << BinarySearch_while(50, 0, size-1) << std::endl;
// 	return 0;
// }


//--------------------------------------------------------------------Mar 10th 2016 Code
// #include <iostream>
// #include <iomanip>
// #include <algorithm>
// #include <assert.h>
// #include <cstdlib>
// #include <string>

// // ACM 2013
// //Problem A - The End of The World is ed

// void TheEndOfTheWorld(std::string input)
// {
// 	std::string output;

// 	for (int i(0); i < input.size()-1; ++i)
// 	{
// 		if(input.at(i+1) == ' ')
// 		{
// 			output.push_back(input.at(i));
// 		}
// 		if((i+1) == (input.size() - 1))
// 		{
// 			output.push_back(input.at(i+1));	
// 		}
// 	}

// 	std::cout << output << std::endl;
// }

// int main(int argc, char *argv[])
// {
// 	int N(0);
// 	std::string input;

// 	std::cin >> N;
// 	std::cin.ignore(256, '\n');

// 	for (int i(0); i < N; ++i)
// 	{
// 		getline(std::cin, input);
// 		TheEndOfTheWorld(input);
// 	}

// 	return 0;
// }


// #include <iostream>
// #include <sstream>
// #include <fstream>
// #include <vector>
// #include <iomanip>
// #include <assert.h>
// #include <cstdlib>
// #include <string>
// #include <algorithm>
// #include <ctime>
// #include <utility>
// #include <map>
// #include <iterator>

// // ACM 2013
// //Problem B - Shoe
 
// typedef std::pair<int, int> Coord; // <int, int> = <# down the stack, column #>
// std::map<int, Coord> Hash;
// std::map<int, Coord>::iterator it;

// int main(int argc, char *argv[])
// {
// 	std::ifstream in("inputB.txt");
// 	std::string input;

// 	while(!in.eof())
// 	{
// 		int min (100000);

// 		for (int i(0); i < 5; ++i)
// 		{
// 			getline(in, input);
// 			std::istringstream iss(input);
// 			int a(0);
// 			int counter(0);
			
// 			while(iss >> a)
// 			{
// 				it = Hash.find(a);
// 				if(it == Hash.end()) // doesn't exist
// 				{
// 					Coord newNode = std::make_pair(counter, i);
// 					Hash[a] = newNode;
// 				}
// 				else // Hash[a] already exist
// 				{
// 					int result(0);
// 					if(it->second.second == i)
// 					{
// 						result = counter;
// 					}
// 					else
// 					{
// 						result = it->second.first + counter;
// 					}

// 					min = min < result ? min : result;
// 				}
// 				counter++;
// 			}
// 		}

// 		std::cout << min << std::endl;	
// 		// Must clear the filled hashtable from the last test case
// 		Hash.clear();
// 	}
	
// 	in.close();
// 	return 0;
// }


// #include <iostream>
// #include <sstream>
// #include <fstream>
// #include <iomanip>
// #include <string>
// #include <cstdlib>
// #include <algorithm>
// #include <assert.h>
// #include <ctime>
// #include <utility>
// #include <vector>

// // // ACM 2013
// // //Problem C - Trolls
// int **IslandMatrix;
// int NumOfIslands(0);

// bool Trolls(int island, int sum)
// {
// 	if(island == 0 && (sum >= 21 && sum <= 24))
// 		return true;
// 	if(sum > 24)
// 		return false;

// 	bool result(false);
// 	for(int i(0); i < NumOfIslands; ++i)
// 	{
// 		if(i != island)
// 		{
// 			result = Trolls(i, sum + IslandMatrix[island][i]) || result;	
// 		}
// 	}
// 	return result;
// }

// int main(int argc, char *argv[])
// {
// 	std::ifstream in("inputC.txt");
// 	// Number of tests
// 	int T(0);
// 	in >> T;

// 	for(int i(0); i < T; ++i)
// 	{
// 		//Number of Islands
// 		int N(0);
// 		in >> N;
// 		::NumOfIslands = N;

// 		// Creating the Island Matrix
// 		IslandMatrix = new int* [N];
// 		for(int row(0); row < N; ++row)
// 		{
// 			IslandMatrix[row] = new int [N];
// 		}

// 		// Stuffin the Island Matrix
// 		for (int row(0); row < N; ++row)
// 		{
// 			for(int col(0); col < N; ++col)
// 			{
// 				in >> IslandMatrix[row][col];
// 			}
// 		}

// 		// Processing
// 		std::cout << (Trolls(0, 4) ? "Yes" : "No") << std::endl;


// 		// Deleting the Island Matrix
// 		for(int row(0); row < N; ++row)
// 		{
// 			delete [] IslandMatrix[row];
// 			IslandMatrix[row] = NULL;
// 		}
// 		delete [] IslandMatrix;
// 		IslandMatrix = NULL;
// 	}

// 	return 0;
// }


//--------------------------------------------------------------------Mar 12th 2016 Code
// #include <iostream>
// #include <sstream>
// #include <fstream>
// #include <iomanip>
// #include <assert.h>
// #include <cstdlib>
// #include <string>
// #include <algorithm>
// #include <utility>
// #include <map>
// #include <limits.h>

// bool IsSorted(int *arr, int size)
// {
// 	bool resultA(true);
// 	int ascending(INT_MIN);
// 	bool resultD(true);
// 	int decending(INT_MAX);

// 	for(int i(0); i < size; ++i)
// 	{
// 		if(arr[i] < ascending && resultA == true)
// 			resultA = false;
// 		else
// 			ascending = arr[i];

// 		if(arr[i] > decending && resultD == true)
// 			resultD = false;
// 		else
// 			decending = arr[i];
// 	}

// 	return resultA || resultD;
// }

// // int main(int argc, char *argv[])
// // {
// // 	int arr1[] = {1, 2, 3, 4, 5}; //ascending sorted
// // 	int arr2[] = {5, 4, 3, 2, 0}; //decending sorted
// //  	int arr3[] = {3, 4, 1, 2, 0}; //unsorted

// // 	int size1 = sizeof(arr1) / sizeof(arr1[0]);
// // 	int size2 = sizeof(arr2) / sizeof(arr2[0]);
// // 	int size3 = sizeof(arr3) / sizeof(arr3[0]);

// // 	std::cout << IsSorted(arr1, size1) << std::endl;
// // 	std::cout << IsSorted(arr2, size2) << std::endl;
// // 	std::cout << IsSorted(arr3, size3) << std::endl;

// // 	return 0;
// // }

// bool BS(int *arr, int ele, int left, int right)
// {
// 	if(right >= left)
// 	{
// 		int mid = left + (right - left) / 2;
		
// 		if(arr[mid] == ele)
// 		{
// 			return 1;
// 		}

// 		if(arr[mid] > ele)
// 			return BS(arr, ele, left, mid - 1);
// 		else
// 			return BS(arr, ele, mid + 1, right);
// 	}

// 	return 0;
// }


// int main(int argc, char *argv[])
// {
// 	int arr[] = {2, 4, 5, 67, 344, 890};
// 	int size = sizeof(arr) / sizeof(arr[0]);

// 	if(IsSorted(arr, size))
// 	{
// 		std::cout << BS(arr, -12, 0, size - 1) << std::endl;

// 	}

// 	return 0;
// }














