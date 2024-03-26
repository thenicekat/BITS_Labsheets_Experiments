import java.io.*;
import java.util.*;

class Employee implements Serializable {
    private int id;
    private String name;
    private float sal;
    private Date obj;

    Employee(int i, String n, float s, Date d) {
        id = i;
        name = n;
        sal = s;
        obj = d;
    }

    void display() {
        System.out.println(id + "\t" + name + "\t" + sal + "\t" + obj);
    }
}

public class Serialization {
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            FileOutputStream fos = new FileOutputStream("objfile");
            ObjectOutputStream oos = new ObjectOutputStream(fos);

            System.out.println("How many objects do you want to store?");
            int n = Integer.parseInt(br.readLine());

            while (n > 0) {
                System.out.println("Enter Employee ID");
                int id = Integer.parseInt(br.readLine());

                System.out.println("Enter Employee Name");
                String name = (br.readLine());

                System.out.println("Enter Salary");
                Float f = Float.parseFloat(br.readLine());

                Date d = new Date();
                Employee employee = new Employee(id, name, id, d);

                oos.writeObject(employee);

                n--;
            }
            oos.close();
        } catch (Exception e) {
        }

        try {
            FileInputStream fis = new FileInputStream("objfile");
            try {
                ObjectInputStream ois = new ObjectInputStream(fis);

                Employee e;
                while ((e = (Employee) ois.readObject()) != null) {
                    e.display();
                }
                ois.close();
            } catch (ClassNotFoundException e) {

            } catch (IOException e) {

            }
        } catch (FileNotFoundException e) {
            System.out.println("File Not Found");
        }
    }
}
