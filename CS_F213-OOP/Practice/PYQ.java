public class PYQ {
    public static void main(String args[]){
        for(int i=0; i<args.length; i++){
            for(int j=0; j<args[i].length(); j+=2){
                System.out.println(args[i].charAt(j));
            }
        }
    }
}

// public class PYQ {
//     public static void main(String args[]) {
//         int arr[] = { 0x324, 0x456, 0x213, 0x78 };
//         int sum = 0;
//         for (int i = 0; i < 4; i++)
//             sum += arr[i] + 1;
//         System.out.println(sum);
//         byte b = (byte) (256*3 + 128);
//         System.out.println(b); // Line 1
//     }
// }

// class Overload{

// int meth(int x, int y) {
// return x + y;
// }

// float meth(int x, int y, int z) {
// return x + y + z;
// }

// boolean meth(float x, float y) {
// if (x + y > 10)
// return true;
// return false;
// }

// String meth(int x, float y, double z) {
// return x + y > z ? "Good" : "Bad";
// }
// }

// class PYQ {
// public static void main(String args[]) {
// Overload ob = new Overload();
// System.out.println(ob.meth(5, 6)); // Line 4
// System.out.println(ob.meth(10, 11, 12.5)); // Line 5
// System.out.println(ob.meth(3.5f, 7.8f)); // Line 6
// System.out.println(ob.meth(3, 4, 5)); // Line 7
// }
// }

// class XYZ {
// protected int x;
// }

// class ABC extends XYZ {
// void proc() {
// System.out.println(x);
// }
// }

// class PYQ {
// public static void main(String args[]) {
// ABC ob = new ABC();
// ob.proc(); // Line 8
// }
// }
