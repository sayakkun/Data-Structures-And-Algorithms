#include<bits/stdc++.h>
int binary_search(int arr[], int l, int r, int key)
{
	int m;
    	while((r-l)>1)
    	{
		//no point for having r-l==1 because, that will make m=l
        	m = l + (r-l)/2;
		//overflow is prevented
        	if( arr[m] <= key ) // second comparison
            	{
			l = m ;
		}
        	else
            	{
			r = m;
		}
    	}
	if(arr[l] == key )
        {
		return l;
	}
    	else
        {
		return -1;
    	}
}
int main()
{
	int arr[]={1,5,7,9,11};
	printf("Finding the element 7 in sorted array arr\n");
	int pos=-1;
	if((pos=binary_search(arr,0,4,7))==-1)
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
