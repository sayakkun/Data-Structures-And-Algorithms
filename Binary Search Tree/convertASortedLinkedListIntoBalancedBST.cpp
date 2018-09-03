#include<bits/stdc++.h>
using namespace std;
struct BST_Node
{
	int data;
	BST_Node *left;
	BST_Node *right;
	BST_Node(int data)
	{
		this->data=data;
		this->left=NULL;
		this->right=NULL;
	}
};
struct L_Node
{
	int data;
	struct L_Node *next;
	L_Node(int data)
	{
		this->data=data;
		this->next=next;
	}
};
/*Basically push function
it inserts a node at the beginning*/
struct L_Node* insert_at_beginning(struct L_Node *,int);
void display_linked_list(struct L_Node *);
struct BST_Node* build_balanced_BST(struct L_Node *&,int);
struct L_Node* insert_at_beginning(struct L_Node *head,int data)
{
	struct L_Node *curr=new L_Node(data);
	if(head==NULL)
	{
		return curr;
	}
	curr->next=head;
	head=curr;
	return head;
}	
void display_linked_list(struct L_Node *head)
{
	struct L_Node *it=head;
	for(;it!=NULL;it=it->next)
	{
		if(it==head)
		{
			printf("%d",it->data);
		}
		else
		{
			printf("->%d",it->data);
		}
	}
	printf("\n");
}
struct BST_Node* build_balanced_BST(struct L_Node *&head,int n)
{
	//node that, we pass head node pointer's reference here
	//and traversing the linkedlist using it
	if(n<=0)
	{
		return NULL;
	}
	/* Recursively construct the left subtree */
	struct BST_Node *left=build_balanced_BST(head,n/2);
	struct BST_Node *root =new BST_Node(head->data);
	root->left=left;
	head=head->next;
	root->right=build_balanced_BST(head,n-n/2-1);
	return root;	
}
void preorder_traversal(struct BST_Node *root)
{
	if(root==NULL)
	{
		return;
	}
	printf("%d ",root->data);
	preorder_traversal(root->left);
	preorder_traversal(root->right);
}
int main()
{	
	struct L_Node *head=NULL;
	int arr[] = {7,6,5,4,3,2,1};
	int n=sizeof(arr)/sizeof(int);
	for(int i=0;i<n;i++)
	{
		head=insert_at_beginning(head,arr[i]);
	}
	//display_linked_list(head);
	BST_Node *root=build_balanced_BST(head,n);
	printf("Preorder traversal of the sorted bst\n");
	preorder_traversal(root);
	printf("\n");
	return 0;
}
