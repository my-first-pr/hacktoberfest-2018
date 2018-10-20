using System;

namespace mdmcclean
{
    class mdmcclean
    {
        static int diagonalDifference(int[][] arr)
        {
            int leftToRightDiagonal = 0;
            int rightToLeftDiagonal = 0;
            Console.WriteLine("Left To Right");
            for (int i = 0; i < arr.GetLength(0); i++)
            {
                leftToRightDiagonal += arr[i][i];
                Console.WriteLine(leftToRightDiagonal);
            }
            Console.WriteLine("Right to Left");
            for (int i = 1; i < arr.GetLength(0) + 1; i++)
            {
                rightToLeftDiagonal += arr[i - 1][ arr.Length - i];
                Console.WriteLine(rightToLeftDiagonal);
            }
            int difference;
            if (leftToRightDiagonal >= rightToLeftDiagonal)
            {
                difference = leftToRightDiagonal - rightToLeftDiagonal;
            }
            else
            {
                difference = rightToLeftDiagonal - leftToRightDiagonal;
            }
            return difference;

        }
        static void Main(string[] args)
        {
            //finds the diagonal difference of a matrix
            // put your matrix in this matrix ... example
            int[][] mtx = { new int[] { 11, 4, 10 }, new int[] { 2, 5, 8 }, new int[] { 4, 6, -12 } };
           
            Console.WriteLine($"\nDiagonal difference: {diagonalDifference(mtx)}");
            Console.ReadKey();


        }
    }
}
