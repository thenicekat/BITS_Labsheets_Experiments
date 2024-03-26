import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class PP4 {
    public static void main(String[] args) {
        try{
            FileReader fr = new FileReader("input.txt");
            BufferedReader br = new BufferedReader(fr);

            FileWriter fw = new FileWriter("output.txt");
            BufferedWriter bw = new BufferedWriter(fw);

            String x;
            while((x = br.readLine()) != null){
                bw.write(x);
                bw.newLine();
            }

            bw.close();
            br.close();
        } catch (IOException e){

        }
    }
}
