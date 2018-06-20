class KStacks
{
	private int k;
	private int n;
	//size of arr
	private int free;
	//contains the starting index of the free list
	private int []top;
	private int []arr;
	private int []next;
	public KStacks(int k,int n)throws Exception
	{
		if(k<=0)
		{
			throw new Exception("k cannot be <=0");
		}
		if(n<=0)
		{
			throw new Exception("n cannot be <=0");
		}
		if(k>n)
		{
		
			throw new Exception("The number of stacks cannot be > the size of arr");
		}
		this.k=k;
		this.n=n;
		this.free=0;
		//initialize it to 0
		//That means, initially 0 is the free index and it can be allocated to the initial stack request
		try
		{
			top=new int[this.k];
		}
		catch(OutOfMemoryError e)
		{
			throw new Exception("Memory cannot be allocated to top");
		}
		try
		{
			arr=new int[this.n];
		}
		catch(OutOfMemoryError e)
		{
			throw new Exception("Memory cannot be allocated to arr");
		}
		try
		{
			next=new int[this.n];
		}
		catch(OutOfMemoryError e)
                {
                        throw new Exception("Memory cannot be allocated to arr");
                }
		//initialize the arrays
		for(int i=0;i<this.k;i++)
		{
			top[i]=-1;
		}	
		for(int i=0;i<this.n-1;i++)
		{
			next[i]=i+1;
		}
		next[this.n-1]=Integer.MAX_VALUE;
	}
	public boolean empty(int sn) throws Exception
	{
		if(sn<0||sn>=k)
		{
			throw new Exception("stack index is out of bound");
		}
		return top[sn]==-1;
	}
	public boolean full()
	{
		return free==Integer.MAX_VALUE;	
	}
	public void push(int sn,int elem) throws Exception
	{
		if(sn<0||sn>=k)
                {
                        throw new Exception("stack index is out of bound");
                }
		if(full())
		{
			System.out.println("Stack overflow");
			return;
		}
		int curr_index=free;
		//in this curr_index in arr, the new element is going to be pushed
		free=next[free];
		//update free
		next[curr_index]=top[sn];	
		//so that, we can track in the case of pop
		top[sn]=curr_index;
		arr[curr_index]=elem;
	}
	public int pop(int sn) throws Exception
	{
		if(sn<0||sn>=k)
                {
                        throw new Exception("stack index is out of bound");
                }
		if(empty(sn))
		{
			System.out.println("Stack underflow");
			return Integer.MAX_VALUE;
		}
		int elem=arr[top[sn]];
		int index_to_be_freed=top[sn];
		top[sn]=next[index_to_be_freed];
		next[index_to_be_freed]=free;
		free=index_to_be_freed;
		//attach the index_to_be_freeed as the first index of the free index pool
		return elem;
	}
}
public class KStackChecker
{
	public static void main(String args[])
	{
		try
		{
			KStacks myKStacks=new KStacks(3,10);
			myKStacks.push(0,1);
			myKStacks.push(0,11);
			myKStacks.push(0,21);
			myKStacks.push(0,31);
			myKStacks.push(1,2);
			myKStacks.push(1,12);
			myKStacks.push(1,22);
			myKStacks.push(1,32);
			myKStacks.push(2,3);
			myKStacks.push(2,13);
			myKStacks.push(2,23);
			
			System.out.println("The element popped from stack 0 "+myKStacks.pop(0));	
			System.out.println("The element popped from stack 0 "+myKStacks.pop(0));
			System.out.println("The element popped from stack 0 "+myKStacks.pop(0));
			System.out.println("The element popped from stack 0 "+myKStacks.pop(0));

			
			System.out.println("The element popped from stack 1 "+myKStacks.pop(1));	
			System.out.println("The element popped from stack 1 "+myKStacks.pop(1));
			System.out.println("The element popped from stack 1 "+myKStacks.pop(1));
			System.out.println("The element popped from stack 1 "+myKStacks.pop(1));

			
			System.out.println("The element popped from stack 2 "+myKStacks.pop(2));
			System.out.println("The element popped from stack 2 "+myKStacks.pop(2));
			System.out.println("The element popped from stack 2 "+myKStacks.pop(2));
			System.out.println("The element popped from stack 2 "+myKStacks.pop(2));
		}
		catch(Exception e)
		{
			System.out.println("The exception is: "+e);
		}
		//there is no need of finally block here

	}
}

