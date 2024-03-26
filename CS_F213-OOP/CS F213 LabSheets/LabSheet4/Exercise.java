class Shape {
    public void computeArea(){
        System.out.println("Area of Shape");
    }
}

class Triangle extends Shape {
    int length = 3;
    int height = 4;

    public void computeArea(){
        System.out.println((length * height)/2);
    }
}

class Square extends Shape {
    int side = 2;

    public void computeArea(){
        System.out.println(side * side);
    }
}

public class Exercise {
    public static void main(String[] args){
        Shape s = new Shape();
        s.computeArea();

        Shape t = new Triangle();
        t.computeArea();

        Shape sq = new Square();
        sq.computeArea();
    }
}
