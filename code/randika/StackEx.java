/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package datastructures;

import java.util.Scanner;

/**
 *
 * @author Randika
 */
public class StackEx {
    
    int top;//initialize the top value of stack
    int MAX=100;//max 
    int array[]=new int[MAX];   
    
    public static void main(String args[])
    {
        StackEx input=new StackEx();
        input.push(10);
        input.push(20);
        input.push(30);
        input.push(20);
        System.out.println(input.pop()+"popped from stack");//pop karnwa LIFO anuwa
    }
    boolean isEmpty()
    {
        return (top<0);    
    }
    public StackEx() {
        top=-1;
    }
    boolean push(int x)
    {
        if(top>=(MAX-1))
        {
            System.out.println("Stack overflow");
            return false;
        }
        else{
            array[++top]=x;
            System.out.println(x+"pushed to the stack");
        }
        return true;      
    }
    int pop()
    {
        if(top<0)
        {
            System.out.println("Stack underflow");
            return 0;
        }
        else{
            int x=array[top--];
            return x;
        }
        
        
    }
    
}
