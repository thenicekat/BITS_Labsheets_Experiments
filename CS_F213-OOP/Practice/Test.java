class Test2 {   
    static {
        System.out.println("Not Constructor");
    }

    Test2(){
        System.out.println("Constructor");
    }
}

public class Test extends Test2 {
    Test() {
        super();
    }

    static {
        System.out.println("Not Constructor 2");

    }

    public static void main(String[] args) {
        Test2 t = new Test();
    }
}