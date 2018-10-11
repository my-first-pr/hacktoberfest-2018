//BUBBLE SORT
import java.util.*;
class Solution {
  public static void main(String[] args) {
  Scanner scan=new Scanner(System.in);
  int n=scan.nextInt();
  int[] arr=new int[n];
  for(int i=0;i<n;i++){
  arr[i]=scan.nextInt();
  }
  bubblesort(arr);
  for(int i=0;i<n;i++){
  System.out.println(arr[i]);
  }
  }
   public static void bubblesort(int[] nums){
        for(int i=0; i< nums.length-1; i++){
            for(int j=0;j<nums.length-i-1;j++){
                if(nums[j]>nums[j+1]){
                   int temp=nums[j];
                   nums[j]=nums[j+1];
                   nums[j+1]=temp;
                }
            }
        }
    }
}    
