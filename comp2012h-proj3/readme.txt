/**********************************************************************
 *  Randomized Queues and Deques
 **********************************************************************/

Name:	LIU Qinhan
ID:		20328953
Login:	
Hours to complete assignment (optional):
		12 hrs

/**********************************************************************
 *  Explain briefly how you implemented the randomized queue and deque.
 *  Which data structure did you choose (array, linked list, etc.)
 *  and why?
 **********************************************************************/
PUT YOUR ANSWER HERE

For deque, I selected linked list to implement. Because the time complexity of adding and removing operation for a linked list is O(1) and the total memory taken up by the list is poportional to the number of elements inside. Moreover, the space used by an iterator is constant which equals the space taken by a pointer to a node in the list.

For randomized queue, I selected array to implement. Then each adding or removing operation takes time proportional to the number of elements the queue contains, which indicates that the time complexity of such operations is O(n). The space for an iterator is also linear.

/**********************************************************************
 *  Briefly describe why any sequence of N randomized queue operations,
 *  starting from an empty randomized queue, takes O(N) time.
 **********************************************************************/
PUT YOUR ANSWER HERE

Initialy an array of size 2 is created and then in the beginning of each operation of a randomized queue (e.g. adding, removing) it would check the number of elements currently inside the queue and once the size hits the boundry of the range [size/4,size], a new array with "new size" of size/2 or 2*size would be allocated and all the elements would be copied into this new array. In such way, the time for N sequencial operations would take averaged O(n) time.

/**********************************************************************
 *  Briefly describe why each Deque operation takes O(1) time.
 **********************************************************************/
PUT YOUR ANSWER HERE

For each deque operation merely have to access one exact node of the linked list, and do modification (e.g. adding, removing).

/**********************************************************************
 *  How much memory (in bytes) does your data type use to store N items.
 *  Use tilde notation to simplify your answer. Use the memory requirements
 *  for a "typical machine" given in Lecture. In your analysis, don't include
 *  the memory for the items themselves (as this memory is allocated by
 *  the client and depends on the item type.
 *  For a typical machine, refer to page 11 of 
 *  https://www.cs.princeton.edu/courses/archive/spr10/cos226/lectures/02-14Analysis-2x2.pdf
 **********************************************************************/

RandomizedQueue:
		~24 bytes
Dequeue:
		~36 bytes

/**********************************************************************
 *  Known bugs / limitations.
 **********************************************************************/


/**********************************************************************
 *  List whatever help (if any) that you received and from whom,
 *  including help from staff members or lab TAs.
 **********************************************************************/

I discussed with LEI Zhao about how to meet the requirement of using constant or linear time and space, and worked out which data structure should be implemented for this project.

I also recieved help from BAI Jiaxin of figuring out how to design the mechanism of modifying the size of the array for a randomized queue.  

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/

For a template class, you cannot simply seperate the interface and implementation like an ordinary one. Initially I did not know this, and found out so many unreadable bugs in the .cpp file.

/**********************************************************************
 *  List any other comments here. Feel free to provide any feedback   
 *  on how much you learned from doing the assignment, and whether    
 *  you enjoyed doing it.                                             
 **********************************************************************/
