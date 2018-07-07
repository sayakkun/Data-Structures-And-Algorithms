//Now, How to implement a stack which will support following operations in O(1) time complexity?
//1) push() which adds an element to the top of stack.
//2) pop() which removes an element from top of stack.
//3) findMiddle() which will return middle element of the stack.
//4) deleteMiddle() which will delete the middle element.
/*
 * The important question is, whether to use a linked list or array for implementation of stack?
 *
 * Please note that, we need to find and delete middle element. Deleting an element from middle is not O(1) for array. Also, we may need to move the middle pointer up when we push an element and move down when we pop(). In singly linked list, moving middle pointer in both directions is not possible.
 *
 * The idea is to use Doubly Linked List (DLL). We can delete middle element in O(1) time by maintaining mid pointer. We can move mid pointer in both directions using previous and next pointers.
 */
class SpecialStacks
{
	//this is package default
	//Now, the inner classs can have private access modifier 
	//telling that this class can be accessed from only the outer class
	private class DLLNode
	{
		//this class will be implementing a DLLNode
		//now, this is funny. But, this inner class will have membeers with either public access modifier
		//or, have no access specififer which is default
		int data;
		DLLNode prev;
		DLLNode next;
		//two references
		//you can access any of it from outside class 
		DLLNode(int data)
		{
			this.data=data;
			this.prev=null;
			this.next=null;
		}
	}	
	private int count;
	/*The number of elements in the stack*/
	private DLLNode middle;
	private DLLNode head;
	/*Note that inner class's members could have the default access specifier here. Because, since, the inner class itself	      has private access modifier*/
	public SpecialStacks()
	{
		head=null;
		middle=null;
		count=0;
	}
	/*we will have only one constructor*/
	public boolean empty()
	{
		return (head==null);
	}
	public void push(int data)
	{
		DLLNode temp=new DLLNode(data);
		//a node is created
		if(head==null)
		{
			head=temp;
			middle=head;
			count++;
		}
		else
		{
			temp.next=head;
			head.prev=temp;
			head=temp;		
			//System.err.println("The head data is: "+head.data);
			//because, in case of a push operation it will be added in the front 
			count++;
			if((count&1)!=0)
			{
				//System.out.println("The middle data is :"+middle.data);
				//it contains the reference of the stack bottom we have to do middle=middle.prev
				//we should not do middle=middle.next
				middle=middle.prev;
			
			}
		}
	}
	public int pop()throws Exception
	{
		//System.err.println("Executing point 1");
		if(empty())
		{
			throw new Exception("The stack is empty. Pop operation cannot be performed");
		}
		DLLNode temp=head;
		int val=temp.data;
		head=head.next;
		count--;
		//System.err.println("Executing point 2");
		if((count&1)!=0)
		{
			//middle=middle.prev;
			middle=middle.next;
		}
		/*An optimization technique which helps JVM understand that they should delete the reference holding by temp
 * 		asap*/
		return val;
	}
	public int getMiddle() throws Exception
	{
		if(empty())
		{
			/*The person which handles this API might forgot that he/she has to check if the stack is empty or not
 */			throw new Exception("The Stack is empty. Hence, middle element cannot be obtained");
		}
		if(middle==null)
		{
			throw new Exception("The operation on middle node cannot be performed.Midddle node is empty");
		}
		return middle.data;
	}
	/*public Iterator iterator()
	{
		//now, we can always return a class which implements Iterator
		//because of polymorphism
		return new SpecialStacksIterator(head);
	}*/
	/*public void display()
	{
		System.out.println("Displaying the stack");
		DLLNode traverse=head;
		for(;traverse!=null;traverse=traverse.next)
		{
			if(traverse==head)
			{
				System.out.print(traverse.data);
			}
			else
			{
				System.out.print(" "+traverse.data);
			}	
		}
		System.out.println();
	}*/
	//Now, the display function should not be there
	//Rather, according to convention Your class should implement the iterable interface
	//Also, you are actually follo0wing conventions and design pattern. Since, iterator is a design pattern
	//But How will we implement it, that's a challenge. Because, DLLNode is a private class
}

public class StackWithOperationOnMiddleNodeTester
{
	public static void main(String args[])
	{
		try
		{
			SpecialStacks newStack=new SpecialStacks();
			newStack.push(12);
			System.out.println("12 is being pushed into the stack\n");
			//newStack.display();
			newStack.push(13);
			System.out.println("13 is being pushed into the stack\n");
			//newStack.display();
			newStack.push(14);
			System.out.println("14 is being pushed into the stack\n");
			//newStack.display();
			//let's hava an operation on middle element
			int currMid,currPoppedElem;
			currMid=newStack.getMiddle();
			System.out.println("The middle element is: "+currMid);
			currPoppedElem=newStack.pop();
			System.out.println("The popped element is: "+currPoppedElem);
			currPoppedElem=newStack.pop();
			System.out.println("The popped element is: "+currPoppedElem);
			currMid=newStack.getMiddle();
			System.out.println("The middle element is: "+currMid);
		}
		catch(Exception e)
		{
			System.out.println("The exception is "+e);
		}
	}
}
