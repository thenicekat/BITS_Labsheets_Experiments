import java.io.*;

class Box implements Serializable{
    private int length, breadth, height;

    Box(int l, int b, int h){
        length = l;
        breadth = b;
        height = h;
    }

    public void getVolume(){
        System.out.println("The volume is: " + length*breadth*height);
    }

}

public class Serialization2 {
    public static void main(String[] args) {
        try{
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            FileOutputStream fos = new FileOutputStream("box.txt");
            ObjectOutputStream oos = new ObjectOutputStream(fos);
            
            System.out.println("How many boxes do you want to store in the file: ");
            int x = Integer.parseInt(br.readLine());
            while(x > 0){
                System.out.println("Give the values for length, breadth and height in the same order: ");
                int l = Integer.parseInt(br.readLine());
                int b = Integer.parseInt(br.readLine());
                int h = Integer.parseInt(br.readLine());

                Box box = new Box(l, b, h);
                oos.writeObject(box);

                x--;
            }

            oos.close();
        }catch(FileNotFoundException e){

        }catch(IOException e){

        }

        try {
            FileInputStream fis = new FileInputStream("box.txt");
            ObjectInputStream ois = new ObjectInputStream(fis);

            try{
                Box b;
                b = (Box) ois.readObject();
                while(b != null){
                    b.getVolume();
                    b = (Box) ois.readObject();
                }
            }
            catch(ClassNotFoundException e){}
            catch(IOException e){}
        }
        catch(FileNotFoundException e){}
        catch(IOException e){}
    }
}
