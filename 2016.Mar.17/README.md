Problem Description:

	Given a sorted array and a number x, find a pair in array whose sum is closest to x.

Problem Solution:

	Off the top of my head, creating a min_diff and a hash table with min_diff key type.

	Turns out, I got it on the first try. It is very similar to the selection sort algorithm. However, keeping track of which pair has the least difference from the provided value. Obviously, comparing one sum at a time doesn't really require the Hash table.
	