public class Question12 {
    public static void main(String[] args){
        System.out.println("The number of arguments entered is: " + args.length);

        int answer = 0;

        for(int i = 0; i < args.length; i++){
            System.out.println(args[i]);
            answer += Integer.parseInt(args[i]);
        }

        System.out.println(answer);
    }
}
