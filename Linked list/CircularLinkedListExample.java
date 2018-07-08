class CircularSingleLinkedList<T>
{
	private class LinkedListNode<T>
	{
		T data;
		LinkedListNode<T> next;
		LinkedListNode(T data)
		{
			this.data=data;
			this.next=null;
		}
	}
	private LinkedListNode<T> head;
	private LinkedListNode<T> tail;
	CircularSingleLinkedList()
	{
		head=null;
		tail=null;
	}
	boolean empty()
	{
		return (head==null);
	}
	void addInBeginning(T data)
	{
		System.out.println("Insertion: data "+data+" Pos first");
		LinkedListNode<T> currNode=new LinkedListNode<>(data);
		if(head==null)
		{
			head=currNode;
			head.next=head;
			tail=head;
			return; 
		}
		currNode.next=head;
		tail.next=currNode;	
		
	}		
	void addInEnd(T data)
	{
		System.out.println("Insertion: data "+data+" Pos last");
		LinkedListNode<T> currNode=new LinkedListNode<>(data);
		if(head==null)
		{
			head=currNode;
			head.next=head;
			tail=head;
			return;
		}	
		tail.next=currNode;
		currNode.next=head;
		tail=currNode;
		//this is important
	}
	void addInAnyPosition(T data,int pos)throws Exception
	{
		System.out.println("Insertion: data "+data+" Pos "+pos);
		LinkedListNode<T> currNode=new LinkedListNode<>(data);
		if(pos<=0)
		{
			throw new Exception("The position is invalid");
		}
		if(pos==1)
		{
			if(head==null)
			{
				head=currNode;
	                        head.next=head;
        	                tail=head;
                	        return;
			}
			currNode.next=head;
			head=currNode;
			tail.next=head;
			//if first node, tail.next needs to be reassigned
			return;	
                }
		//if pos is not 1 and head is null
		if(head==null)
		{
			throw new Exception("head is null and pos is :"+pos);
		}
		//pos is in 1 indexing
		LinkedListNode<T> traverseNode=head;	
		int currPos=1;
		for(;traverseNode.next!=null&currPos<pos-1;traverseNode=traverseNode.next,currPos++);
		//we got the position
		if(traverseNode.next==null&&currPos!=pos-1)
		{
			//invalid position
			throw new Exception("Invalid position :"+pos);

		}	
		if(traverseNode==tail&&currPos==pos-1)
		{
			traverseNode.next=currNode;
			currNode.next=head;
			tail=currNode;
			//if last node, tail is to be aadjusted
			return;
		}
		currNode.next=traverseNode.next;
		traverseNode.next=currNode;
	}
	T deleteFromAnyPosition(int pos)throws Exception
	{
		System.out.println("Deletion: pos "+pos);
		if(pos<=0)
		{
			throw new Exception("The position is invalid");
		}
		if(head==null)
		{
			throw new Exception("The head is null");
		}
		if(pos==1)
		{
			//tail next is to be adjusted
			if(head.next!=head)
			{
				LinkedListNode<T> deletedNode=head;
				head=head.next;
				tail.next=head;
				T deletedData=deletedNode.data;
				deletedNode=null;
				//to make sure the memory allocated from heap is freed by java virtual machine asap
				return deletedData;
			}
			else
			{
				T deletedData=head.data;	
				head=null;
				tail=null;		
				return deletedData;
			}
		}
		LinkedListNode<T> traverseNode=head;
		int currPos=1;
		for(;traverseNode.next!=null&currPos<pos-1;traverseNode=traverseNode.next,currPos++);
                //we got the position
		if(traverseNode.next==null&&currPos!=pos-1)
                {
                        //invalid position
			 throw new Exception("Invalid position :"+pos);

                }
                if(traverseNode==tail&&currPos==pos-1)
                {
			
			//still invalid position
			//for deletion	
                       throw new Exception("Invalid position :"+pos);
		}
		if(traverseNode.next==tail&&currPos==pos-1)
		{
			//the tail node is to be deleted
			tail=traverseNode;
			T deletedData=traverseNode.next.data;
			traverseNode.next=null;
			//to be discoveered first by java virtual machine
			tail.next=head;
			return deletedData;
		}
		LinkedListNode<T> deletedNode=traverseNode.next;
		traverseNode.next=traverseNode.next.next;
		T deletedData=deletedNode.data;
		return deletedData;
	}
	void display()
	{
		System.out.print("The LinkedList is: ");
		LinkedListNode<T> traverseNode=head;
		for(;traverseNode!=tail;traverseNode=traverseNode.next)
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
		System.out.println("->"+traverseNode.data);
		System.out.println();
	}
					
}
public class CircularLinkedListExample

{
	public static void main(String args[])
	{
		try
		{
			CircularSingleLinkedList<Integer> list=new CircularSingleLinkedList<>();		
			list.addInBeginning(10);
			list.display();
			list.addInEnd(15);
			list.display();
			list.addInAnyPosition(11,2);
			list.display();
			list.addInAnyPosition(12,3);
			list.display();
			list.addInAnyPosition(16,5);
			list.display();
			list.addInAnyPosition(13,4);
			list.display();
			list.addInAnyPosition(14,5);
			list.display();
			list.deleteFromAnyPosition(7);
			list.display();
			list.deleteFromAnyPosition(6);
			list.display();
			list.deleteFromAnyPosition(1);
			list.display();
			list.deleteFromAnyPosition(2);
			list.display();
			list.deleteFromAnyPosition(1);
			list.display();
		}
		catch(Exception e)
		{
			System.out.println("The exception catched: "+e);
		}
	}
}


