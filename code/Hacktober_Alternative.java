
public class Hacktober {

    public static void setYourMessage(String myAwesomeMessage){
        System.out.println("-----------------------------"+myAwesomeMessage+"----------------------------");
    }
    public static void main(String[] args) {
        String myAwesomeMessage = "Hacktoberfest is even as awesome as Oktoberfest, well just without beer :)";

        for(int i=0;i<3;i++){
            System.out.print(" * ");
            if(i==myAwesomeMessage.length()-1)
                System.out.println("");
        }

        setYourMessage(myAwesomeMessage);
		
		for(int i=0;i<3;i++){
            System.out.print(" * ");
            if(i==myAwesomeMessage.length()-1)
                System.out.println("");
        }
    }
}