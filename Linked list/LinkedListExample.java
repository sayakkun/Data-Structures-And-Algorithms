class LinkedList<T>
{
	//an outside class does not 
	//define a private class
	//which should not even be accessible from other classes of same package
	private class Node<T>
	{
		public T data;
		public Node<T> next;
		//the compiler will automatically include a no arg constructor
		//now, we dont need one, we will use a parametric constructor
		public Node(T data)
		{
			this.data=data;
			this.next=null;
		}
		
	}
	private Node<T> head;
	//this is LinkedList head;
	public LinkedList()
	{
		head=null;
	}
	public void addFirst(T data)
	{
		Node<T> toBeAdded=new Node<>(data);
		toBeAdded.next=head;
		head=toBeAdded;
		//reference is going to be changed
	}
	public void addLast(T data)
	{
		Node<T> toBeAdded=new Node<>(data);
		//otherwise JVM will throw NullPointerException
		if(head==null)
		{
			head=toBeAdded;
		}
		else
		{
			Node <T> traverseNode=head;
			for(;traverseNode.next!=null;traverseNode=traverseNode.next);
			traverseNode.next=toBeAdded;
		}
	}
	public void display()
	{
		Node<T> traverseNode=head;
		for(;traverseNode!=null;traverseNode=traverseNode.next)
		{
			if(traverseNode==head)
			{
				System.out.print(traverseNode.data);
			}
			else
			{
				System.out.print("->"+traverseNode.data);
			}
		}
		System.out.println();
	}	
}
public class LinkedListExample
{
	public static void main(String args[])
	{
		LinkedList<Integer> linkedList=new LinkedList<>();
		//diamond notation
		linkedList.addLast(12);
		linkedList.addFirst(11);
		linkedList.display();
	}	
}

