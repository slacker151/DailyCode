Problem Desctiption:

	Hashing

	Suppose we wanto desing a system for storing employee records 
	keyed using phone numbers, And we want following queries to be performed efficiently:

		1. Insert a phone number nad corresponding information
		2. Search a phone number and fetch the information
		3. Delete a phone number and related information

	We can think of using the following data structures to maintain information about different phone numbers.

		1. Array of phone numbers and records.
		2. Linked list of phone numbers and record.
		3. Balanced binary search tree with phone numbers as keys
		4. Direct Access Table


Problem Solution:

	For arrarys and linked list, we need to search in linear fashion, which can be costly in practice. If we use arrays and keep the data sorted, then a phone number can be searched in O(logn) time using Binar Search, but insert and delete become costly as we have to maintain sorted order.

	With balance binary search tree, we get moderate search, insert and delete times. All of these operations can be guaranteed to be in O(logn) time.

	Another solution that one can thingk of is to use a direct access table where we make a multi-dimensional array and use phone numbers as index in the arrays. Time complexity wise, this solution is the best among all, we can do all operations in O(1) time. For example to inset a phone number, we create a record with details of given phone number, use phone number as index and store the pointer to the created record in table. However, there are many practical limitations. First problme with this solution is extra space required is huge. For example if phone number is n digits, we need O(n * 10^n), where m is the is size of a pointer to record.


	After all, Hashing is the solution that can be used in almost all such situations and performs extrmemly well compare to above data structures like Array, linked list, balance BST in proactice. With hash, we get O(1) search time on average and O(n) in worse.

	Hashing is an improvement over Direct Access Table. The idea is to use hash function the converts a given phone number or any other key to a smaller number and uses the small number as index in a table called hash table.

	Hash function: 
	A function that converts a given big phone number o a small proactical integer value. The mapped integer value is used as an index in hash table. In simple terms, a hash function maps a big number or string to a small integer that can be used as index in hash table.

	Hash table: 
	A array that sotred pointers to record corresponding to a given phone number. A entry in hash table is NIL if no existing phone number has hash fucntion value equal to the index for the entry.

























