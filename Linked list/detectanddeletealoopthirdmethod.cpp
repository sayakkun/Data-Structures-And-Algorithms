#include<bits/stdc++.h>
using namespace std; 
/* Link list node */
struct Linked_list_node
{
	int data;
    	struct Linked_list_node* next;
};
 
bool detect_and_remove_loop(struct Linked_list_node *);
void display_linked_list(struct Linked_list_node *node);
 
/* This function detects and removes loop in the list
 *   If loop was there in the list then it returns true,
 *     otherwise returns false */
bool detect_and_remove_loop(struct Linked_list_node *head)
{
	struct Linked_list_node  *slow_p = head, *fast_p = head; 
    	while (slow_p && fast_p && fast_p->next)
    	{
        	slow_p = slow_p->next;
        	fast_p  = fast_p->next->next;
 
        	/* If slow_p and fast_p meet at some point then there is a loop */
        	if (slow_p == fast_p)
        	{
			break;
			//because loop is found
		}
        }
    	if(slow_p!=fast_p)
	{
		//break due to normal reasons
		return false;
	}
	if (slow_p == fast_p)
    	{
        	slow_p = head;
        	while (slow_p->next != fast_p->next)
        	{
            		slow_p = slow_p->next;
            		fast_p = fast_p->next;
        	}
        	/* since fast->next is the looping point */
        	fast_p->next = NULL; /* remove loop */
		return true;
    	}
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
