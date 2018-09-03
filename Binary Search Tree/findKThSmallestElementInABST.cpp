/*
Performance: O(h) is case of balanced bst tree
O(n): worst case in case of normal bst when the bst is scewed*/
#include<bits/stdc++.h>
using namespace std;
struct bst_node
{
	int data;
	struct bst_node *left;
	struct bst_node *right;
	int left_count;
	//left_count is the number of nodes in the left subtree for the current node
	bst_node(int data)
	{
		this->data=data;
		this->left=NULL;
		this->right=NULL;
		this->left_count=0;
	}
};
/*insert in a bst*/
struct bst_node *insert(struct bst_node *root,int data)
{
	if(root==NULL)
	{
		struct bst_node *curr=new bst_node(data);
		return curr;
	}
	if(root->data==data)
	{
		throw "Duplicate data is not supported in this bst";
	}
	if(root->data>data)
	{
		//left bst_insert
		root->left=insert(root->left,data);
		root->left_count++;
		return root;
	}
	//root->data<data
	//right subtree insertion
	root->right=insert(root->right,data);
	return root;		
}
/*convention: if we wont find the kth smallest element here, we will return INT_MAX
*/
int find_kth_smallest(struct bst_node *root,int k)
{
	if(root==NULL)
	{
		return INT_MAX;
	}
	if(k==root->left_count+1)
	{
		return root->data;
	}
	if(k<root->left_count+1)
	{
		//we need to find it in the left subtree
		return find_kth_smallest(root->left,k);
	}
	//obviously, otherwise, we need to visit the right subtree
	//now, the count should be decreased by root->left_count+1
	//as upto this count, we can find it in root or root's left subtree
	return find_kth_smallest(root->right,k-(root->left_count+1));
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
int main()
{
	try
	{
		int ele[] = { 20, 8, 22, 4, 12, 10, 14 };
		int n=sizeof(ele)/sizeof(int);
		//now, inserting elements from an array will be easier to code
		//as, we just need to run a loop
		struct bst_node *root=NULL;
		for(int i=0;i<n;i++)
		{
			root=insert(root,ele[i]);
			/*printf("The inorder traversal of bst is:");
			inorder_traversal(root);
			printf("\n");
			*/
		}
		printf("The first smallest element is: %d\n",find_kth_smallest(root,1));
		printf("The second smallest element is: %d\n",find_kth_smallest(root,2));
		printf("The third smallest element is: %d\n",find_kth_smallest(root,3));
		printf("The fourth smallest element is: %d\n",find_kth_smallest(root,4));
		printf("The fifth smallest element is: %d\n",find_kth_smallest(root,5));
		//test cases for index out of bound
		/*printf("The Oth smallest element is: %d\n",find_kth_smallest(root,0));		
		printf("The 8th smallest element is: %d\n",find_kth_smallest(root,8));
		worked ok
		*/
	}
	catch(const char* e)
	{
		printf("The exception is: %s\n",e);
	}
	return 0;
}
