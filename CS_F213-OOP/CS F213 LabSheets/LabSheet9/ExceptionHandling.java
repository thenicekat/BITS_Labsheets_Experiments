class InvalidArgumentException extends Exception {
	int code;
	
	InvalidArgumentException(){
		code = 333;
	}
	
	public String toString(){
		return "Code: " + code + " Invalid Argument Exception";
	}
}


public class ExceptionHandling {
	public static void main(String args[]){
		int x = args.length;
		for(int i=0; i<x; i++){
			try{
				if(args[i].equals("NO")){
					throw new InvalidArgumentException();
				}else System.out.println("Argument: " + args[i] + " is valid");
			}catch (InvalidArgumentException e){
				System.out.println(e);
			}
		}
	}
}
