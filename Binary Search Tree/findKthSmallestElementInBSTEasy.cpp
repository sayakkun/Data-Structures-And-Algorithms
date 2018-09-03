//this solves the problem in O(n)
//when it is highly beeneficial
//when you have to do order statistics only one time and memory constraints are there
#include<bits/stdc++.h>
using namespace std;
struct bst_node
{
	int data;
	struct bst_node *left;
	struct bst_node *right;
	bst_node(int data)
	{
		this->data=data;
		this->left=left;
		this->right=right;
	}
};
struct bst_node *insert(struct bst_node *,int);
void inorder_traversal(struct bst_node *);
struct bst_node *insert(struct bst_node *root,int data)
{
	if(root==NULL)
	{
		struct bst_node *curr=new bst_node(data);
		return curr;
	}	
	if(root->data>data)
	{
		//it is to be inserted in left subtree
		root->left=insert(root->left,data);
	}
	else
	{
		root->right=insert(root->right,data);
	}
	return root;	
}
void inorder_traversal(struct bst_node *root)
{
	if(root==NULL)
	{
		return;
	}
	inorder_traversal(root->left);
	printf("%d ",root->data);
	inorder_traversal(root->right);
}
int find_kth_smallest_util(struct bst_node *root,int k,int &count)
{
	
	if(root==NULL)
	{
		return INT_MAX;
	}
	int val;
	if((val=find_kth_smallest_util(root->left,k,count))!=INT_MAX)
	{
		return val;
	}
	//now, play the inorder traversal here
	//here, increment the count and check
	count++;
	if(count==k)
	{
		return root->data;
	}
	return find_kth_smallest_util(root->right,k,count); 
}
int find_kth_smallest(struct bst_node *root,int k)
{
	if(k<=0)
	{
		throw "k cannot be <=0";
	}
	int count=0;
	return find_kth_smallest_util(root,k,count);
}
int main()
{
	struct bst_node *root=NULL;
	int ele[] = { 20, 8, 22, 4, 12, 10, 14 };
        int n=sizeof(ele)/sizeof(int);
	for(int i=0;i<n;i++)
	{
		root=insert(root,ele[i]);
		printf("The inorder traversal of the tree is following: ");
		inorder_traversal(root);
		printf("\n");
	}
	try
	{
		printf("The first smallest element is: %d\n",find_kth_smallest(root,1));
                printf("The second smallest element is: %d\n",find_kth_smallest(root,2));
                printf("The third smallest element is: %d\n",find_kth_smallest(root,3));
                printf("The fourth smallest element is: %d\n",find_kth_smallest(root,4));
                printf("The fifth smallest element is: %d\n",find_kth_smallest(root,5));
	}
	catch(const char *e)
	{
		printf("The exception thrown is %s\n",e);
	}
	return 0;
}
