#include<bits/stdc++.h>
using namespace std; 
/* Link list node */
struct Linked_list_node
{
	int data;
    	struct Linked_list_node* next;
};
 
/* Function to remove loop. Used by detect_and_remove_loop() */
void remove_loop(struct Linked_list_node *,struct Linked_list_node *);
bool detect_and_remove_loop(struct Linked_list_node *);
void display_linked_list(struct Linked_list_node *node);
 
/* This function detects and removes loop in the list
 *   If loop was there in the list then it returns true,
 *     otherwise returns false */
bool detect_and_remove_loop(struct Linked_list_node *list)
{
	struct Linked_list_node  *slow_p = list, *fast_p = list; 
    	while (slow_p && fast_p && fast_p->next)
    	{
        	slow_p = slow_p->next;
        	fast_p  = fast_p->next->next;
 
        	/* If slow_p and fast_p meet at some point then there is a loop */
        	if (slow_p == fast_p)
        	{
            		remove_loop(slow_p, list); 
			return true;
			//because loop is found
		}
        }
	//otherwise, there is no loop
    	return false;
}
 
/* Function to remove loop.
 *  loop_node : Pointer to one of the loop nodes which is discovered by Floyd's loop detection
 *   head     : Pointer to the start node of the linked list */
void remove_loop(struct Linked_list_node *loop_node, struct Linked_list_node *head)
{
	struct Linked_list_node *ptr1;
   	struct Linked_list_node *ptr2;
   /* Set a pointer to the beginning of the Linked List and
 *    move it one by one to find the first node which is part of the Linked List */
  	 ptr1 = head;
   	 while (true)
   	 {
     	/* Now start a pointer from loop_node and check if it ever eaches ptr2 */
     		ptr2 = loop_node;
     		while (ptr2->next != loop_node && ptr2->next != ptr1)
         	{
			ptr2 = ptr2->next;
		}
 		/* If ptr2 reahced ptr1 we found the beginning of the loop. So break the loop */
     		if (ptr2->next == ptr1)
       		{
			 break;
		}
 		/* If ptr2 did't reach ptr1 then try the next node after ptr1 */
    	 	ptr1 = ptr1->next;
   	}
   	/* After the end of loop ptr2 is the last node of the loop. So make next of ptr2 as NULL */
   	ptr2->next = NULL;
}
 
/* Function to print linked list */
void display_linked_list(struct Linked_list_node *head)
{
	struct Linked_list_node *traverse_node=head;
	while (traverse_node!=NULL)
    	{
		if(traverse_node==head)
		{
			printf("%d",traverse_node->data);
		}
		else
		{
        		printf("->%d",traverse_node->data);
		}
        	traverse_node = traverse_node->next;
    	}
	printf("\n");
}
struct Linked_list_node *new_linked_list_node(int key)
{
	struct Linked_list_node *temp =NULL;
     	try
 	{
     		temp=new struct Linked_list_node();
		temp->data = key;
    		temp->next = NULL;
    		return temp;
	}
	catch(const bad_alloc &e)
	{
		throw "The memory for new linked list node cannot be allocated";
		//it could be throw exception("The memory for new linked list node cannot be allocated");
	}
}
 
/* Drier program to test above function*/
int main()
{
    	struct Linked_list_node *head =NULL;
	try
	{
		head=new_linked_list_node(50);
    		head->next = new_linked_list_node(20);
    		head->next->next = new_linked_list_node(15);
   	 	head->next->next->next = new_linked_list_node(4);
    		head->next->next->next->next = new_linked_list_node(10);
    		/* Create a loop for testing */
    		head->next->next->next->next->next = head->next->next; 
    		detect_and_remove_loop(head);
 	    	printf("Linked List after removing loop \n");
    		display_linked_list(head);
	}
	catch(const char* e)
	{
		printf("The exception thrown is %s\n",e);
	}
    	return 0;
}
