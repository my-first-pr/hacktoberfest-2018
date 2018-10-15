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
public class Queue {
    
    int front,rear,size;
    int capacity;
    int array[];
    
    public Queue(int capacity)
    {
        this.capacity=capacity;
        front=this.size=0;
        rear=capacity=1;
        array =new int[this.capacity];
    }//queue is full when size becomes equal to the capacity
    boolean isFull(Queue queue)
    {
        return (queue.size==queue.capacity);     
    }
    //queue is empty when size is 0
    boolean isEmpty(Queue queue)
    {
      return (queue.size==0);  
    }
    //method to add item, it changes rear and size
    public void enqueue(int item)
    {
        if(isFull(this))
            return;
        this.rear=(this.rear+1)%this.capacity;
        this.array[this.rear]=item;
        this.size=this.size+1;
        System.out.println(item+"enqueued to Queue");
    }
    //method to remove item from queue front size
    public int dequeue()
            {
               if(isEmpty(this))
                   return Integer.MIN_VALUE;
               int item=this.array[this.front];
               this.front=(this.front+1)%this.capacity;
               return item;
            }
    //method to get front of queue
    int front()
    {
        if(isEmpty(this))
        {
            return Integer.MIN_VALUE;
        }
        return this.array[this.front];        
    }
    //methos to get rear
    int rear()
    {
        if(isEmpty(this))
        {
            return Integer.MIN_VALUE;
        }
        return this.array[this.rear];     
    }
    public static void main(String[] args) {
        
       Queue input=new Queue(1000);
       input.enqueue(10);
       input.enqueue(20);
       input.enqueue(30);
       input.enqueue(40);
       
        System.out.println(input.dequeue()+"dequeue from Queue");
        System.out.println("Front item is"+input.front());
        System.out.println("Rear item is"+input.rear());
    }
    
    
}
