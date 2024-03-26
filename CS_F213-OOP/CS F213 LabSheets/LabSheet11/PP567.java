import java.io.*;

public class PP567 {
    public static void main(String[] args) {
        File f1 = new File("G:\\My Drive\\Year 2 Sem 1\\CS F213 - Object Oriented Programming\\JavaDevelopment\\CS F213 LabSheets\\LabSheet11\\");
        System.out.println(f1.getName());
        System.out.println(f1.getAbsolutePath());
        System.out.println(f1.isDirectory());
        System.out.println(f1.lastModified());
        System.out.println(f1.length());

        System.out.println("\n");

        for(int i=0; i<f1.list().length; i++){
            File f2 = new File(f1, f1.list()[i]);
            System.out.println(f2.getName());
        }
    }
}
