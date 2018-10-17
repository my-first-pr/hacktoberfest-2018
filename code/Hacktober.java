package com.timbuchalka;

public class Hacktober {

    public static void setYourMessage(String myAwesomeMessage){
        System.out.println("-----------------------------"+myAwesomeMessage+"----------------------------");
    }
    public static void main(String[] args) {
        String myAwesomeMessage = " YAY! We love Open Source!!!";

        for(int i=0;i<myAwesomeMessage.length();i++){
            System.out.print(" * ");
            if(i==myAwesomeMessage.length()-1)
                System.out.println("");
        }

        setYourMessage(myAwesomeMessage);

    }
}
