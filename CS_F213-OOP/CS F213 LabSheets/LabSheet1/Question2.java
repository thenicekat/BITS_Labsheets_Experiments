package LabSheet1;
import java.util.Scanner;

public class Question2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int radius;
        double diameter, circumference, area;
        System.out.print("Radius: ");

        radius = sc.nextInt();
        diameter = radius * 2;
        circumference = radius*2*3.14;
        area = 3.14*radius*radius;

        System.out.println("Diameter: " + Double.toString(diameter));
        System.out.println("Circumference: " + Double.toString(circumference));
        System.out.println("Area: " + Double.toString(area));

        sc.close();
    }
}
