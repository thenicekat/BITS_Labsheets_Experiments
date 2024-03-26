import java.util.regex.*;

public class Regex {
    public static void main( String args[] ) {
        System.out.println(Pattern.matches("(\\w[^0-9])\\1", "aaba")); 
        System.out.println(Pattern.matches("(\\w[^0-9])\\1", "aaaa")); 
        System.out.println(Pattern.matches("((\\w\\d)[^a-b])\\1\\2", "a2ca2c")); 
        System.out.println(Pattern.matches("((\\w\\d)[a-b])\\1\\2", "a2ca2c")); 

        Pattern pattern = Pattern.compile("(\\d?)");
        Matcher m = pattern.matcher("hello welcome to 2021. Year 2020 is full of problems");
        while (m.find()){
            System.out.println("Extracted pattern "+ m.group());
        }
}}
