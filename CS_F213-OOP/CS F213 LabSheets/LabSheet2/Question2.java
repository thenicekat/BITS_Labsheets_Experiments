package LabSheet2;

public class Question2 {
    public static void main(String[] args){
        System.out.println("Float to Integer");
        int x = (int) 3.1415926;
        System.out.println(x);

        System.out.println("Integer to Float");
        float y = (float) 3;
        System.out.println(y);

        System.out.println("Boolean to Integer");
        x =  Integer.parseInt(Boolean.toString(true));
        System.out.println(x);
    }
}
