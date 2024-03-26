import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class CommandException extends RuntimeException {
    public String toString() {
        return "Command Exception";
    }
}

public class PYQ13 {
    public static void main(String[] args) {
        try {
            System.out.println("Enter threshold: ");
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            int x = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(args[0], " ", false);
            if(st.countTokens() == x){
                while(st.hasMoreTokens()){
                    System.out.println(st.nextToken());
                    System.out.println(st.nextElement());
                }
            }else{
                throw new CommandException();
            }
        } catch (IOException e) {

        }
    }
}
