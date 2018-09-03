#include<bits/stdc++.h>
using namespace std;
struct BST_Node
{
	int data;
	struct BST_Node *left;
	struct BST_Node *right;
	BST_Node(int data)
	{
		this->data=data;
		this->left=NULL;
		this->right=NULL;
	}
};
void inorder_traversal(struct BST_Node *,vector<int> &);
void preorder_traversal(struct BST_Node *);
struct BST_Node* build_balanced_bst(struct BST_Node *);
struct BST_Node* build_balanced_bst_util(vector<int> ,int,int);
void inorder_traversal(struct BST_Node *root,vector<int> &container)
{
	if(root==NULL)
	{
		return;
	}
	inorder_traversal(root->left,container);
	//printf("%d ",root->data);
	container.push_back(root->data);
	inorder_traversal(root->right,container);
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
/*
s: start
e: end*/
struct BST_Node *build_balanced_bst_util(vector<int> container,int s,int e)
{
	if(s>e)
	{
		return NULL;
	}
	if(s==e)
	{
		return new BST_Node(container[s]);
	}
	int mid=(s+e)/2;
	struct BST_Node *root=new BST_Node(container[mid]);
	root->left=build_balanced_bst_util(container,s,mid-1);
	root->right=build_balanced_bst_util(container,mid+1,e);
	return root;
	
}
struct BST_Node *build_balanced_bst(struct BST_Node *root)
{
	vector<int> container;
	//the container is empty
	inorder_traversal(root,container);
	//now,reference of the container is sent
	//after, inorder_traversal is called, it will contain the inorder traversal of it
	return build_balanced_bst_util(container,0,container.size()-1);
}
int main()
{
	 /* Constructed skewed binary tree is
                10
               /
              8
             /
            7
           /
          6
         /
        5   */
 
	BST_Node* root = new BST_Node(10);
    	root->left = new BST_Node(8);
    	root->left->left = new BST_Node(7);
    	root->left->left->left = new BST_Node(6);
    	root->left->left->left->left =new BST_Node(5);
    	root=build_balanced_bst(root);
	printf("Printing the balanced bst in preorder\n");
	preorder_traversal(root);
	printf("\n");
	return 0;
}
