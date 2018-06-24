#include<bits/stdc++.h>
using namespace std;
class Node
{
	private:
		int data;
		Node *next;
	public:
		Node(int);
		friend class Queue;
};
Node::Node(int data)
{
	this->data=data;
	this->next=NULL;
}
class Queue
{
	private:
		Node *rear;
		Node *front;
	public:
		Queue();
		//bool full();
		bool empty();
		void enqueue(int);
		int dequeue();
		void display_queue();
};
Queue::Queue()
{
	rear=NULL;
	front=NULL;
}
bool Queue::empty()
{
	//if front NULL
	return (front==NULL);
}
void Queue::enqueue(int data)
{
	Node *curr_node=new Node(data);
	if(empty())
	{
		front=curr_node;
		rear=curr_node;
		//no other linking
		return;
	}
	rear->next=curr_node;
	rear=curr_node;
	rear->next=front;
}
int Queue::dequeue()
{
	if(empty())
	{
		printf("Queue underflow\n");
		return -1;
	}	
	int value;
	if (front == rear)
    	{
       		value = front->data;
        	free(front);
        	front = NULL;
        	rear = NULL;
    	}
	else  // There are more than one nodes
    	{
        	struct Node *temp = front;
        	value = temp->data;
        	front = front->next;
        	rear->next=front;
        	free(temp);
    	}
	return value;
}
void Queue::display_queue()
{
	printf("The values is the queue:\n");
	struct Node *traverse_node=front;
	for(;traverse_node->next!=front;traverse_node=traverse_node->next)
	{
		printf("%d->",traverse_node->data);
	}
	printf("%d",traverse_node->data);
	printf("\n");
}
int main()
{
	Queue my_queue;
	my_queue.enqueue(11);
	my_queue.enqueue(12);
	my_queue.enqueue(13);
	my_queue.display_queue();
	printf("The element dequeued %d\n",my_queue.dequeue());	
	printf("The element dequeued %d\n",my_queue.dequeue());
	printf("The element dequeued %d\n",my_queue.dequeue());
	return 0;
}
