#include<bits/stdc++.h>
using namespace std;
/*uses the idea of inorder traversal using stack*/
struct BST_Node
{
	int data;
	struct BST_Node *left;
	struct BST_Node *right;
	BST_Node(int data)
	{
		this->data=data;
		this->left=NULL;
		this->right=right;
	}
};
/*
idea inorder_traversal
since, since, inorder traversal is sorted for BST
*/
void inorder_traversal(struct BST_Node *);
struct BST_Node *insert(struct BST_Node *,int);
void find_predecessor_and_successor(struct BST_Node *,int);
void find_predecessor_and_successor(struct BST_Node *root,int data)
{
	if(root==NULL)
	{
		return;
	}
	stack<struct BST_Node*> inorder_traversal_container;
	struct BST_Node *curr=root;
	int curr_data=INT_MAX,pre=INT_MAX,succ=INT_MIN;
	bool flag=false;
	//curr_data will keep track of the values we get at each step of inorder traversal
	while(true)
	{
		if(curr!=NULL)
		{
			inorder_traversal_container.push(curr);
			curr=curr->left;
		}
		else
		{	
			if(inorder_traversal_container.empty())
			{
				break;
				//the inorder traversal using stack is over
			}
			else
			{		
				curr=inorder_traversal_container.top();
				inorder_traversal_container.pop();
				//printf("curr data is %d\n",curr->data);
				if(curr->data==data)
				{
					if(curr_data!=INT_MAX)
					{
						pre=curr_data;
					}
					else
					{
						//no predecessor is there
						flag=true;
						//printf("This is set\n");
					}			
					//first take the data
					//as this is still containing the previous value
				}
				else
				{
					//otherwise, after pre is set
					//this will get executed
					if(pre!=INT_MAX||flag==true)
					{
						succ=curr->data;
						break;		
						//there is no point of traversing more
					}	
				}
				curr_data=curr->data;
				//curr_data is set
				curr=curr->right;
			}
		}
	}
	printf("The current value %d\n",data);
	if(pre==INT_MAX)
	{
		printf("The predecessor is not found\n");
	}
	else
	{
		printf("The predecesssor is found as: %d\n",pre);
	}
	if(succ==INT_MIN)
	{
		printf("The successor is not found\n");
	}
	else
	{
		printf("The successor is found as: %d\n",succ);
	}
	printf("\n");	
}
void inorder_traversal(struct BST_Node *root)
{
	if(root==NULL)
	{
		return;
	}
	inorder_traversal(root->left);
	printf("%d ",root->data);
	inorder_traversal(root->right);
}
struct BST_Node *insert(struct BST_Node *root,int data)
{
	if(root==NULL)
	{
		return new BST_Node(data);
	}
	if(root->data==data)
	{
		throw "This version of BST does not support duplicate key insertion";
	}
	if(root->data>data)
	{
		//it will be inserted in left subtree
		root->left=insert(root->left,data);
	}
	else
	{
		root->right=insert(root->right,data);	
	}
	return root;
	
}
int main()
{
	struct BST_Node *root=NULL;
	root=insert(root,4);
	root=insert(root,2);
	root=insert(root,6);
	root=insert(root,1);
	root=insert(root,3);
	root=insert(root,5);
	root=insert(root,7);
	/*
			4
		       / \
                      2   6
		     / \ / \
		    1  3 5  7
	*/
	find_predecessor_and_successor(root,1);				
	find_predecessor_and_successor(root,2);
	find_predecessor_and_successor(root,3);
	find_predecessor_and_successor(root,4);
	find_predecessor_and_successor(root,5);
	find_predecessor_and_successor(root,6);
	find_predecessor_and_successor(root,7);
	//find_predecessor_and_successor(root,8);
	/*I think it will pass as it covers all the test cases*/
	return 0;
}
