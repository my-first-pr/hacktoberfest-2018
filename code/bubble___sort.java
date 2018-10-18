//BUBBLE SORT
import java.util.*;
class Bubble {
  public static void main(String[] args) {
  Scanner sc=new Scanner(System.in);
  int s=sc.nextInt();
  int[] arr=new int[s];
  for(int i=0;i<s;i++){
  arr[i]=sc.nextInt();
  }
  bubblesort(arr);
  for(int i=0;i<s;i++){
  System.out.println(arr[i]);
  }
  }
   public static void bubblesort(int[] numbers){
        for(int i=0; i< numbers.length-1; i++){
            for(int j=0;j<numbers.length-i-1;j++){
                if(numbers[j]>numbers[j+1]){
                   int temp=numbers[j];
                   numbers[j]=numbers[j+1];
                   numbers[j+1]=temp;
                }
            }
          }
       }
  }     
