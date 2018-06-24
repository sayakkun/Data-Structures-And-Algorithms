#include<bits/stdc++.h>
using namespace std;
struct trie_node
{
	map<char,struct trie_node*> nodes;
	bool is_word_ended;
	//for marking the leaf
};
struct trie_node *create_new_trie_node();
void insert_in_trie(struct trie_node *&root,string str);
bool search_in_trie(struct trie_node *root);
bool delete_in_trie_util(struct trie_node *root,struct trie_node *curr_root,string str,int curr_index);
void delete_in_trie(struct trie_node *root,string str);
struct trie_node *create_new_trie_node()
{
	struct trie_node *new_trie_node=NULL;
        try
        {
                new_trie_node=new trie_node();
                new_trie_node->is_word_ended=false;
        }
        catch(const bad_alloc& e)
        {
                printf("Memory could be allocated for new_trie_node\n");
                exit(EXIT_FAILURE);
        }
        return new_trie_node;
}	
void insert_in_trie(struct trie_node *&root,string str)
{
	//using c++ reference feature
	//
        if(str.empty())
        {
                return;
        }
        int str_length=str.size();
        if(str_length==0)
        {
                return;
        }
        if(root==NULL)
        {
                root=create_new_trie_node();

        }
        struct trie_node *curr=root;
        for(int i=0;i<str_length;i++)
        {
                if(curr->nodes.find(str[i])==curr->nodes.end())
                {
                        curr->nodes[str[i]]=create_new_trie_node();
                }
                curr=curr->nodes[str[i]];
        }
        curr->is_word_ended=true;
}
bool search_in_trie(struct trie_node *root,string str) 
{
	//you cannot make the function const 
	//as a non member function cannot be declared as const
        if(str.empty())
        {
                printf("The string is an empty string\n");
                return true;
        }
        int str_length=str.size();
        if(str_length==0)
        {
                return true;
        }
        if(root==NULL)
        {
                printf("The root of the trie_node is NULL\n");
                return false;
        }
        struct trie_node *curr=root;
        for(int i=0;i<str_length;i++)
        {
                if(curr->nodes[str[i]]==NULL)
                {
                        return false;
                }
                else
                {
                        curr=curr->nodes[str[i]];
                }
        }
        if(curr->is_word_ended==true)
        {
  		return true;
	}
	else
	{
		//otherwise, the search_in_trie string is a prefix of some other string
		return false;
	}
}
bool delete_in_trie_util(struct trie_node *root,struct trie_node *curr_root,string str,int curr_index)
{
	if(curr_index==str.size())
	{
		curr_root->is_word_ended=false;
		if(curr_root->nodes.empty())
		{
			//no child to traverse..
			//So, no word exists with str prefix
			//we can safely delete the node
			delete curr_root;
			return true;
			//a notification type mecchanism
		}
		return false;	
	}
	if(curr_root->nodes.find(str[curr_index])==curr_root->nodes.end())
        {
		//that means the str does not exist
		return false;
	}
	if(delete_in_trie_util(root,curr_root->nodes[str[curr_index]],str,curr_index+1))
	{
		if(curr_root->nodes.empty())
		{
			if(curr_root==root)
			{
				root=NULL;
			}
			else
			{
				delete curr_root;
			}
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}		
void delete_in_trie(struct trie_node *root,string str)
{
	if(str.empty())
	{
		printf("The string is an empty stringi.Hence, cannot be deleted\n");
	}
	delete_in_trie_util(root,root,str,0);

}
//test it
int main()
{
	string keys[] = {"the", "a", "there","answer", "any", "by","bye", "their" };
	int n = sizeof(keys)/sizeof(keys[0]);
	struct trie_node *root=NULL;
	//if root is null for the very first time we can give it a predictable behaviour
	//otherwise, we cannot 
	for (int i = 0; i < n; i++)
        {
		insert_in_trie(root, keys[i]);
 	}
	string str1="the";
    	//search_in_trie(root,str1)? cout << "Yes\n" :cout << "No\n";
    	cout<<"The string "<<str1<<" is"<<(search_in_trie(root,str1)?"":" not")<<" found"<<endl;
	string str2="these";
	cout<<"The string "<<str2<<" is"<<(search_in_trie(root,str2)?"":" not")<<" found"<<endl;
    	cout<<"The string the is going to be deleted"<<endl;
	delete_in_trie(root,str1);
	cout<<"The string "<<str1<<" is"<<(search_in_trie(root,str1)?"":" not")<<" found"<<endl;
	string str3="there";
	cout<<"The string "<<str3<<" is"<<(search_in_trie(root,str3)?"":" not")<<" found"<<endl;
	return 0;
}
	
