#include<bits/stdc++.h>
using namespace std;
/*second way of doing it in O(h)*/
/*Now, I personally find the first one is better*/
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
	struct bst_node *curr1=root;
	struct bst_node *curr2=root;	
	int first,second;
	while(true)
	{
		//this is combined loop
		//will break when one element from inorder traversal + one element from reverse inorder traversal will be == sum
		//consider those nodes as curr1 and curr2
		//now, loop will break in two cases:
		//first way: 
		/*
			if(curr1->data+curr2->data==sum)
			
		*/
		//second way
		/*
			if(curr1->data>=curr2->data)
				
		*/
		/*Now, this will be used for inorder traversal*/ 
		while(done1==false)
		{
			if(curr1!=NULL)
			{
				inorder_traversal_container.push(curr1);
				curr1=curr1->left;		
			}
			else
			{
				if(inorder_traversal_container.empty())
				{
					done1=true;
					curr1=NULL;
				}
				else
				{
					curr1=inorder_traversal_container.top();
					inorder_traversal_container.pop();
					first=curr1->data;
					inorder_traversal_container.push(curr1->right);
					curr1=curr1->right;
					//now, here, unlike the last program, we inserted the current root's right here
					done1=true;
					//because, we need to compare
				}
			}
						
		}
		/*Now, this will be used for reverse inorder traversal*/
		while(done2==false)
		{
			if(curr2!=NULL)
			{
				reverse_inorder_traversal_container.push(curr2);
				curr2=curr2->right;
			}
			else
			{
				if(reverse_inorder_traversal_container.empty())
				{
					done2=true;
					curr2=NULL;
				}
				else
				{
					curr2=reverse_inorder_traversal_container.top();
					reverse_inorder_traversal_container.pop();
					second=curr2->data;
					reverse_inorder_traversal_container.push(curr2->left);
					curr2=curr2->left;
					done2=true;
					//because, we need to compare
				}
			}	
		}		
		if(curr1==NULL||curr2==NULL)//either inorder traversal or reverse inorder traversal is finished and the pair is not found yet
		{
			return false;
		}
		if(first>=second)//considering that the bst will contain only unique keys
		{
			return false;
		}
		if(first+second==sum)
		{
			first_val=first;
			second_val=second;
			return true;
		}	
		if(first+second<sum)
		{
			//what does that mean?
			//curr1->data needs to be increased
			//so, in inorder traversal, we have to move to current node's successor node
			done1=false;
			//then only inorder_traversal will resume again
		}
		//only one case remains
		else
		{
			//what does that mean?
			//curr2->data needs to be decreased
			//so, in reverse inorder traversal, we have to move to current nodde's successor node
			done2=false;
			//only reverse inorder traversal is to be resumed	
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
	/*first test case*/
	/*
	int sum = 33;
	*/
	/*Second test case
	int sum=34;
	*/
	/*third test case*/
	int sum=-1;
	find_pair(root,sum);
	return 0;
}
/*Now, only very effective in case of balanced bst
Otherwise, you can choose the apporach with no space complexity
i.e. first converting it to in place DLL
after that check using two pointer*/
