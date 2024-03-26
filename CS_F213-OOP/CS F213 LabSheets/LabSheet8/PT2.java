import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class PT2 {
    public static void main(String[] args) {
        Pattern p = Pattern.compile("[1-7]\\d\\d\\d\\d\\d");
        Matcher m = p.matcher(args[0]);
        if(m.matches()){
            System.out.println(args[0] + " is a pincode");
        }else{
            System.out.println(args[0] + " is not a pincode");
        }
    }
}
