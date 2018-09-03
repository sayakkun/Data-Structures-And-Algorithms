#include<bits/stdc++.h>
using namespace std;
/*uses the iddea of recursive inorder traversal*/
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
void find_predecessor_and_successor_util(struct BST_Node *,int,struct BST_Node *&,int &,int &,bool &);
void find_predecessor_and_successor(struct BST_Node *,int);
void inorder_traversal(struct BST_Node *);
struct BST_Node* insert(struct BST_Node *,int);
void find_predecessor_and_successor_util(struct BST_Node *root,int data,struct BST_Node *&pre,int &pre_data,int &succ_data)
{
	if(root==NULL)
	{
		return;
	}
	if(pre_data!=INT_MAX&&succ_data!=INT_MIN)
	{
		//both are found
		//we can return
		return;
	}
	/*
	if it exists for improving the time complexity
	case like
			2
		       / \
                      1   3 
	will pass if we are looking for 2's successor and predecessor
	but, 
		
			4
                       / \
                      2   6
                     / \ / \
                    1  3 5  7
	will not pass: 
	if you are looking for 4's successor
	because, this block will return the result as 6	
	if(pre_data!=INT_MAX)
	{
		//but, succ data is not found and right subtree is called
		succ_data=root->data;
		return;
	}
	*/
	//both are not found
	//left subtree is called
	find_predecessor_and_successor_util(root->left,data,pre,pre_data,succ_data);
	//for the first call pre is set as NULL from outside the function call
	//if root->data==data
	//that means the exact prev node in inorder traversal was the predecessor 
	if(root->data==data)
	{
		if(pre!=NULL)
		{
			pre_data=pre->data;
		}
		//otherwise, pre_data will remain as NULL
	}
	else
	{
		//left subtree is traversed and both are found
		if(pre_data==INT_MAX&&succ_data==INT_MIN&&pre!=NULL&&pre->data==data)
                {
                        succ_data=root->data;
                        return;
                }

		if(pre_data!=INT_MAX&&succ_data!=INT_MIN)
		{
			return;
		}
		//left subtree traversed and omly predecesssor is found
		if(pre_data!=INT_MAX)
		{
			succ_data=root->data;
			return;
		}
	}
	pre=root;
	return find_predecessor_and_successor_util(root->right,data,pre,pre_data,succ_data);	
	/*though the return statement does not matter here
	as the last statement
	*/
}
void find_predecessor_and_successor(struct BST_Node *root,int data)
{
	struct BST_Node *pre=NULL;
	int pre_data=INT_MAX;
	int succ_data=INT_MIN;
	find_predecessor_and_successor_util(root,data,pre,pre_data,succ_data);
	if(pre_data==INT_MAX)
	{
		printf("The predecessor is not found\n");
	}
	else
	{
		printf("The predecessor is found as %d\n",pre_data);
	}
	if(succ_data==INT_MIN)
	{
		printf("The successor is not found\n");
	}
	else
	{
		printf("The successor is found as %d\n",succ_data);
	} 
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
