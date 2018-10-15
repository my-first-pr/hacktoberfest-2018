/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package datastructures;

/**
 *
 * @author Randika
 */
//1.I
public class ImpStack {
    //1.II
    int maxSize;
    int array[];
    int top=-1;
    //1.III
    public ImpStack()
    {
       maxSize=1;
       int array[]=new int[maxSize];       
    }
    //1.IV to add value to the stack by using push operation 
    public void push(int x)
    {
        if(top==maxSize-1)
        {
            int array2[]=new int[array.length*2];
            for(int i=0; i<array.length; i++)
            {
               array2[i]=array[i];
            }
            maxSize=array2.length;
            array=array2;
        }
        else
        {
            array[++top]=x;
            
        }
        
    }
    //1.V to remove elements from stack
    public void pop()
    {
        if(top<0)
        {
            System.out.println("Stack Overflow");
            //return 0;
        }
        else
        {
           //return array[top--];
            top--;
        }
         
    }
    //1.VI
    public void peek()
    {
        if(top==-1)
        {
            System.out.println("empty stack");
        }
        else{
            System.out.println("Top Element of the Stack:"+array[top]);
        }
    }
    //1.VII
    public void display()
    {
        System.out.println("Elements of the Stack:");
        for(int i=0; i<top; i++)
        {
            System.out.print(array[i]+" "); 
        }
        System.out.println("");
    }
    public static void main(String[] args) {
        
       ImpStack newStack=new ImpStack();
       newStack.push(12);
       newStack.push(23);
       newStack.push(34);
       newStack.display();
       newStack.push(45);
       newStack.push(56);
       newStack.display();
       newStack.pop();
       newStack.display();
       newStack.peek();
    }
}
