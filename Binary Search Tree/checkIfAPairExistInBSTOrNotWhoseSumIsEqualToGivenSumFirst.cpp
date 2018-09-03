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
bst_node* insert(struct bst_node *,int);
void find_pair(struct bst_node *,int);
/*this is recursive insert function*/
bool find_pair_util(struct bst_node *root,int sum,int &first_val,int &second_val)
{
	stack<struct bst_node*> inorder_traversal_container;
	stack<struct bst_node*> reverse_inorder_traversal_container;
	bool done1=false,done2=false;
	struct bst_node *first=root;
	struct bst_node *second=root;
	while(true)
	{
		//this is combined loop
		//will break when one element from inorder traversal + one element from reverse inorder traversal will be == sum
		//consider those nodes as first and second
		//now, loop will break in two cases:
		//first: 
		/*
			if(first->data+second->data==sum)
			
		*/
		//second
		/*
			if(first->data>=second->data)
				
		*/
		/*Now, this will be used for inorder traversal*/ 
		while(done1==false)
		{
			if(first!=NULL)
			{
				inorder_traversal_container.push(first);
				first=first->left;		
			}
			else
			{
				if(inorder_traversal_container.empty())
				{
					//curr will remain NULL		
					done1=true;
					//loop will break
				}
				else
				{
					first=inorder_traversal_container.top();
					inorder_traversal_container.pop();
					done1=true;
					//because, we need to compare
				}
			}
						
		}
		/*Now, this will be used for reverse inorder traversal*/
		while(done2==false)
		{
			if(second!=NULL)
			{
				reverse_inorder_traversal_container.push(second);
				second=second->right;
			}
			else
			{
				if(reverse_inorder_traversal_container.empty())
				{
					done2=true;
				}
				else
				{
					second=reverse_inorder_traversal_container.top();
					reverse_inorder_traversal_container.pop();
					done2=true;
					//because, we need to compare
				}
			}	
		}		
		if(first==NULL||second==NULL)
		{
			return false;
		}
		if(first->data>=second->data)
		{
			return false;
		}
		if(first->data+second->data==sum)
		{
			first_val=first->data;
			second_val=second->data;
			return true;
		}	
		if(first->data+second->data<sum)
		{
			//what does that mean?
			//first->data needs to be increased
			//so, in inorder traversal, we have to move to current node's successor node
			done1=false;
			//then only inorder_traversal will resume again
			first=first->right;
			//must be, because, before it, left subtree of current root is already handled and root is also already handled
		}
		//only one case remains
		else
		{
			//what does that mean?
			//second->data needs to be decreased
			//so, in reverse inorder traversal, we have to move to current nodde's successor node
			done2=false;
			//only reverse_inorder_traversal will resume again
			second=second->left;
			//must be, think of it. Because in case of reverse inorder traversal, the right subtree of current root and current root is already traversed
		}
						
	}	
}
void find_pair(struct bst_node *root,int sum)
{
	int first=INT_MAX;
	int second=INT_MAX;
	if(find_pair_util(root,sum,first,second))
	{
		printf("A pair is found as (%d,%d) with the given sum as %d\n",first,second,sum);
	}
	else
	{
		printf("No pair is found\n");
	}
}
int main()
{
	struct bst_node *root = new bst_node(15);
    	root->left = new bst_node(10);
    	root->right = new bst_node(20);
    	root->left->left =new  bst_node(8);
    	root->left->right = new bst_node(12);
    	root->right->left = new bst_node(16);
    	root->right->right = new bst_node(25);
	/*first test case
	int sum = 33;*/		
	/*second test case
	int sum=34;
	*/
	/*third test case
	int sum=-1
	*/
	int sum=-1;
	find_pair(root,sum);
	return 0;
}
