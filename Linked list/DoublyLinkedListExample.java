//make the linkedlist generic
class DoublyLinkedList<T>
{
	private class DoublyLinkedListNode<T>
	{
		//make all functions and variables as if they are having default access specifiers
		//
		T data;
		DoublyLinkedListNode<T> prev;
		DoublyLinkedListNode<T> next;
		DoublyLinkedListNode(T data)
		{
			this.data=data;
			this.prev=null;
			this.next=null;
		}
	}
	private DoublyLinkedListNode<T> head;
	//do we need more
	//just have the functions with default access specifier
	//since, the class is not public
	//eventually, the functions cannot be accessed outside the package
	//now, no package is mentioned. Hence, this classes will be undeer default package
	DoublyLinkedList()
	{
		head=null;
	}
	/*
 * 	checks if the linkedlist is empty
 */
	boolean empty()
	{
		return (head==null);
	}
	/*
 * 	It inserts a node at the end*
 */
	void addANodeAtEnd(T data)
	{
		System.out.println("Insertion: Data: "+data+" Pos: Last");
		DoublyLinkedListNode<T> currNode=new DoublyLinkedListNode<>(data);
		if(head==null)
		{
			head=currNode;
			return;
		}
		DoublyLinkedListNode<T> traverseNode=head;
		for(;traverseNode.next!=null;traverseNode=traverseNode.next);
		traverseNode.next=currNode;
		currNode.prev=traverseNode;
		//two links are to be adjusted for the end node
	}
	/*
 * 	It inserts a node at the beginning
 */
	void addANodeAtBeginning(T data)
	{
		System.out.println("Insertion: Data: "+data+" Pos: 1st");
		DoublyLinkedListNode<T> currNode=new DoublyLinkedListNode<>(data);
		if(head==null)
		{
			head=currNode;
			return;
		}
		currNode.next=head;
		head.prev=currNode;
		//two links are adjusted
	}
	/*Inserts a node at any position
 * 	position is given in one indexing
 */
	void addANodeAtAnyPosition(T data,int pos)throws Exception
	{
		//System.out.println("In function addANodeAtAnyPosition. The position is "+pos);
		System.out.println("Insertion: Data: "+data+" Pos: "+pos);  
		if(pos<=0)
		{
			throw new Exception("Invalid position");
		}
		DoublyLinkedListNode<T> currNode=new DoublyLinkedListNode<>(data);
		if(head==null)
		{
			throw new Exception("Invalid position: "+pos+" as the linked list is empty");
		}
		int currPos=1;
		DoublyLinkedListNode<T> traverseNode=head;
		for(;traverseNode.next!=null&&currPos<pos-1;traverseNode=traverseNode.next,currPos++);
		if(traverseNode.next==null&&currPos!=pos-1)
		{
			throw new Exception("Invalid position");
		}
		currNode.next=traverseNode.next;
		if(traverseNode.next!=null)
		{
			traverseNode.next.prev=currNode;
		}
		traverseNode.next=currNode;
		currNode.prev=traverseNode;
	}
	/*Delete a node from any position
 * 	position is given in 1 indexing*/
	T deleteNodeFromAnyPosition(int pos) throws Exception
	{
		System.out.println("the position for delete: "+pos);
		if(pos<=0)
		{
			throw new Exception("Invalid position");
		}
		if(head==null)
		{
			throw new Exception("Empty linked list");
		}
		DoublyLinkedListNode<T> deletedNode;
		if(pos==1)
		{
			T data=head.data;
			deletedNode=head;
			head=head.next;
			head.prev=null;
			deletedNode=null;
			return data;
		}
		int currPos=1;
                DoublyLinkedListNode<T> traverseNode=head;
                for(;traverseNode.next!=null&&currPos<pos-1;traverseNode=traverseNode.next,currPos++);
		if(traverseNode.next==null&&currPos!=pos-1)
                {
                        throw new Exception("Invalid position");
                }
		deletedNode=traverseNode.next;
		traverseNode.next=deletedNode.next;
		if(deletedNode.next!=null)
		{
			deletedNode.next.prev=traverseNode;
		}
		T data=deletedNode.data;
		deletedNode=null;
		//so, that, memory cleanup can be done early
		return data;		
	}
	void display()
	{
		System.out.print("The linked list node is:");
		DoublyLinkedListNode<T> traverseNode=head;
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
public class DoublyLinkedListExample
{
	public static void main(String args[])
	{
		try
		{
			DoublyLinkedList<Integer> list=new DoublyLinkedList<>();
			list.addANodeAtBeginning(10);
			list.display();
			list.addANodeAtEnd(15);
			list.display();
			//list.addANodeAtAnyPosition(11,0);
			//list.display();
			//an exception is expected
			list.addANodeAtAnyPosition(11,2);
			list.display();
			//list.addANodeAtAnyPosition(12,5);
			//list.display();
			//an exception is excepted
			list.addANodeAtAnyPosition(12,3);
			list.display();
			list.addANodeAtAnyPosition(13,4);
			list.display();
			list.addANodeAtAnyPosition(14,5);
			list.display();
			list.addANodeAtAnyPosition(16,7);		
			list.display();
			list.deleteNodeFromAnyPosition(1);
			list.display();
			//list.deleteNodeFromAnyPosition(0);
			//list.display();
			//an exception is expected
			list.deleteNodeFromAnyPosition(2);
			list.display();
			list.deleteNodeFromAnyPosition(5);
			list.display();
			list.deleteNodeFromAnyPosition(3);
			list.display();
		}
		catch(Exception e)
		{
			System.out.println("The exception is: "+e);
		}
	}
} 
