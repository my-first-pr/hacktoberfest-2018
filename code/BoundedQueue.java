import java.util.concurrent.locks.*;

/** 
    A first-in, first-out bounded collection of objects. 
*/ 
public class BoundedQueue<E>
{ 
   /** 
       Constructs an empty queue. 
       @param capacity the maximum capacity of the queue 
   */ 
   public BoundedQueue(int capacity) 
   { 
      elements = new Object[capacity]; 
      head = 0; 
      tail = 0; 
      size = 0;
   } 

   /** 
       Removes the object at the head. 
       @return the object that has been removed from the queue
   */ 
   public E remove() throws InterruptedException
   { 
      queueLock.lock();
      try
      {         
         while (size == 0) 
            valueAvailableCondition.await();
         E r = (E) elements[head]; 
         head++;
         size--;
         if (head == elements.length) 
            head = 0; 
         spaceAvailableCondition.signalAll();
         return r; 
      }
      finally
      {
         queueLock.unlock();
      }
   } 
   public void add(E newValue) throws InterruptedException
   { 
      queueLock.lock();
      try
      {         
         while (size == elements.length) 
            spaceAvailableCondition.await();
         elements[tail] = newValue; 
         tail++;
         size++;
         if (tail == elements.length) 
            tail = 0; 
         valueAvailableCondition.signalAll();
      }
      finally
      {
         queueLock.unlock();
      }
   } 

   private Object[] elements; 
   private int head; 
   private int tail; 
   private int size;

   private Lock queueLock = new ReentrantLock();
   private Condition spaceAvailableCondition 
         = queueLock.newCondition();
   private Condition valueAvailableCondition 
         = queueLock.newCondition();
}
