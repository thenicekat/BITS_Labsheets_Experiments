class Demo {
    static {
        System.out.println("hello");
    }
}

class Test{
    final static int i=2;
    public static void main(String[] args){
        switch(i){
            case i: System.out.println("1");
            case i+1: System.out.println("1");
            case i+2: System.out.println("1");
        }
    }
}