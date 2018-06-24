#include<bits/stdc++.h>
using namespace std;
// A recursive ternary search function. It returns location of x in
// given array arr[l..r] is present, otherwise -1
int ternary_search(int arr[], int l, int r, int x)
{
	
	if (r >= l)
   	{
        	int mid1 = l + (r - l)/3;
        	int mid2 = mid1 + (r - l)/3;
        	// If x is present at the mid1
        	if (arr[mid1] == x)  return mid1;
        	// If x is present at the mid2
        	if (arr[mid2] == x)  return mid2;
        	// If x is present in left one-third
        	if (arr[mid1] > x) return ternary_search(arr, l, mid1-1, x);
        	// If x is present in right one-third
        	if (arr[mid2] < x) return ternary_search(arr, mid2+1, r, x);
        	// If x is present in middle one-third
        	return ternary_search(arr, mid1+1, mid2-1, x);
   	}
   	// We reach here when element is not present in array
   	return -1;
}
int main()
{
	int arr[]={1,3,6,10,15};
	printf("Finding the element 6 in sorted array arr\n");
	int pos=-1;
	if((pos=ternary_search(arr,0,4,6))==-1)
	{
		printf("The element is not found\n");
	}
	else
	{
		//note that, how did I manage to make it with only one function call
		printf("The element is found at %d\n",pos);
	}

	return 0;
}
