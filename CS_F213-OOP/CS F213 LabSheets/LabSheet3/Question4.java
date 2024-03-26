package LabSheet3;

import java.util.Scanner;

public class Question4 {
    public static void main(String args[]){
        int arr[][] = {
            {101, 103, 105, 106, 109},
            {67, 70, 43, 89, 56}
        };

        Scanner scan = new Scanner(System.in);
        System.out.println("Enter any ID: ");
        int id = scan.nextInt();
        scan.close();

        if(id == -999){
            return;
        }
        
        int i;
        
        for(i=0; i < arr[0].length; i++){
            if(arr[0][i] == id){
                System.out.println("The marks of the student with ID " + id + " is " + arr[1][i]);
                break;
            }
        }
        
    }
}
