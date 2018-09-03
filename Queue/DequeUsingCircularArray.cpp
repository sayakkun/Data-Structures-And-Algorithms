#include<bits/stdc++.h>
using namespace std;
#define MAX 100
class Deque
{
	private:
		int  arr[MAX];
    		int  front;
    		int  rear;
    		int  size;
	public:
		Deque(int);
		bool full();
		bool empty();
		void push_front(int);
		void push_back(int);
		int pop_front();
		int pop_back();
};
Deque::Deque(int size)
{
	this->front=-1;
        this->rear = 0;
        this->size = size;
}
bool Deque::full()
{
	return ((front == 0 && rear == size-1)||(front == rear+1));
	//Now, understand the first case, 
	/*
	First case:
		when no element is deleted
		so, after first insertion front will be 0 and remained as 0, as there were only insertion or enqueue
		Now, this condition is deque irrespective whether the queue is a normal queue using circular array or a dequeue using 
		circular array
	*/
	/*	
	Second case:
		Now, this is when circularity nature of it takes more role (again, this condition 
		is irrespective of whether it's a normal queue or deque
		So, suppose, 
		array size is 5
		1 2 3 4 5 IS inserted
		Now, 1 is deleted
		Now, for better space utilization, we use circular array
		Now, front will be 1 and rear will be 4
		Now, queue is not still full
		Now, we insert at 0th place
		the place from where we delete the element
		Now, rear will be 0 and front will remain 1 -> Now, in this case, it will still be full
		Now, in such case, the second condition plays a role
	*/
			
}
bool Deque::empty ()
{
    return (front == -1);
}
void Deque::push_front(int key)
{
	// check whether Deque if  full or not
    	if (full())
    	{
        	cout << "Queue Overflow\n" << endl;
        	return;
    	}
   	// If queue is initially empty
    	if (front == -1)
    	{
        	front = 0;
        	rear = 0;
    	}
 	//first, front is changed
	//then, insertion is done
    	// front is at first position of queue
    	else if (front == 0)
        {
		
		front = size - 1;
 	}
	/*
		this condition: Now, very first insertion was already done
		Now, irrespective of whether it will be push_front or push_back
		it will be same
		But, for next insertion using push_front it would be from size-1 normal array's last position
	*/
   	else // decrement front end by '1'
	{
		//the very first insertion is done
		//after that another push_front is done
		//now, for continuous push_front, we have to decrement front before every insertFront
		//because, since, it starts from MAX-1 after the very first push_front or push_back
        	front = front-1;
 	}
    	// insert current element into Deque
    	arr[front]=key;
}
void Deque ::push_back(int key)
{
	if (full())
    	{
        	cout << "Queue Overflow\n " << endl;
        	return;
    	}
    	// If queue is initially empty
    	if (front == -1)
    	{
        	front = 0;
       	 	rear = 0;
    	}
    	// rear is at last position of queue
    	else if (rear == size-1)
        {
		//it will reach the other end due to circularity
		rear = 0;
 	}
    	// increment rear end by '1'
    	else
        {
		rear = rear+1;
 	}
    	// insert current element into Deque
	//we first prepare the position
    	arr[rear] = key ;
}
int Deque ::pop_front()
{
    // check whether Deque is empty or not
	if (empty())
    	{
        	throw  "Queue Underflow";
    	}
 	int elem=arr[front];
	//take the element
	if(front==size-1)
	{
		front=0;
	}
	else
	{
		front=front+1;
	}
	//now, we have to check if queue becomes empty
	if(front==rear)
	{
		//it has to be done here to make queue empty	
       	 	front = -1;
       	 	rear = -1;
    	}
	return elem;
} 
// Delete element at rear end of Deque
int Deque::pop_back()
{
	if(empty())
    	{
        	throw "Queue Underflow";
    	}
	int elem=arr[rear];
	if(rear==0)
	{
		rear=size-1;
	}
	else
	{
		rear=rear-1;
	}	
    	//Now, we  have to check if queue becomes empty
    	if (front == rear)
    	{
        	front = -1;
        	rear = -1;
		//this is to be done, to make queue empty for next pop_rear or pop_front
    	}
	return elem;
}
int main()
{	
	Deque my_deque(5);
	/*write your own test case*/		
	my_deque.push_back(1);
	/*
	front: 0
	rear: 0
	*/	
	my_deque.push_back(2);
	/*front: 0
	rear: 1
	*/
	my_deque.push_back(3);
	/*front: 0
	rear: 1
	*/
	my_deque.push_back(4);
	/*front: 0
	rear: 4
	*/
	my_deque.push_back(5);
	/*
	front: 0
	rear: 5*/
	printf("The element which is popped from front(should be 1): %d\n",my_deque.pop_front());
	/*
	front: 1
	rear: 5*/
	printf("The element which is popped from back(should be 5): %d\n",my_deque.pop_back());
	/*front: 1
	rear: 4*/
	printf("The element which is popped from front(should be 2): %d\n",my_deque.pop_front());
	/*front: 2
	rear: 3
	*/
	my_deque.push_back(6);
	/*front: 2
	rear: 4
	*/
	my_deque.push_back(7);
	/*front: 2
	rear: 5
	*/
	my_deque.push_back(8);
	/*front: 2
	rear: 0*/
	printf("The element which is popped from back(should be 8) : %d\n",my_deque.pop_back());
	/*the rear end contains the element as 8
	it will be popped
	front: 2
	rear: 4
	*/
	printf("The element which is popped from front(should be 3) :%d\n",my_deque.pop_front());
	/*front: 3
	rear: 4
	*/
	return 0;
}
