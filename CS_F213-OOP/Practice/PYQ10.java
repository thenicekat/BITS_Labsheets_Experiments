class A {
    int a;

    A(int x) {
        a = x;
        System.out.println("A's constructor: a = " + a);
        try {
            throw new ArithmeticException();
        } catch (ArithmeticException e) {
            System.out.println("Inside catch of A's constructor");
        }
    }
}

class B extends A {
    int b;

    B(int x, int y) {
        super(x);
        System.out.println("Exiting B's constructor");
        return;
    }
}

class DemoE {
    static {
        System.out.println("Static block"); // Line 16
        A ob1 = new A(1); // Line 17
        B ob2 = new B(2, 3); // Line 18
    }

    public static void main(String args[]){
    }
}