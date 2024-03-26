class Base {
    
    public void methodOne(){
        System.out.println("M1 Base");
        System.out.println("A");
        this.methodTwo();
    }
    
    public void methodTwo(){
        System.out.println("M2 Base");
        System.out.println("B");
    }
}

class Derived extends Base {
    public void methodOne(){
        System.out.println("M1 Derived");
        super.methodOne();
        System.out.println("C");
    }

    public void methodTwo(){
        System.out.println("M2 Derived");
        super.methodTwo();
        System.out.println("D");
    }

}

public class PYQ4
{
	public static void main(String[] args) {
		Base b = new Derived();
		b.methodOne();
	}
}

z