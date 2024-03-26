public class PYQ2 {
    public static void main(String args[]){
        int x;
        try{
            x = Integer.parseInt(args[0]);
        } catch(Exception e){
            x = 5;
        }

        for(int i = 0; i<x; i++){
            System.out.print(args[1].charAt(i));
        }
    }
}
