import java.util.StringTokenizer;

public class StringTokenization {
    public static void main(String[] args) {
        String name = "Divyateja Pasupuleti";
        StringTokenizer st = new StringTokenizer(name, " ", false);
        System.out.println("Number of tokens: " + st.countTokens());
        while(st.hasMoreTokens()){
            System.out.println(st.nextToken());
        }
    }
}
