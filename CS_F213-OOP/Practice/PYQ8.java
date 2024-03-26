import java.io.File;

public class PYQ8 {
    public static void main(String[] args) {
        if(args.length <= 0){
            System.out.println("Give Location of the file as an argument");
        }else{
            File f1;
            f1 = new File(args[0]);
            System.out.println(f1.getParent());
            System.out.println(f1.lastModified());
            for(String x: f1.list()){
                File innerFile = new File(f1, x);
                System.out.println("File Name: " + x + " | Directory/Not: " + innerFile.isDirectory());
            }
        }
    }
}
