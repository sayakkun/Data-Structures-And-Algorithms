#include<bits/stdc++.h>
using namespace std;
class MaxPriorityQueue
{
	private:
		vector<pair<int,int> > value_set;
		//unlike java, this will be initialized..so no problem
		int left_index(int);
		int right_index(int);
		int parent_index(int);
		void heapify(int);
		void insert(pair<int,int> );
		int extract_max();
		bool empty();
		MaxPriorityQueue();
		//so, making the  constructor private, we are making it more strict
		//since, for outside, only the stack class should exist
	public:
		//MaxPriorityQueue();
		friend class Stack;
};
class Stack
{
	//since, it is friend class, it can operate on private data
	 private:
		int count;
		//we do not need static
		//this is a variable which is to be incremented after every insertion
		MaxPriorityQueue p_queue;
	public:
		Stack();
		void push(int);
		int pop();
		bool empty();
		
};
MaxPriorityQueue::MaxPriorityQueue()
{
}
int MaxPriorityQueue::left_index(int i)
{
	return 2*i+1;
}
int MaxPriorityQueue::right_index(int i)
{
	return 2*i+2;
}
int MaxPriorityQueue::parent_index(int i)
{
	return (i-1)<<1;
}
void MaxPriorityQueue::heapify(int i)
{
	int size=value_set.size();
	int max_index=i;
	int max=value_set[i].second;
	//first will be data
	//second is priority
	int l_c_index=left_index(i);
	int r_c_index=right_index(i);
	if(l_c_index<size&&value_set[l_c_index].second>max)
	{
		max_index=l_c_index;
		max=value_set[l_c_index].second;
	}
	if(r_c_index<size&&value_set[r_c_index].second>max)
	{
		max_index=r_c_index;
		max=value_set[r_c_index].second;
	}
	if(max_index!=i)
	{
		pair<int,int> temp=value_set[max_index];
		value_set[max_index]=value_set[i];
		value_set[i]=temp;
		//swapping position
		heapify(max_index);
	}	
}
void MaxPriorityQueue::insert(pair<int,int> new_pair)
{
	value_set.push_back(new_pair);
	int i=value_set.size()-1;
	int p_index=parent_index(i);
	while(p_index>=0)
	{
		if(value_set[i].first>value_set[p_index].first)
		{
			//swapping is done
			pair<int,int> temp=value_set[i];
			value_set[i]=value_set[p_index];
			value_set[p_index]=temp;
		}
		p_index=parent_index(p_index);
	}
}
int MaxPriorityQueue::extract_max()
{
	int end_i=value_set.size()-1;
	//got the last position
	int val=value_set[0].first;
	pair<int,int> temp=value_set[0];
	//since, in max priorityQueue the max element is at 0th index
	value_set[0]=value_set[end_i];
	value_set[end_i]=temp;	
	value_set.erase(value_set.end()-1);		
	//swapping the max value
	heapify(0);
	return val;
}
bool MaxPriorityQueue::empty()
{
	return (value_set.size()==0);
}
Stack::Stack()
{
	count=0;
}
void Stack::push(int data)
{
	count++;
	//increment it before pushing or after pushing the current element into the stack
	pair<int,int> curr_pair=make_pair(data,count);
	p_queue.insert(curr_pair);
	//done	
}
bool Stack::empty()
{
	return p_queue.empty();
}
int Stack::pop()
{
	if(p_queue.empty())
	{
		throw "Stack underflow";
	}
	return p_queue.extract_max();
}
int main()
{
	try
	{
		Stack my_stack;
		my_stack.push(12);
		my_stack.push(13);
		printf("The element popped %d\n",my_stack.pop());
		my_stack.push(14);
		printf("The element popped %d\n",my_stack.pop());
		printf("The element popped %d\n",my_stack.pop());
		//MaxPriorityQueue p_queue; 	
		//this constructor invokation is not possible
	}
	catch(const char *e)
	{
		printf("The exception thrown %s\n",e);
	}
}	

