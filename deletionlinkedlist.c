// A complete working C program
// to demonstrate deletion in
// singly linked list
#include <stdio.h>
#include <stdlib.h>
 
// A linked list node
struct Node {
    int data;
    struct Node* next;
};
 
/* Given a reference (pointer to pointer) to the head of a
   list and an int, inserts a new node on the front of the
   list. */
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node
        = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
 
/* Given a reference (pointer to pointer) to the head of a
   list and a key, deletes the first occurrence of key in
   linked list */
void deleteNode(struct Node** head_ref, int key)
{
    // Store head node
    struct Node *temp = *head_ref, *prev;
 
    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; // Changed head
        free(temp); // free old head
        return;
    }
 
    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
 
    // If key was not present in linked list
    if (temp == NULL)
        return;
 
    // Unlink the node from linked list
    prev->next = temp->next;
 
    free(temp); // Free memory
}
 
// This function prints contents of linked list starting
// from the given node
void printList(struct Node* node)
{
    while (node != NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
}
 
// Driver code
int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;
 
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
 
    puts("Created Linked List: ");
    printList(head);
    deleteNode(&head, 1);
    puts("\nLinked List after Deletion of 1: ");
    printList(head);
    return 0;
}




/*Output
Created Linked List: 
 2  3  1  7 
Linked List after Deletion of 1: 
 2  3  7  */








//Delete a Linked List node at a given position
/*Example:  

Input: position = 1, Linked List = 8->2->3->1->7
Output: Linked List =  8->3->1->7

Input: position = 0, Linked List = 8->2->3->1->7
Output: Linked List = 2->3->1->7 */


// Simple C code to delete node at particular position

#include<stdio.h>
#include<stdlib.h>

void insert(int );
void display_List();
void delete(int );

struct node			 // Structure declaration
{
	int data;
	struct node *next; // Self referral pointer
}*head=NULL,*tail=NULL; // Initial value of Head and Tail pointer is NULL


void delete(int pos)
{
	struct node *temp = head;	 // Creating a temporary variable pointing to head
	int i;					
	if(pos==0)
	{
		printf("\nElement deleted is : %d\n",temp->data);
		head=head->next;	 // Advancing the head pointer
		temp->next=NULL;
		free(temp);			 // Node is deleted
	}
	else
	{
		for(i=0;i<pos-1;i++)
		{
			temp=temp->next;
		}
		// Now temp pointer points to the previous node of the node to be deleted
		struct node *del =temp->next;	 // del pointer points to the node to be deleted
		temp->next=temp->next->next;
		printf("\nElement deleted is : %d\n",del->data);	
		del->next=NULL;
		free(del);						 // Node is deleted
	}
	printf("\nUpdated Linked List is : \n");
	display_List();
	return ;
}



void insert(int value)
{
	struct node *newnode; // Creating a new node
	newnode = (struct node *)malloc(sizeof(struct node)); // Allocating dynamic memory

	newnode->data = value;	 // Assigning value to newnode
	newnode->next = NULL;	

	if(head==NULL)	 // Checking if List is empty
	{
		head = newnode;
		tail = newnode;
	}
	else			 // If not empty then...
	{
		tail->next=newnode;	
		tail=newnode;	 // Updating the tail node with each insertion
	}
	return ;
}

void display_List()
{
	struct node *temp; // Creating a temporary pointer to the structure
	temp=head;		 // temp points to head;
	while(temp!=NULL)
	{
		if(temp->next==NULL)
		{
			printf(" %d->NULL",temp->data);
		}
		else
		{
			printf(" %d->",temp->data);
		}
		temp=temp->next;		 // Traversing the List till end
	}
	printf("\n");
	return ;
}
// --Driver Code--
int main()
{
	insert(10);
	insert(20);
	insert(30);
	insert(40);
	insert(50);
	insert(60);
	printf("\n--Created Linked List--\n");
	display_List();
	printf("\nLinked List after deletion at position 0");
	delete(0);								 // List indexing starts from 0
	printf("\nLinked List after deletion at position 2");
	delete(2);
	return 0;
}
// This code is contributed by Sanjeeban Mukhopadhyay.



/*Output: 

--Created Linked List--
 10-> 20-> 30-> 40-> 50-> 60->NULL      

Linked List after deletion at position 0
Element deleted is : 10

Updated Linked List is : 
 20-> 30-> 40-> 50-> 60->NULL

Linked List after deletion at position 2
Element deleted is : 40

Updated Linked List is : 
 20-> 30-> 50-> 60->NULL */
