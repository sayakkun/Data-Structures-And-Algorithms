#include<cstdio>
#include<iostream>
class Node
{
	private:
		int key;
		Node *next;
	public:
		Node();
		Node(int);
		int get_key();
		Node* get_node();
		void set_next(Node *);
		~Node();
		friend class LinkedList;
};
class LinkedList
{
	private:
		Node *head;
	public:
		LinkedList();
		void insert_at_beginning(int);
		void insert_at_end(int);
		void display_linked_list() const;
		~LinkedList();
};
//friend Node LinkedList;
Node::Node()
{
	//an empty contructor
}
Node::Node(int key)
{
	this->key=key;
	this->next=NULL;
}
int Node::get_key()
{
	return this->key;
}
Node* Node::get_node()
{
	//Now, this is a pointer
	//could we return this?
	return this;
}
void Node::set_next(Node *to_be_next)
{
	this->next=to_be_next;
}
Node::~Node()
{
	//free next;
	delete next;
	//otherwise, the memory will remain allocated in case of a big program
	//and we cannot reuse the heap memory
}
LinkedList::LinkedList()
{
	head=NULL;
}
void LinkedList::insert_at_beginning(int data)
{
	//now, since, LinkedList is a friend class of Node we can access the private members directly
	Node *curr=new Node();
	//allocate memory for pointer to a class dynamically
	curr->key=data;
	curr->next=NULL;
	//since, LinkedList is a friend class
	if(head==NULL)
	{
		head=curr;
		return;
	}
	curr->next=head;
	head=curr;
	//implmentation of singly linked list
	//curr cannot be freed
	//as it is assigned as a node in linked list
}
void LinkedList::insert_at_end(int data)
{
	Node *curr=new Node();
	//now, sincce, LinkedList is a friend class of Node 
	//we can access the private members directly
	curr->key=data;
	curr->next=NULL;
	if(head==NULL)
	{
		head=curr;
		return;
	}
	Node *index_node=head;
	for(;index_node->next!=NULL;index_node=index_node->next)
	{
	}
	index_node->next=curr;
	//this is done	
	//Now, index_node is not freed
	//why?
	//because, it has not it's own memory allocated from heap
	//hence, it will not cause memory leak
	//it is allocated from stack memory
	//will be freed when the function insert_at_end ends
	//but this pointer points to some memory location (since, it is alias to some pointer whose memory is allocated dynamically)
	//so, freeing it would actually free that memory, which will cause problem in current context
	//that is what I can explain from my knowledge
}	
void LinkedList::display_linked_list()const
{
	printf("The linkedlist is: ");
	Node *index_node=head;
	for(;index_node!=NULL;index_node=index_node->next)
	{
		if(index_node==head)
		{
			printf("%d",index_node->key);
		}
		else
		{
			printf(" %d",index_node->key);
		}
	}
}
LinkedList::~LinkedList()
{
	//free head;
	delete head;
	//generally memory allocated by new will be freed by delete function
}
int main()
{
	LinkedList curr_list;
	//default constructor will be invoked
	curr_list.insert_at_end(2);
	curr_list.insert_at_beginning(1);
	curr_list.insert_at_end(3);
	curr_list.display_linked_list();
	return 0;
	//now, curr_list goes out of scope
	//so, destructor will be invoked
}
