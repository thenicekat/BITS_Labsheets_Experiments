class Box
{
 int length, width, height;

 Box(){
    this.length = 10;
    this.width = 5;
    this.height = 2;
 }

 Box(int length, int width, int height){
    this.length = length;
    this.width = width;
    this.height = height;
 }

 void setDimensions(int length, int width, int height){
    this.length = length;
    this.width = width;
    this.height = height;
 }

 void printBoxDetails()
 { 
    System.out.println("Box length is : " + length);
    System.out.println("Box width is : " + width);
    System.out.println("Box height is : " + height);
 }

 int getVolume(){
    return this.length*this.height*this.width;
 }
}

public class Question3 {
    public static void main(String args[]){
        Box b = new Box(); // using default constructor
        b.printBoxDetails();

        Box b2 = new Box(1,2,3);
        b2.printBoxDetails();
        System.out.println(b2.getVolume());
    }
}
