import java.util.Arrays; 
class twoD
{
    public static void main(String args[])
    {
        int[][] ar={{1,5},{2,88},{43,22}};
        int arr[]=new int[6];
        int a=0;
        System.out.println("Old array");
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<2;j++)
            System.out.print(ar[i][j]);
            System.out.println();
        }
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<2;j++)
            {arr[a]=ar[i][j];
            a++;}
        }
        Arrays.sort(arr);
        a=0;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<2;j++){
            ar[i][j]=arr[a];
            a++;}
            
        }
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<2;j++)
            System.out.print(ar[i][j]);
            System.out.println();
        }
    }
}
