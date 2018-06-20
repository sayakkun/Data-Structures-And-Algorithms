// A C++ program to demonstrate implementation of k stacks in a single 
// array in time and space efficient way
#include<bits/stdc++.h>
using namespace std; 
// A C++ class to represent k stacks in a single array of size n
class kStacks
{
	int *arr;   // Array of size n to store actual content to be stored in stacks
    	int *top;   // Array of size k to store indexes of top elements of stacks
    	int *next;  // Array of size n to store next entry in all stacks
                // and free list
    	int n, k;
    	int free; // To store beginning index of free list
	public:
    		//constructor to create k stacks in an array of size n
    	kStacks(int k, int n);
 
    	// A utility function to check if there is space available
    	bool is_full();
 
    	// To push an item in stack number 'sn' where sn is from 0 to k-1
    	void push(int item, int sn);
 
    	// To pop an from stack number 'sn' where sn is from 0 to k-1
    	int pop(int sn);
 
    	// To check whether stack number 'sn' is empty or not
    	bool is_empty(int);
};
 
//constructor to create k stacks in an array of size n
kStacks::kStacks(int k, int n)
{
	// Initialize n and k, and allocate memory for all arrays
	if(k<=0)
	{
		throw "The number of stacks to be created cannot be <=0";
	}
	if(n<=0)
	{
		throw "The size of array cannot be <=0";
	}
	if(k>n)
	{
		throw "The number of stacks cannot be > the number of elements in the array";
	}
	this->k=k;
	this->n=n;
	//in this point arr is an uninitialized pointer
	try
	{
    		arr = new int[this->n];
	}
	catch(const bad_alloc &e)
	{
		throw "Memory cannot be allocated for arr";
	}
	try
	{
    		top = new int[this->k];
	}
	catch(const bad_alloc &e)
	{
		throw "Memory cannot be allocated for top";
	}
	try
	{
    		next = new int[this->n];
 	}
	catch(const bad_alloc &e)
	{
		throw "Memory cannot be allocated for next";
	}
    	// Initialize all stacks as empty
   	 for (int i = 0; i < k; i++)
         {
	 	top[i] = -1;
	 }
    	 // Initialize all spaces as free
    	free = 0;
    	for (int i=0; i<n-1; i++)
        {
		next[i] = i+1;
	}
    	next[n-1] = INT_MAX;  //INT_MAX is used here to indicate the end of list
}
bool kStacks::is_empty(int sn)
{
	//check if a particular stack is empty or not
	if(sn<0||sn>=k)
        {
                throw "Stack index is out of bound";
        }
	return (top[sn]==-1);
} 
bool kStacks::is_full()
{
	return (free==INT_MAX);
	//no index is free of the next list
}
// To push an item in stack number 'sn' where sn is from 0 to k-1
// Now, you could really return true or false push operation indicating whether an element is actually pushed or not
// but, this would violate the standard definition of push operation
void kStacks::push(int item, int sn)
{
	if(sn<0||sn>=k)
	{
		throw "Stack index is out of bound";
	}
    	// Overflow check
	if (is_full())
    	{
        	cout << "Stack Overflow\n";
        	return;
    	}
    	int i = free;      // Store index of first free slot
    	// Update index of free slot to index of next slot in free list
    	free = next[i];
    	// Update next of top and then top for stack number 'sn'
    	next[i] = top[sn];
    	top[sn] = i;
    	// Put the item in array
    	arr[i] = item;
}
 
// To pop an from stack number 'sn' where sn is from 0 to k-1
int kStacks::pop(int sn)
{
	if(sn<0||sn>=k)
        {
                throw "Stack index is out of bound";
        }
	// Underflow check
    	if (is_empty(sn))
    	{
         	cout << "Stack Underflow\n";
         	return INT_MAX;
    	}
    	// Find index of top item in stack number 'sn'
    	int i = top[sn];
    	top[sn] = next[i];  // Change top to store next of previous top
    	// Attach the previous top to the beginning of free list
    	next[i] = free;
    	free = i;
    	// Return the previous top item
    	return arr[i];
} 
/* Driver program to test twStacks class */
int main()
{
	try
	{
		// Let us create 3 stacks in an array of size 10
	    	int k = 3, n = 10;
    		kStacks ks(k, n);
    		// Let us put some items in stack number 2
	    	ks.push(15, 2);
    		ks.push(45, 2);
 		ks.push(65,2);
    		// Let us put some items in stack number 1
    		ks.push(17, 1);
    		ks.push(49, 1);
    		ks.push(39, 1);
 		ks.push(69,1);
    		// Let us put some items in stack number 0
    		ks.push(11, 0);
    		ks.push(9, 0);
    		ks.push(7, 0);
 		ks.push(5,0);
	
    		cout << "Popped element from stack 0 is " << ks.pop(0) << endl;
    		cout << "Popped element from stack 0 is " << ks.pop(0) << endl;
    		cout << "Popped element from stack 0 is " << ks.pop(0) << endl;
    		cout << "Popped element from stack 0 is " << ks.pop(0) << endl;
    
	
   	 	cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
    		cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
    		cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
    		cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
	
		cout << "Popped element from stack 2 is " << ks.pop(2) << endl; 
		cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
		cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
		cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
   	 	return 0;
	}
	catch (const char* e)
	{
		cout<<"The exception is:"<<e<<endl;
	}
}
