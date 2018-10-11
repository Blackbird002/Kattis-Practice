/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.github.blackbird002.assignment1;
import java.util.Scanner;

/**
 *
 * @author riads
 */
public class Egypt {
    public static void main(String args[]){

        String inputStr = "";
        int[] threeInts;
        boolean result;

        Scanner sc = new Scanner(System.in);
        while(sc.hasNextLine()){
            result = false;
            inputStr = sc.nextLine();
            threeInts = splitString(inputStr);

            //Exits the program is 0 0 0 is entered
            if(threeInts[0] == 0 || threeInts[1] == 0 || threeInts[2] == 0)
                break;
            
            EgyptSolver solver = new EgyptSolver(threeInts);

            result = solver.isRight();

            if(result == true)
                System.out.println("right");
            else
                System.out.println("wrong");
        }                        
    }
    
    public static int[] splitString(String inputStr){
        String[] threeNums = {"0","0","0"};
        int[] threeInts = {0,0,0}; 

        threeNums = inputStr.split(" ");

        //Try to convert a string to an int
        try{
            for(int i = 0; i <= 2; i++){
                //Type cast the string to an int
                threeInts[i] = Integer.valueOf(threeNums[i]);
            }
        }catch(IllegalArgumentException illegalArgument){
            /*Since this program is for Kattis, it's better to return an
            array with 0s so execution and continue
            */
            threeInts = new int[] {0,0,0}; 
            return threeInts;
        }catch(ArrayIndexOutOfBoundsException outOfBounds){
             /*Since this program is for Kattis, it's better to return an
            array with 0s so execution and continue
            */
            threeInts = new int[] {0,0,0}; 
            return threeInts;
        }
        return threeInts;     
    }
}

class EgyptSolver{
    private int a;
    private int b;
    private int c;
    public int sides[];

    public EgyptSolver(int[] threeSides){       
       
        sides = threeSides;
        bubbleSort();
        a = threeSides[0];
        b = threeSides[1];
        c = threeSides[2];     
         
    }

    public void bubbleSort(){
        for (int i = 0; i < sides.length-1; i++){
            for(int j = 0; j < sides.length-1; j++){
                if(sides[j] > sides[j+1]){
                    int temp = sides[j];
                    sides[j] = sides[j+1]; 
                    sides[j+1] = temp;
                }
            }
        }
    }

    public boolean isRight(){
        boolean test = false;
        a = a * a;
        b = b * b;
        c = c * c;

        if((a + b) == c){
            test = true;
        }
        return test;
    }
}


