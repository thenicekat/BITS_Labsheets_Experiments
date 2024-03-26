import java.util.*;

public class ArrayListDemo1{
	public static void main(String args[]){
		ArrayList ar = new ArrayList();
		ar.add("Java");
		ar.add("Ok");
		ar.add(new Integer(7));
		ar.add(38);
		System.out.println(ar);
		ar.add(2, 50);
		System.out.println(ar);
		
		ArrayList<Integer> ar1 = new ArrayList<Integer>();
		ar1.add(38);
		ar1.add(30);
		System.out.println(ar1);
		ar1.add(1, 50);
		System.out.println(ar1);
	}
}
