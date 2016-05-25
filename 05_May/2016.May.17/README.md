Problem Description

	Huffman Compression Algorithm

	Huffman coding is a lossless data compression algorithm. The idea is to assign variable-lenght codes to input characrers, lengths of the assign codes are based on the frequencies of corresponding characters. The most frequency characer gets the smallest code and the least frequency character gets the largest code.

	The variable-length codes assigned to code assigned to one character is not prefix of code assigned to any other charater. This is how Huffman Coding makes sure that there is no ambiguity when decoding the generated bit-stream.

	Let us understand prefix codes with a counter example. Let there be four characters a, b, c and d, and their corresponding variable length codes be 00, 01, 0 and 1. This coding leads to ambiguity because code assigned to c is prefix of codes assigned to a and b. If the compressed bit stream is 0001, the de-compressed output may be “cccd” or “ccb” or “acd” or “ab”.

Problem Solution
	
	1. First, insert minHeapNode(char data, int freq) into a minHeap
	2. Second, combine two lowest freq nodes into a new single node with left and right nodes and insert back to the minHeap
	3. Third, repeat step 2 until there is only 1 node left on the minHeap
	4. Fourth, print out the compression with left branch appending "0" and right branch appending "1"