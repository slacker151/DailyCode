Problem Description:

	Given a string, print all possible palindromic partitions

	Example:

	Input: nitin
	Output: n i t i n
			n iti n
			nitin

	Input: geeks
	Output: g e e k s
			g ee k s

Problem Solution:

	I find the solution to this problem to be quite straightforward. At least, right at the beginning.

	My idea:

		We start from partition of size 1 and end on partition of size of the string (the whole string as a partition)

		For each partition, pass it through a parlindrom checking function with returning type of boolean.
		If the function returns true, print out that partition. Else, print out just the head character. Move on to the next partition starting with the next character in string.

		However, what if the string is like "jititim", then "j iti t i m", "j i tit i m", and "j i t iti m" are all valid for partition size of 3. 