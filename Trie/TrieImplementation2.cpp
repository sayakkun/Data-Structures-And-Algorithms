#include<bits/stdc++.h>
using namespace std;
struct trie_node
{
	map<char,struct trie_node*> nodes;
	bool is_word_ended;
	//for marking the leaf
};
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
void insert(struct trie_node *&root,string str)
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
bool search(struct trie_node *root,string str) 
{
	//you cannot make the function const 
	//as a non member function cannot be declared as const
        if(str.empty())
        {
                printf("The pointer str does not point to any memory location\n");
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
		//otherwise, the search string is a prefix of some other string
		return false;
	}
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
		insert(root, keys[i]);
 	}
	string str1="the";
    	//search(root,str1)? cout << "Yes\n" :cout << "No\n";
    	cout<<"The string "<<str1<<" is"<<(search(root,str1)?"":" not")<<" found"<<endl;
	string str2="these";
	cout<<"The string "<<str2<<" is"<<(search(root,str2)?"":" not")<<" found"<<endl;
    	return 0;
}
	
