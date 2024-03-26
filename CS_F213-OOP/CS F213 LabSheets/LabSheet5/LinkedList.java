class Node{
    int value;
    Node next = null;

    Node(int x){
        value = x;
    }
}

class LinkedListImplementation {
    Node head;

    LinkedListImplementation(int initial){
        head = new Node(initial);
    }

    void addToEnd(int t){
        
    }

    void printLL(){
        Node temp = head;
        while(temp != null){
            System.out.println(temp.value);
            temp = temp.next;
        }
    }
}

public class LinkedList {
    public static void main(String args[]){
        LinkedListImplementation linkedListImplementation = new LinkedListImplementation(0);
        linkedListImplementation.printLL();
    }
    
}
