#include<bits/stdc++.h> 
using namespace std;
// A utility function to get the middle index from corner indexes.
int get_mid(int s, int e) 
{  
	//this technique avoids the overflow
	return s + (e -s)/2; 
}
 
/*  A recursive function to get the sum of values in given range
    of the array. The following are parameters for this function.
 
    st    --> Pointer to segment tree
    si    --> Index of current node in the segment tree. Initially
              0 is passed as root is always at index 0. Consider this to be be segment index
    ss & se  --> Starting and ending indexes of the segment represented
                 by current node, i.e., st[si]
    qs & qe  --> Starting and ending indexes of query range */
int get_sum_util(int *st, int ss, int se, int qs, int qe, int si)
{
    	// If segment of this node is a part of given range, then return
    	// the sum of the segment
    	// but, note that, in this case, the query range should not overlap with the current segment range
	if (qs <= ss && qe >= se)
        {
		return st[si];
 	}
    	// If segment of this node is outside the given range
    	if (se < qs || ss > qe)
        {
		return 0;
 	}
    	// If a part of this segment overlaps with the given range
    	int mid = get_mid(ss, se);
    	return get_sum_util(st, ss, mid, qs, qe, 2*si+1)+get_sum_util(st, mid+1, se, qs, qe, 2*si+2);
}
 
/* A recursive function to update the nodes which have the given 
   index in their range. The following are parameters
    st, si, ss and se are same as get_sum_util()
    i    --> index of the element to be updated. This index is in input array.
   diff --> Value to be added to all nodes which have i in range */
void update_value_util(int *st, int ss, int se, int i, int diff, int si)
{
	// Base Case: If the input index lies outside the range of this segment
	// during initial call, if it lies outside the whole segment tree's range index
    	if (i < ss || i > se)
        {
		return;
 	}
    	// If the input index is in range of this node, then update 
    	// the value of the node and its children
    	st[si] = st[si] + diff;
    	if (se != ss)
    	{
		//all segment containing the index i should be updated
        	int mid = get_mid(ss, se);
        	update_value_util(st, ss, mid, i, diff, 2*si + 1);
        	update_value_util(st, mid+1, se, i, diff, 2*si + 2);
    	}
}
 
// The function to update a value in input array and segment tree.
// It uses update_value_util() to update the value in segment tree
void update_value(int arr[], int *st, int n, int i, int new_val)
{
	// Check for erroneous input index
    	if (i < 0 || i > n-1)
    	{
        	printf("Out of bound index for update operation");
        	return;
    	}
 	// Get the difference between new value and old value
    	int diff = new_val - arr[i];
 	// Update the value in array
 	//we cannot update all the ranges containing this input index here
 	//but, we have to update the actual arr here
    	arr[i] = new_val;
    	// Update the values of nodes in segment tree
    	update_value_util(st, 0, n-1, i, diff, 0);
}
 
// Return sum of elements in range from index qs (quey start)
// to qe (query end).  It mainly uses get_sum_util()
int get_sum(int *st, int n, int qs, int qe)
{
    // Check for erroneous input values
	if (qs < 0 || qe > n-1 || qs > qe)
    	{
        	printf("Invalid query range");
        	return -1;
    	}
 	return get_sum_util(st, 0, n-1, qs, qe, 0);
}
 
// A recursive function that constructs Segment Tree for array[ss..se].
// si is index of current node in segment tree st
int construct_st_util(int arr[], int ss, int se, int *st, int si)
{
	// If there is one element in array, store it in current node of
    	// segment tree and return
    	if (ss == se)
    	{
        	st[si] = arr[ss];
        	return arr[ss];
    	}
 	// If there are more than one elements, then recur for left and
    	// right subtrees and store the sum of values in this node
    	int mid = get_mid(ss, se);
    	st[si] =  construct_st_util(arr, ss, mid, st, si*2+1) + construct_st_util(arr, mid+1, se, st, si*2+2);
    	return st[si];
}
 
/* Function to construct segment tree from given array. This function
   allocates memory for segment tree and calls construct_st_util() to
   fill the allocated memory */
int *construct_st(int arr[], int n)
{
	// Allocate memory for segment tree
    	//Height of segment tree
    	int height = (int)(ceil(log2(n))); 
	//since, segment tree is a full binary tree containing 0 or 2 children at every node
    	//Maximum size of segment tree
    	int max_size = 2*(int)pow(2,height) - 1; 
    	// Allocate memory
    	int *st = NULL;
	//Now, segment tree consumes huge memory
	try
	{
		st=new int[max_size];
	}
	catch(const bad_alloc &e)
	{
		//we can rethrow it. But, let's define out own exception
    		// Fill the allocated memory st
    		printf("Memory cannot be allocated for segment tree\n");
	}
    	construct_st_util(arr, 0, n-1, st, 0);
    	// Return the constructed segment tree
    	return st;
}
 
// Driver program to test above functions
int main()
{
	int arr[] = {1, 3, 5, 7, 9, 11};
    	int n = sizeof(arr)/sizeof(arr[0]);
 	// Build segment tree from given array
 	int *st=NULL;
	try
    	{
		st = construct_st(arr, n);
 		// Print sum of values in array from index 1 to 3
    		printf("Sum of values in given range = %d\n",get_sum(st, n, 1, 3));
    		// Update: set arr[1] = 10 and update corresponding 
    		// segment tree nodes
   		 update_value(arr, st, n, 1, 10);
    		// Find sum after the value is updated
    		printf("Updated sum of values in given range = %d\n",get_sum(st, n, 1, 3));
	}
	catch(const char *e)
	{
		printf("The exception is %s\n",e);
	}
    	return 0;
}
