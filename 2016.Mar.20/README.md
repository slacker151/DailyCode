Problem Description:

	Compare two strings represented as LL

	Given two linked lists, represented as linked lists(every character is a node is linked list). Write a function compare() that works similar to strcmp(), i.e., it returns 0 if both strings are same, 1 if first linked list is lexicographically greater, and -1 if second string is lexicographically greater.


Problem Solution:

	The solution for this problem is extremely easy. While both linked list are still not empty, if the present nodes are different, if LL1 node is greater than LL2 node, then return 1, else return -1. Once we exist from the while-loop, we check if either LL is still not empty, return 1 if LL1 is still not empty, -1, if LL2 is still not empty.