package LabSheet1;
import java.util.Scanner;

public class Question1{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int f, c;
        System.out.println("Enter temperature in Fahrenheit: ");
        f = sc.nextInt();
        c = (f-32)*5/9;
        System.out.println("The temperature in celsius: " + Integer.toString(c) + "'C");
        sc.close();
    }
}