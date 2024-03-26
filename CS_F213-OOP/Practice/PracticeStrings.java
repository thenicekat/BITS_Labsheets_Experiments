import java.util.StringTokenizer;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class PracticeStrings {
    public static void main(String[] args) {
        // StringTokenizer st = new StringTokenizer("Bangalore is the capital city of Karnataka and Bombay is the capital city of Maharashtra", " ");
        // while(st.hasMoreTokens()){
        //     String x = st.nextToken();
        //     if(x.charAt(0) == 'B'){
        //         System.out.println(x);
        //     }
        // }

        String input = "\"123.45.67.89 - - [27/Oct/2000:09:27:09 -0400] \"GET /java/javaResources.html HTTP/1.0\" 200 10450 \"-\" \"Mozilla/4.6 [en] (X11; U; OpenBSD 2.8 i386; Nav)\"";
        System.out.println(input);
        //IP Address
        Pattern p = Pattern.compile("\\d\\d?\\d?\\.\\d\\d?\\d?\\.\\d\\d?\\d?\\.\\d\\d?\\d?");
        Matcher m = p.matcher(input);
        if(m.find()){
            System.out.println("IP Address: " + m.group());
        }

        //Date Time
        p = Pattern.compile("\\[.*?\\]");
        m = p.matcher(input);
        if(m.find()){
            System.out.println("Date Time: " + m.group());
        }

        //Request
        p = Pattern.compile(" \".*?\"");
        m = p.matcher(input);
        if(m.find()){
            System.out.println("Request: " + input.substring(m.start()+2, m.end()-1));
        }

        //Response
        p = Pattern.compile(" \\d\\d\\d ");
        m = p.matcher(input);
        if(m.find()){
            System.out.println("Response: " + input.substring(m.start()+1, m.end()-1));
        }

        p = Pattern.compile(" \\d\\d\\d\\d\\d ");
        m = p.matcher(input);
        if(m.find()){
            System.out.println("Bytes Sent: " + input.substring(m.start()+1, m.end()-1));
        }

        p = Pattern.compile(" \"-\" \".*?\"");
        m = p.matcher(input);
        if(m.find()){
            System.out.println("Browser: " + input.substring(m.start()+6, m.end()-1));
        }
    }
}
