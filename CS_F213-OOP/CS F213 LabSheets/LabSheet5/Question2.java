    class Stack {
        int length = 2;
        int array[] = new int[length];
        int curr = 0;

        void push(int x) {
            if (curr == length) {
                int[] tempArray = new int[length + 1];
                for (int i = 0; i < length; i++) {
                    tempArray[i] = array[i];
                }
                length += 1;
                tempArray[curr] = x;
                array = tempArray;
            } else
                array[curr] = x;
            curr++;
        }

        void printArray() {
            System.out.println("--------------");
            for (int i = 0; i < length; i++) {
                System.out.println(array[i]);
            }
            System.out.println("--------------");
        }

        void pop() {
            length--;
            int[] tempArray = new int[length];
            for (int i = 0; i < length; i++) {
                tempArray[i] = array[i];
            }
            array = tempArray;
        }
    }

    public class Question2 {
        public static void main(String args[]) {
            Stack s = new Stack();
            s.push(12);
            s.push(11);
            s.printArray();
            s.push(10);
            s.printArray();
            s.push(100);
            s.printArray();
            s.push(150);
            s.pop();
            s.pop();
            s.printArray();
        }
    }
