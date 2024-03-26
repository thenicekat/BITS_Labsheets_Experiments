package LabSheet2;

import java.util.Scanner;

public class Question1 {
    public static void recursiveCompute(){
        System.out.println("Enter 1 for Circle, 2 for Rectangle, 3 for Square: ");
        Scanner scan = new Scanner(System.in);
        int numb = scan.nextInt();
        double perimeter;

        switch(numb){
            case 1:
            System.out.println("Enter radius: ");
            int radius = scan.nextInt();
            perimeter = 2*3.1415926*radius;
            System.out.println("Perimeter of the Circle is: " + perimeter);
            recursiveCompute();
            break;

            case 2:
            System.out.println("Enter length: ");
            int length = scan.nextInt();
            System.out.println("Enter breadth: ");
            int breadth = scan.nextInt();
            perimeter = 2*(length + breadth);
            System.out.println("Perimeter of the Rectangle is: " + perimeter);
            recursiveCompute();
            break;

            case 3:
            System.out.println("Enter side: ");
            int side = scan.nextInt();
            perimeter = 4*side;
            System.out.println("Perimeter of the Square is: " + perimeter);
            recursiveCompute();
            break;

            default:
            break;
        }
        scan.close();
    }

    public static void main(String[] args){
        recursiveCompute();
    }
}
