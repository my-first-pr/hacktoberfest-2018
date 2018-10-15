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
public class ImpQueue {
    
    int maxSize;
    int Queue[];
    int front=0;
    int rear=-1;

    public ImpQueue() {
        maxSize=maxSize;
        Queue=new int[maxSize];
    }
        
    boolean isFull()
    {
        if(front==0 && rear>=(maxSize-1))
        {
            System.out.println("Queue is full");
            
        }
        return true;
    }
    boolean isEmpty()
    {
        if(front==0 && rear==-1)
        {
            System.out.println("Queue is empty"); 
        }
        return true;
    }
    public void enqueue(int x)
    {
        if(front==0 && rear>maxSize-1)
        {
            isFull();
        }
        else
        {
            rear=rear+1;
           Queue[rear]=x; 
            System.out.println("Enqueue element is "+Queue[rear]);
        }
    }
    public int dequeue()
    {
        if(front==0 && rear==-1)
        {
            isEmpty();
           return 0; 
        }
        else
        {
           front=front+1;
            System.out.println("Dequeue element is "+Queue[front-1]);
            return 0;
        }
        
    }
    public int front()
    {
        System.out.println("Front element of the queue is "+Queue[front]);
        return 0;
    }
    public int rear()
    {
        System.out.println("Rear element of the queue is "+Queue[rear]);
        return 0;
    }
    
    public static void main(String[] args) {
        
        ImpQueue in=new ImpQueue();
        in.enqueue(12);
        in.enqueue(23);
        in.enqueue(34);
        in.front();
        in.rear();
        in.dequeue();
        in.front();
    }
    
}
