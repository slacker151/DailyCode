Problem Description:

	Reservoir Sampling

		Reservoir sampling is a family of randomized algorithms 
		for randomly choosing k samples from a list n items, 
		where n is either a very large or unknown number. 
		Typically n is large enough that the list doesn't fit 
		into main memory. For example, a list of search 
		queries in Google and Facebook.

		So we are given a big array of numbers, so we need to write 
		an efficient function to randomly select k numbers where 1 <
		= k <= n. Let the input array be stream[].


Problem Solution:

	A simple solution is to create an array reservoir[] of maximum 
	size k. One by one randomly select an item from stream[0...n-1].
	If the selected item is not previously selected, then put it 
	in reservoir[]. To check if an item is previously selected or 
	not, we need to search the item in reservoir[]. The time 
	complexity of this algorithm will be O(k^2). This can be costly 
	if k is big. Also, this is not efficient if the input is in the 
	form of stream.

	A more efficient solution would be: It can be solved in O(n) 
	time. Firstly, assign the reservoir[] with partial of stream[]. 
	Then for the unassigned portion of stream[], the program 
	generates j = rand() % (index + 1), if this number is smaller 
	than K, then we update the reservoir[j] = stream[j].
