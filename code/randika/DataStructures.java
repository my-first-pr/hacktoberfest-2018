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
import java.util.*;
import java.util.stream.*;

public class DataStructures {

    private static int[] array2;

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        int total=0,avg,odd;
        
        Scanner input=new Scanner(System.in);
        
        System.out.println("Enter number of elements :");
        int numbers=input.nextInt();
        
        int array[]=new int[numbers];
        
        
        System.out.println("Enter elements :");
        for(int i=0; i<numbers; i++)
        {
          array[i]=input.nextInt();
             
          //total=+array[i];
        }
        
        System.out.println("Elemenets of array");
        for(int i:array )
        {
            System.out.println(i);
        }
        //Max Number
        int max = array[0];
        for(int i = 0; i < numbers; i++)
        {
            if(max < array[i])
            {
                max = array[i];
            }
        }
        System.out.println("Maximum value:"+max);
        //Min Number
        int min = array[0];
        for(int i = 0; i < numbers; i++)
        {
            if(min > array[i])
            {
                min = array[i];
            }
        }
        System.out.println("Minimum value:"+min);
        
        for(int i : array) 
        {
             total += i;
          }
        
        
        System.out.println("Total = "+total);
        
        for(int i=0;i<array.length;i++)
        {
           if(array[i]%2!=0)
           {
              System.out.println("ODD numbers are :");
              System.out.println(array[i]);
            }
        }
        
    }
}
