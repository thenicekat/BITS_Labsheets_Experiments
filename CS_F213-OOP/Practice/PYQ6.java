class A {
    public static void fuckYou(int y){
        System.out.println("y");
    }
}

public class PYQ6 extends A{
    public static void fuckYou(int y){
        System.out.println("x");
    }

    static {
        System.out.println((byte) 30);
    }

    {
        System.out.println("block");
    }

    public static void main(String[] args) {
        PYQ6 p = new PYQ6();
        PYQ6 p2 = new PYQ6();
    }
}
