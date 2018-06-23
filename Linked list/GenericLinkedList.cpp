#include<bits/stdc++.h>
using namespace std;
template <class T>
class Node
{
	private:
		T key;
		Node<T> *next;
	public:
		Node();
		Node(T);
		T get_key();
		Node<T>* get_node();
		void set_next(Node<T> *);
		~Node();
		template<class U>
		/*template parameters cannot shadow each other 
		hence, nest templates must have different template names*/
		friend class LinkedList;
};
template <class T>
class LinkedList
{
	private:
		Node<T> *head;
	public:
		LinkedList();
		void insert_at_beginning(T);
		void insert_at_end(T);
		void display_linked_list() const;
		~LinkedList();
};
//friend Node LinkedList;
template <class T>
Node<T>::Node()
{
	//an empty contructor
}
template <class T>
Node<T>::Node(T key)
{
	this->key=key;
	this->next=NULL;
}
template <class T>
T Node<T>::get_key()
{
	return this->key;
}
template<class T>
Node<T>* Node<T>::get_node()
{
	//Now, this is a pointer
	//could we return this?
	return this;
}
template<class T>
void Node<T>::set_next(Node<T> *to_be_next)
{
	this->next=to_be_next;
}
template <class T>
Node<T>::~Node()
{
	//free next;
	delete next;
	//otherwise, the memory will remain allocated in case of a big program
	//and we cannot reuse the heap memory
}
template <class T>
LinkedList<T>::LinkedList()
{
	head=NULL;
}
template <class T>
void LinkedList<T>::insert_at_beginning(T data)
{
	//now, since, LinkedList is a friend class of Node we can access the private members directly
	Node <T>*curr=new Node<T>();
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
template <class T>
void LinkedList<T>::insert_at_end(T data)
{
	Node <T>*curr=new Node<T>();
	//now, sincce, LinkedList is a friend class of Node 
	//we can access the private members directly
	curr->key=data;
	curr->next=NULL;
	if(head==NULL)
	{
		head=curr;
		return;
	}
	Node <T>*index_node=head;
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
template <class T>
void LinkedList<T>::display_linked_list()const
{
	printf("The linkedlist is: ");
	Node <T>*index_node=head;
	for(;index_node!=NULL;index_node=index_node->next)
	{
		if(index_node==head)
		{
			cout<<index_node->key;
		}
		else
		{
			cout<<"->"<<index_node->key;
		}
	}
	cout<<endl;
}
template <class T>
LinkedList<T>::~LinkedList()
{
	delete head;
	//generally memory allocated by new will be freed by delete function
}
int main()
{
	LinkedList<int> curr_list;
	//default constructor will be invoked
	curr_list.insert_at_end(2);
	curr_list.insert_at_beginning(1);
	curr_list.insert_at_end(3);
	curr_list.display_linked_list();
	return 0;
	//now, curr_list goes out of scope
	//so, destructor will be invoked
}

