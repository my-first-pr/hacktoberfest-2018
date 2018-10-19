public class StarArt {

    public static void StarBox(int rows, int columns){

        for(int i = 0; i < rows; i++){

            for(int j = 0; j < columns; j++){
                System.out.print("*");
            }

            System.out.println();

        }

    }

    public static void StarTriangle(int base){

        for(int i = 1; i <= base; i++){

            for(int j = 1; j <= i; j++){
                System.out.print("*");

            }

            System.out.println();

        }

    }

    public static void StarPyramid(int n){

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= i; j++){
                System.out.print("*");
            }
            System.out.println();
        }

        for(int i = 1; i < n; i++){
            for(int j = i; j < n; j++){
                System.out.print("*");
            }
            System.out.println();
        }

    }

}
