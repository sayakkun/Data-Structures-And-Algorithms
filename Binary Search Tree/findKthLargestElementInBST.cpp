#include<bits/stdc++.h>
using namespace std;
class BST_NODE
{
	private:
		int data;
		BST_NODE *left;
		BST_NODE *right;
		int left_count;
		BST_NODE(int);
	public:
		friend class BST;
};
class BST
{
	private:
		 BST_NODE *root;
		 int total_count;
		 //just because we are writing an recusrsive inorder traversal
		void inorder_traversal_helper(BST_NODE *);
	public:
		BST();
		void insert(int);
		int find_kth_largest(int);
		void inorder_traversal();
};
BST_NODE::BST_NODE(int data)
{
	this->data=data;
	this->left=NULL;
	this->right=NULL;
	this->left_count=0;
}
BST::BST()
{
	root=NULL;
	total_count=0;
}
/*insert a value in the bst*/
void BST::insert(int data)
{
	BST_NODE *curr=new BST_NODE(data);
	total_count++;
	if(root==NULL)
	{
		root=curr;
		return;
	}
	BST_NODE *it=root;
	while(true)
	{
		if(data<it->data)
		{
			if(it->left==NULL)
			{
				it->left_count++;
				it->left=curr;
				break;
			}		
			else
			{
				it->left_count++;
				it=it->left;
			}
		}
		else if(data==it->data)
		{
			throw "Duplicate value is not supported in this bst";
		}
		else
		{
			if(it->right==NULL)
			{
				it->right=curr;
				break;
			}
			else
			{
				it=it->right;
			}
		}	
	}
}
int BST::find_kth_largest(int k)
{
	//that is one good way
	//with maintaining one additional variable
	//and without changing the algo
	//because, if you maintain right_count which is the number of nodes in the right subtree for a particular node
	//it will become more complex
	int needed_k=total_count+1-k;
	//for 1st largest element it would be total_count+1th smallest element
	if(root==NULL)
	{
		throw "The tree is empty. Hence, order statistics cannot be performed";
	}
	BST_NODE *it=root;
	while(true)
	{
		if(it==NULL)
		{
			//throw "Position out of bound (in 1 indexing)";
			return INT_MAX;
		}
		if(it->left_count+1==needed_k)
		{
			return it->data;
		}
		if(it->left_count+1>needed_k)
		{
			//it will be present in left subtree of course
			it=it->left;
		}
		else
		{
			needed_k-=(it->left_count+1);
			it=it->right;
		}
	}
}
void BST::inorder_traversal_helper(BST_NODE *it)
{
	if(it==NULL)
	{
		return;
	}
	inorder_traversal_helper(it->left);
	printf("%d ",it->data);
	inorder_traversal_helper(it->right);
}
void BST::inorder_traversal()
{
	printf("The inorder traversal of the tree is following\n");
	inorder_traversal_helper(root);
	printf("\n");
}
int main()
{
	BST my_bst;
	int ele[]={ 20, 8, 22, 4, 12, 10, 14 };
	int n=sizeof(ele)/sizeof(int);
	try
	{
		for(int i=0;i<n;i++)
		{
			my_bst.insert(ele[i]);
			my_bst.inorder_traversal();
		}
		//insertion is done
		printf("The 1st largest element is %d\n",my_bst.find_kth_largest(1));		
		printf("The 2nd largest element is %d\n",my_bst.find_kth_largest(2));
		printf("The 3rd largest element is %d\n",my_bst.find_kth_largest(3));	
		printf("The 4th largest element is %d\n",my_bst.find_kth_largest(4));
		printf("The 5th largest element is %d\n",my_bst.find_kth_largest(5));
		printf("The 6th largest element is %d\n",my_bst.find_kth_largest(6));
		printf("The 7th largest element is %d\n",my_bst.find_kth_largest(7));	
		//the out of bound index checking
		printf("The 0th largest element is %d\n",my_bst.find_kth_largest(0));
		printf("The 8th largest element is %d\n",my_bst.find_kth_largest(8));
	}
	catch(const char *e)
	{
		printf("The exception is %s\n",e);
	}	
}
	
