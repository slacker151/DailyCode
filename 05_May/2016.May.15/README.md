Problem Description:

	Binary Heap

	1. It's a complete tree (all levels are completely filled except
		for possibly the last level and the last level has all keys
		as left as possible). This property of Binary Heap makes them
		suitable to be stored in an array. 
	
	2. Binary Heap is either Min Heap or Max Heap. In a Min Binary 
		Heap, the key at root must be minimum among all keys present 
		in Binary Heap. The same property must be recursively true 
		for all nodes in Binary Tree. Max Binary Heap is similar to 
		Min Heap.

	Applications of Heaps:

	1. Heap Sort: O(nlogn)
	2. Priority Queue: insert(), delete(), extractMax() O(logn)
	3. Graph Algorithm: Priority Queue is used in Dijkstra's Path
	4. Problems that can be solved easily using heap:
		a) K'th largest element in an array
		b) Sort and almost sorted array
		c) Merge K sorted arrays

	Operation times of Heap:

	1. insert() 		O(log n)
	2. delete() 		O(log n)
	3. getMin() 		O(1)
	4. extractMin() 	O(log n)


Problem Solution:

	The most important part of a binary heap are "Insert()" and
	"Delete()".

	Insert: Assign the last element to the newly inserted value, then 
			check recursively for if its parent is larger or smaller 
			than itself for MinHeap and MaxHeap, respectively. If so, swap the two elements from the same array until either it
			has reached the root of the heap or the parent is smaller
			or larger than that element for MinHeap and MaxHeap, 
			respectively.

	Delete: Since there is gonna be one less element from the list 
			and the first element if gonna be deleted, we can swap 
			the first element with the last element in the list. Then
			we need to reorder the list because the last element is 
			defintely not the smallest or largest element in the list
			for a MinHeap or MaxHeap, respectively. From there, we 
			can determine the smallest element between its left and 
			right child recursively. Until, it has reached the heap 

	Time complexity:
			The time complexity for both of these operations is 
			O(logn) because heap is a binary tree. The operations are
			shortened because of branching of a complete binary tree.

			
