import java.util.ArrayList;
class GenericStack<T>
{
        private ArrayList<T> container;
        private int top;
        GenericStack()
        {
                container=new ArrayList<>();
                top=0;
        }
        public int size()
        {
                return top;
        }
        public void push(T item)
        {
                container.add(top++,item);
                //add(int index,E item) is called

        }
        public T pop()throws Exception
        {
                if(top==0)
                {
                        throw new Exception("The stack is empty");
                }
                return container.remove(--top);
        }
        public boolean empty()
        {
                return (top==0);
        }
}
public class GenericTypeExample
{
        public static void main(String args[])throws Exception	
        {        
		try
                {
                        GenericStack<Integer> container=new GenericStack<>();
                        container.push(10);
                        System.out.println("10 is being pushed in stack");
                        container.push(20);
                        System.out.println("20 is being pushed in stack");
                        container.push(30);
                        System.out.println("30 is being pushed in stack");
                        System.out.println("the element is popped: "+container.pop());
                        System.out.println("the element is popped: "+container.pop());
                        System.out.println("the element is popped: "+container.pop());
                        System.out.println("the element is popped: "+container.pop());
                }
                catch(Exception e)
                {
                        System.out.println("The exception thrown: "+e);
                }
        }
}
