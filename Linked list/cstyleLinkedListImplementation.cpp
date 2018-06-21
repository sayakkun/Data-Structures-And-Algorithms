//this is c style linked link implementation 
//using struct and functions
#include<cstdio>
struct Node
{
	int data;
	struct Node *next;
};
struct Node* insert_at_end(struct Node *head,int data)
{
	struct Node *curr=new struct Node();
	curr->data=data;
	curr->next=NULL;
	if(head==NULL)
	{
		return curr;
	}
	struct Node *index_node=head;
	for(;index_node->next!=NULL;index_node=index_node->next);
	index_node->next=curr;
	return head;
}
struct Node* insert_at_beginning(struct Node *head,int data)
{
	struct Node *curr=new struct Node();
        curr->data=data;
        curr->next=NULL;
        if(head==NULL)
        {
                return curr;
        }
	curr->next=head;
	head=curr;
	return head;
}
void display_linked_list(struct Node *head)
{
	if(head==NULL)
	{
		printf("The linked list is empty\n");
		return;
	}
	printf("The Linked List is:");
	struct Node* index_node=head;
	for(;index_node!=NULL;index_node=index_node->next)
	{
		if(index_node==head)
		{
			printf("%d",index_node->data);
		}
		else
		{
			printf(" %d",index_node->data);
		}
	}
	printf("\n");
}
int main()
{
	struct Node *linked_list_head=NULL;
	//since, it is made NULL, NULL checking is important in all files
	//however, if it is just declared and defined like: struct Node *linked_list_node;
	//the pointer is actually uninitialized pointer
	//So, it might not be detected in null checking (compiler depended). Hence, it could generate segmentation fault if we try to dereference it
	linked_list_head=insert_at_beginning(linked_list_head,2);
	linked_list_head=insert_at_end(linked_list_head,3);
	linked_list_head=insert_at_beginning(linked_list_head,1);
	display_linked_list(linked_list_head);	
	return 0;
}
