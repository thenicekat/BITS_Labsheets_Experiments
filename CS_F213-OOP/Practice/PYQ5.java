// class X {

//     // int procA() {
//     //     try {
//     //         return 5;
//     //     } 
//     //     // finally {
//     //     //     return 7;
//     //     //     // throw new ArithmeticException();
//     //     // }
//     // }
// }

// class Y extends X {
//     int procA() {
//         int a = 0;
//         try {
//             a = super.procA();
//             a = a + 1;
//             throw new NullPointerException();
//         } catch (ArithmeticException e) {
//             return a + 1;
//         } catch (NullPointerException e) {
//             return a + 5;
//         }
//     }
// }

// class PYQ5 {
//     public static void main(String args[]) {
//         Y ob = new Y();
//         int a = 0;
//         try {
//             a = ob.procA();
//         } catch (ArithmeticException e) {
//             a = a + 10;
//         } catch (NullPointerException e) {
//             a = a + 20;
//         } finally {
//             System.out.println("a = " + a); // Line 10
//         }
//     }
// }
