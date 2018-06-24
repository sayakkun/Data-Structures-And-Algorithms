#include <bits/stdc++.h>
using namespace std; 
// Structure of a Node
struct Node
{
	int data;
    	struct Node* next;
};
 
struct Queue_Node
{
    	struct Node *front, *rear;
};
 
// Function to create Circular queue
void enqueue(Queue_Node *q, int value)
{
	struct Node *temp = new Node;
    	temp->data = value;
    	if (q->front == NULL)
        {
		q->front = temp;
	}
    	else
        {
		q->rear->next = temp;
 	}
    	q->rear = temp;
   	q->rear->next = q->front;
}
 
// Function to delete element from Circular Queue
int deQueue(Queue_Node *q)
{
	if(q->front == NULL)
    	{
        	printf ("Queue is empty");
        	return INT_MIN;
    	}
 
    	// If this is the last node to be deleted
    	int value; // Value to be dequeued
    	if (q->front == q->rear)
    	{
        	value = q->front->data;
        	free(q->front);
        	q->front = NULL;
        	q->rear = NULL;
    	}
   	else  // There are more than one nodes
    	{
        	struct Node *temp = q->front;
        	value = temp->data;
        	q->front = q->front->next;
        	q->rear->next= q->front;
        	free(temp);
    	}
 	return value ;
}
 
// Function displaying the elements of Circular Queue
void display_queue(struct Queue_Node *q)
{
	struct Node *temp = q->front;
    	printf("Elements in Circular Queue are: ");
    	while (temp->next != q->front)
    	{
        	printf("%d->", temp->data);
        	temp = temp->next;
    	}
    	printf("%d", temp->data);
	printf("\n");
}
/* Driver of the program */
int main()
{
    	// Create a queue and initialize front and rear
	Queue_Node *q = new Queue_Node;
    	q->front = q->rear = NULL;
	// Inserting elements in Circular Queue
    	enqueue(q, 14);
    	enqueue(q, 22);
    	enqueue(q, 6); 
    	// Display elements present in Circular Queue
    	display_queue(q);
    	// Deleting elements from Circular Queue
    	printf("Deleted value = %d\n", deQueue(q));
    	printf("Deleted value = %d\n", deQueue(q));
    	// Remaining elements in Circular Queue
    	display_queue(q);
    	enqueue(q, 9);
    	enqueue(q, 20);
    	display_queue(q); 
    	return 0;
}
