//Initially, when the list is empty, the last pointer will be NULL. 
struct Node *addToEmpty(struct Node *last, int data)
{
	// This function is only for empty list
	if (last != NULL)
	return last;

	// Creating a node dynamically.
	struct Node *temp =
		(struct Node*)malloc(sizeof(struct Node));

	// Assigning the data.
	temp -> data = data;
	last = temp;
	// Note : list was empty. We link single node
	// to itself.
	temp -> next = last;

	return last;
}



/*To insert a node at the beginning of the list, follow these steps: 
1. Create a node, say T. 
2. Make T -> next = last -> next. 
3. last -> next = T. */

struct Node *addBegin(struct Node *last, int data)
{
if (last == NULL)
	return addToEmpty(last, data);

// Creating a node dynamically.
struct Node *temp
		= (struct Node *)malloc(sizeof(struct Node));

// Assigning the data.
temp -> data = data;

// Adjusting the links.
temp -> next = last -> next;
last -> next = temp;

return last;
}



/*To insert a node at the end of the list, follow these steps: 
1. Create a node, say T. 
2. Make T -> next = last -> next; 
3. last -> next = T. 
4. last = T. 
	
	*/