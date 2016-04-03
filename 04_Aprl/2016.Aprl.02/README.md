Problem Description:

	Select a random node from a singly linked list

	Given a singly linked list, select a random node from linked 
	list (the probability of picking a node should be 1/N if there
	are N noded in the linked list). You are given a random number
	generator

Problem Solution:

	There is a quite simpel solution to this problem, traverse the whole linked list to determine the total number of nodes in the list. Next, generate a random number ranges from 0 to N - 1. Then traverse to the linked list with that index and return the node. Q.E.D.

	How to select a random node with only one traverse??

		The idea is to use Reservoir Sampling.

		There will be another topic mainly attributed to Resrvoir Sampling. 

		However, instead of having multiple keys, there is only one key for this case, as we only need to get one random node in the linked list.

		The procedures are as follow:

			1. Set the head->data as the result
			2. Iterate through the list
			3. For each iteration, we check whether a new rand() 
				% (n+1) is equal to 0, if so, update result to 
				the data of that node of that iteration. N is 
				the index of node in the list, count starts from
				1.
	
		Thoughts on the reservoir algorithm:

			Although it seems like there is a 1/N chances that a node can be selected, the N value varies for each node. As a result, the earlier node has a higher chance of getting selected compared to the nodes in the back of the list. Then I thought about it even more - although there is higher chance for the earlier nodes to be updated as the result, there is a also a higher chance for the result to be updated as other values along with the traversal. 