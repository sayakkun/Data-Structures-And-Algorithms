#include<bits/stdc++.h>
using namespace std;
template<class T,int size=32>
class myStack
{
    private:
        T stack[size];
        int topIdx;
        //it will be initialised to -1
        
    public:
        myStack();
        void push(T);
        T pop();
        bool empty();
        T top();
};
template<class T,int size>
myStack<T,size>::myStack()
{
	topIdx=-1;
}

template<class T,int size>
void myStack<T,size>::push(T n)
{
    if(topIdx==size-1)
    {
        throw "Stack is full";
    }
    stack[++topIdx]=n;
}
template<class T, int size>
T myStack<T,size>::pop()
{
    if(topIdx==-1)
    {
        throw "Stack is empty";
    }
    T elem=stack[topIdx--];
    return elem;
}
template <class T,int size>
T myStack<T,size>::top()
{
    if(topIdx==-1)
    {
        throw "Stack is empty";
    }
    return stack[topIdx];
}
template<class T,int size>
bool myStack<T,size>::empty()
{
    return (topIdx==-1);
}
int main()
{
    	myStack<int,40> myStack1;
    	myStack1.push(10);
   	myStack1.push(20);
    	myStack1.push(30);
	cout<<"The element popped from myStack1:"<<myStack1.pop()<<endl;
	cout<<"The element popped from myStack1:"<<myStack1.pop()<<endl;
	cout<<"The element popped from myStack1:"<<myStack1.pop()<<endl;

	myStack<int> myStack2;
	//created with the default size of 32
	myStack2.push(40);
	cout<<"The element popped from myStack2:"<<myStack2.pop()<<endl;
	return 0;
}
