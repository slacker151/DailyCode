Problem Description:

	Reverse an array without affecting special charaters.

	Given a string, that contains special character together 
	with alphabets('a' to 'z' and 'A' to 'Z'), reverse the
	string in a way that special characters are not affected.

	For example:

		Input:   str = "a,b$c"
		Output:  str = "c,b$a"
		Note that $ and , are not moved anywhere.  
		Only subsequence "abc" is reversed

		Input:   str = "Ab,c,de!$"
		Output:  str = "ed,c,bA!$"

Problem Solution:

	From the ASCII table, we can determine the range in 
	which 'a' to 'z' and 'A' to 'Z' lay in. 

	We also know that arrays are easier for element manipulations than strings are. 

	We can determine the length of the string using string.
	size().

	Now, we can use a while-loop conditions base on two 
	indices: front index and back index. While(front < back)

	


