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
bool delete_in_trie_util(struct trie_node *&root,struct trie_node *curr_root,string str,int curr_index);
void delete_in_trie(struct trie_node *&root,string str);
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
			curr->nodes.insert(make_pair(str[i],create_new_trie_node()));
                }
                curr=curr->nodes.find(str[i])->second;
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
                if(curr->nodes.find(str[i])==curr->nodes.end())
                {
			
                        return false;
                }
                else
                {
			
                	curr=curr->nodes.find(str[i])->second;
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
bool delete_in_trie_util(struct trie_node *&root,struct trie_node *curr_root,string str,int curr_index)
{
	if(curr_index==str.size())
	{
		curr_root->is_word_ended=false;
		if(curr_root->nodes.empty())
		{
			//printf("True is returned for character %c\n",str[curr_index-1]);
			return true;
			//a notification type mecchanism
		}
		/*printf("the character for which is it is called %c\n",str[curr_index-1]);
		map<char,struct trie_node*>::iterator it;
		for(it=curr_root->nodes.begin();it!=curr_root->nodes.end();it++)
		{
			printf("The character %c\n",it->first);
		}*/
		return false;	
	}
	if(curr_root->nodes.find(str[curr_index])==curr_root->nodes.end())
        {
		//that means the str does not exist
		return false;
	}
	if(delete_in_trie_util(root,curr_root->nodes[str[curr_index]],str,curr_index+1))
	{
		struct trie_node *temp=curr_root->nodes[str[curr_index]];
		delete temp;
		//we can safely delete it
		printf("The character %c is deleted\n",str[curr_index]);
		map<char,struct trie_node*>::iterator it;
                /*for(it=curr_root->nodes.begin();it!=curr_root->nodes.end();it++)
                {
                 	printf("The character %c\n",it->first);
                }*/
		curr_root->nodes.erase(curr_root->nodes.find(str[curr_index]));
		if(curr_root->nodes.empty())
		{
			//curr_root->nodes.erase(curr_index);
			return true;
		}
		else
		{
			/*map<char,struct trie_node*>::iterator it;
                	for(it=curr_root->nodes.begin();it!=curr_root->nodes.end();it++)
                	{
                        	printf("The character %c\n",it->first);
                	}*/
			return false;
		}
	}
	else
	{
		return false;
	}
}		
void delete_in_trie(struct trie_node *&root,string str)
{
	if(str.empty())
	{
		printf("The string is an empty stringi.Hence, cannot be deleted\n");
	}
	delete_in_trie_util(root,root,str,0);
	if(root->nodes.empty())
        {
                root=NULL;
        }
}
//test it
int main()
{
	string keys[] = {"the", "a", "there"};
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
	 string str4="a";
        cout<<"The string "<<str4<<" is going to be deleted"<<endl;
        delete_in_trie(root,str4);
        string str5="there";
        cout<<"The string "<<str5<<" is going to be deleted"<<endl;
        delete_in_trie(root,str5);
        cout<<"The string "<<str4<<" is"<<(search_in_trie(root,str4)?"":" not")<<" found"<<endl;
        cout<<"The string "<<str5<<" is"<<(search_in_trie(root,str5)?"":" not")<<" found"<<endl;
        if(root==NULL)
        {
                printf("The trie's root becomes NULL\n");
        }
        insert_in_trie(root,"Hello");
        string str6="Hello";
        cout<<"The string "<<str6<<" is"<<(search_in_trie(root,str6)?"":" not")<<" found"<<endl;
	return 0;
}
	
