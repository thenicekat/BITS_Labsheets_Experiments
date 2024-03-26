// Q make an array of classes and find it's size

import java.util.*;

class Course {
    int cid;
    String cname;
    int credits;

    Course(int id, String name, int cred){
        cid = id;
        cname = name;
        credits = cred;
    }
}

public class PYQ14 {
    public static void main(String[] args) {
        long mem1, mem2;
        Runtime.getRuntime().gc();
        mem1 = Runtime.getRuntime().freeMemory();
        ArrayList<Course> std = new ArrayList<Course>();
        for(int i=0;i<100; i++){
            std.add(new Course(i, Integer.toString(i), i));
        }
        System.out.println(std.size());
        mem2 = Runtime.getRuntime().freeMemory();

        System.out.println("The size occupied is: " + Long.toString(mem1-mem2));

        Course c = new Course(200, "ben", 34);
        c = null;
        System.gc();
        
    }

    @Override
    protected void finalize(){
        System.out.println("End of Life");
    }
}
