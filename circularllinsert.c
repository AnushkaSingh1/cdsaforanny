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
struct Node *addEnd(struct Node *last, int data)
{
if (last == NULL)
	return addToEmpty(last, data);

// Creating a node dynamically.
struct Node *temp =
		(struct Node *)malloc(sizeof(struct Node));

// Assigning the data.
temp -> data = data;

// Adjusting the links.
temp -> next = last -> next;
last -> next = temp;
last = temp;

return last;
}

/*To insert a node in between the two nodes, follow these steps: 
1. Create a node, say T. 
2. Search for the node after which T needs to be inserted, say that node is P. 
3. Make T -> next = P -> next; 
4. P -> next = T.
*/

struct Node *addAfter(struct Node *last, int data, int item)
{
	if (last == NULL)
	return NULL;

	struct Node *temp, *p;
	p = last -> next;

	// Searching the item.
	do
	{
		if (p ->data == item)
		{
			// Creating a node dynamically.
			temp = (struct Node *)malloc(sizeof(struct Node));

			// Assigning the data.
			temp -> data = data;

			// Adjusting the links.
			temp -> next = p -> next;

			// Adding newly allocated node after p.
			p -> next = temp;

			// Checking for the last node.
			if (p == last)
				last = temp;

			return last;
		}
		p = p -> next;
	} while (p != last -> next);

	cout << item << " not present in the list." << endl;
	return last;
}

//The following is a complete program that uses all of the above methods to create a circular singly linked list.
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
};

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

	// Creating the link.
	last -> next = last;

	return last;
}

struct Node *addBegin(struct Node *last, int data)
{
	if (last == NULL)
		return addToEmpty(last, data);

	struct Node *temp =
			(struct Node *)malloc(sizeof(struct Node));

	temp -> data = data;
	temp -> next = last -> next;
	last -> next = temp;

	return last;
}

struct Node *addEnd(struct Node *last, int data)
{
	if (last == NULL)
		return addToEmpty(last, data);
	
	struct Node *temp =
		(struct Node *)malloc(sizeof(struct Node));

	temp -> data = data;
	temp -> next = last -> next;
	last -> next = temp;
	last = temp;

	return last;
}

struct Node *addAfter(struct Node *last, int data, int item)
{
	if (last == NULL)
		return NULL;

	struct Node *temp, *p;
	p = last -> next;
	do
	{
		if (p ->data == item)
		{
			temp = (struct Node *)malloc(sizeof(struct Node));
			temp -> data = data;
			temp -> next = p -> next;
			p -> next = temp;

			if (p == last)
				last = temp;
			return last;
		}
		p = p -> next;
	} while(p != last -> next);

	cout << item << " not present in the list." << endl;
	return last;

}

void traverse(struct Node *last)
{
	struct Node *p;

	// If list is empty, return.
	if (last == NULL)
	{
		cout << "List is empty." << endl;
		return;
	}

	// Pointing to first Node of the list.
	p = last -> next;

	// Traversing the list.
	do
	{
		cout << p -> data << " ";
		p = p -> next;

	}
	while(p != last->next);

}

// Driven Program
int main()
{
	struct Node *last = NULL;

	last = addToEmpty(last, 6);
	last = addBegin(last, 4);
	last = addBegin(last, 2);
	last = addEnd(last, 8);
	last = addEnd(last, 12);
	last = addAfter(last, 10, 8);

	traverse(last);

	return 0;
}



//Output:  

//2 4 6 8 10 12
