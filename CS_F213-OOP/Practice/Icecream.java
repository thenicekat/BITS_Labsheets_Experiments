import java.io.*;
class MyException extends Exception{
	String message;
	MyException(String text){
		message = text;
	}
	
	public String toString(){
		return "fuck you" + message;
	}
}

class ThreadIce implements Runnable{
	File f1;

	ThreadIce(){
		new Thread(this, "Icecream Thread").start();
	}

	public void run(){
		try{
			f1 = new File("chuin.txt");
			BufferedWriter bw = new BufferedWriter(new FileWriter(f1));
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            String temp = br.readLine();
            while(temp != null){
                System.out.println("::>" + temp);
                bw.write(temp);
                bw.flush();
                temp = br.readLine();
            }

			bw.write("Hello World");
			
            bw.close();
		}
		catch(IOException e){
            System.out.println("Error");
        }
	}

	public void randomlyThrowException() throws MyException{
		throw new MyException(" life");
	}
}



public class Icecream{
	public static void main(String args[]){
		ThreadIce ti = new ThreadIce();
		ThreadIce ti2 = new ThreadIce();
	}
}