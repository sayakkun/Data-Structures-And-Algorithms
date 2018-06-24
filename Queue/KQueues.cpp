#include<bits/stdc++.h>
using namespace std;
//we can make it more complex: like make it generic and so on. Let's just make this simple
class KQueues
{
	private:
		int n;
		int k;
		int *arr;
		int *next;
		int *front;
		int *rear;
		int free;
	public:
		KQueues(int,int);
		//you can make it private,too
		bool empty(int);
		//you can make it private, too
		bool full();
		void enqueue(int,int);
		int dequeue(int);
		//void print_next();	
};
KQueues::KQueues(int k,int n)
{
	if(k<0)
	{
		throw "K cannot be <0";
		//again, we make this necessarily simple
		//I can do the following throw exception("K cannot be <0");
		//and during exception handling, I could print it like printf("The exception is: %s\n",e.what());
	}
	if(n<0)
	{
		throw "n cannot be <0";
	}
	if(n<k)
	{
		throw "The number of elements in the array cannot be < than the number of queues";
	}
	//in c++, the function need not to contain the statement throws some exception
	//it can contain throw statement for specifying type list for exceptions
	this->k=k;
	this->n=n;
	this->arr=NULL;
	try
	{
		this->arr=new int[this->n];
	}
	catch(const bad_alloc &e)
	{	
		//bad_alloc is one of nine sstandard exceptions
		//gives when we cannot allocate more memory from heap
		throw "Memory can not be allocated for arr";
	}
	this->next=NULL;
	try
	{
		this->next=new int[this->n];
	}
	catch(const bad_alloc &e)
	{
		throw "Memory cannot be allocated for next";
	}
	this->front=NULL;
	try
	{
		this->front=new int[this->k];
		//front for k queues
	}
	catch(const bad_alloc &e)
	{
		throw "Memory cannot be allocated for front";
	}
	this->rear=NULL;
	try
	{
		this->rear=new int[this->k];
		//rear for k queues
	}
	catch(const bad_alloc &e)
	{
		throw "Memory cannot be allocated for rear";
	}
	//Now, arr, next, front, rear these are defined
	//it's time for initializing them
	this->free=0;
	//starting free index is 0
	for(int i=0;i<this->n-1;i++)
	{
		this->next[i]=i+1;
	}
	this->next[this->n-1]=INT_MAX;
	//to indicate that no longer a free index is avialable
	for(int i=0;i<this->k;i++)
	{
		this->front[i]=-1;
	}
	//make every front element -1 indicating initially all queues are empty
}
bool KQueues::empty(int qi)
{
	if(qi<0||qi>=k)
	{
		throw "queue index is out of bounds";
	}
	return (front[qi]==-1);
}
bool KQueues::full()
{
	return (free==INT_MAX);
}
void KQueues::enqueue(int qi,int elem)
{
	if(qi<0||qi>=k)
	{
		throw "queue index is out of bound";
	}
	if(full())
	{	
		//we will not throw exception here
		printf("Queue overflow\n");
		return;
	}
	int curr_free_index=free;
	//free should be updated
	free=next[free];
	//free should be updated to the next free index
	arr[curr_free_index]=elem;
	//store the actual element
	if(empty(qi))
	{
		front[qi]=curr_free_index;
		rear[qi]=curr_free_index;
		next[curr_free_index]=-1;	
		//make the index stored as current front
		//otherwise, front is not going to be changed
	}
	
	//however, for quickness, either make empty function inline or just replace the if block as
	/*
 * 	if(empty(qi))
 * 	{
 * 		front[qi]=curr_free_index
 *	}
 * 	*/
	else
	{
		next[rear[qi]]=curr_free_index;
		rear[qi]=curr_free_index;
		next[curr_free_index]=-1;
	}
	//make some log
	//printf("The value %d is successfully inserted into queue no %d in position %d\n",elem,qi,curr_free_index);
	//printf("front[%d] is %d rear[%d] is %d next free is %d\n",qi,front[qi],qi,rear[qi],free);
}
/*
void KQueues::print_next()
{
	for(int i=0;i<n;i++)
	{
		printf("index %d,next index %d\n",i,next[i]);
	}
}
*/
int KQueues::dequeue(int qi)
{
	if(qi<0||qi>=k)
	{
		throw "queue index is out of bound";
        }
	if(empty(qi))
	{
		printf("Queue underflow\n");
		return -1;
	}
	//printf("Current front[%d] is %d\n",qi,front[qi]);
	int curr_front_index=front[qi];
	int elem=arr[front[qi]];
	//front[qi] stored the first free index allocated for queue
	front[qi]=next[front[qi]];
	//move to the next element
	int index_to_be_freed=curr_front_index;
	next[index_to_be_freed]=free;
	//initialize curr free
	free=index_to_be_freed;
	//make the index to be freed as the first free index available
	//printf("The value %d is successfully deleted from queue no %d in position %d\n",elem,qi,curr_front_index);
	return elem;
}
int main()
{
	try
	{
		int k=3,n=10;
		KQueues my_KQueues(k,n);
		my_KQueues.enqueue(0,1);
		my_KQueues.enqueue(0,11);		
		my_KQueues.enqueue(0,21);
		

		my_KQueues.enqueue(1,2);
		my_KQueues.enqueue(1,12);
		my_KQueues.enqueue(1,22);
		
		my_KQueues.enqueue(2,3);
		my_KQueues.enqueue(2,13);
		my_KQueues.enqueue(2,23);
		my_KQueues.enqueue(2,33);
		//to get overflow error
		my_KQueues.enqueue(2,43);

		//my_KQueues.print_next();
		printf("The element dequeued from queue 0 is: %d\n",my_KQueues.dequeue(0));
		printf("The element dequeued from queue 0 is: %d\n",my_KQueues.dequeue(0));
		printf("The element dequeued from queue 0 is: %d\n",my_KQueues.dequeue(0));
		//get the underflow error	
		printf("The element dequeued from queue 0 is: %d\n",my_KQueues.dequeue(0));
		
		printf("The element dequeued from queue 1 is: %d\n",my_KQueues.dequeue(1));	
		printf("The element dequeued from queue 1 is: %d\n",my_KQueues.dequeue(1));
		printf("The element dequeued from queue 1 is: %d\n",my_KQueues.dequeue(1));
		//get the underflow error
		printf("The element dequeued from queue 1 is: %d\n",my_KQueues.dequeue(1));
		
				
		printf("The element dequeued from queue 2 is: %d\n",my_KQueues.dequeue(2));	
		printf("The element dequeued from queue 2 is: %d\n",my_KQueues.dequeue(2));
		printf("The element dequeued from queue 2 is: %d\n",my_KQueues.dequeue(2));
		printf("The element dequeued from queue 2 is: %d\n",my_KQueues.dequeue(2));
		printf("The element dequeued from queue 2 is: %d\n",my_KQueues.dequeue(2));
	}
	catch(const char *e)
	{
		printf("The exception thrown: %s\n",e);
	}
	//we can do many experimentation with exception handling: just follow the simple one
	return 0;
}
