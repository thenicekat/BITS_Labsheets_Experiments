import java.io.IOException;
import java.io.InputStreamReader;

public class PP12 {
    public static void main(String[] args) {
        InputStreamReader isr = new InputStreamReader(System.in);
        try {
            int c;
            while ((c = isr.read()) != -1) {
                System.out.print((char) c);
            }
        } catch (IOException e) {
        }
    }
}