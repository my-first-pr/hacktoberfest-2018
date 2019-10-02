
import java.util.Scanner;

public class fibo {

    // An optimized version of Fibonacci
    public static int fib(int n) {
        int a = 0;
        int b = 1;
        int c = 0;
        for (int i = 0; i < n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        System.out.println("fib(" + a + ") = " + fib(a));
    }

}
