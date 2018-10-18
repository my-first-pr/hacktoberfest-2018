/*
* Author: Cameron Brill
* Function: Calculates factorial of an inputted integer
* Date: 10-17-2018
*/
import java.util.Scanner;

public class HelloWorld
{
    public static void main(String[] args)
    {
        Scanner s = new Scanner(System.in);
        System.out.print("Input an integer you would like to find the factorial of: ");
        int factor = s.nextInt();
        System.out.println("The factorial of "+factor+" is "+factorial(factor));
    }
    public static long factorial(int x)
    {
        return x == 1 ? 1 : factorial(x-1)*x;
    }
}
