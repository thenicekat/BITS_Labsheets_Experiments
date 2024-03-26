import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class PP3 {
    public static void main(String[] args) {
        try {
            FileReader fr = new FileReader("input.txt");
            BufferedReader br = new BufferedReader(fr);

            String temp;
            try {
                while ((temp = br.readLine()) != null) {
                    System.out.println(temp);
                }
            } catch (IOException e) {
            }
        } catch (FileNotFoundException e) {

        }
    }
}
