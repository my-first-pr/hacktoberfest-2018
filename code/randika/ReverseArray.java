package datastructures;



/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Randika
 */

import java.util.*; 

public class ReverseArray {
    
    public static void main(String[] args) {
        System.out.println("Enter string to reverse:");
		
		Scanner read = new Scanner(System.in);
		String str = read.nextLine();
		
		StringBuilder sb = new StringBuilder(str);
		
		System.out.println("Reversed string is:");
		System.out.println(sb.reverse().toString());
    }
}

