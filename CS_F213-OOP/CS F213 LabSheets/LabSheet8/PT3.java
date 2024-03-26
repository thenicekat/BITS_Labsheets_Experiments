class Node {
    int val;
    Node next;
    Node prev;

    Node(int x) {
        val = x;
    }
}

class DoublyLinkedList {
    Node head;
    Node tail;

    DoublyLinkedList() {
    }

    DoublyLinkedList(int x) {
        head = new Node(x);
        head.prev = null;
        tail.next = null;
        tail = head;
    }

    void append(int val) {
        // Check if head is null, if yes
        // create a new node
        if (head == null) {
            head = new Node(val);
            tail = head;
            head.prev = null;
            tail.next = null;
        } else {
            // Create a new node
            Node temp = new Node(val);
            // point current tail's next to the new node
            tail.next = temp;
            // make the prev of temp the current tail
            temp.prev = tail;
            // change tail to the current one
            tail = temp;
            // make next null
            tail.next = null;
        }
    }

    void insert(int val, int pos){
        Node temp = head;
        for(int i = 0; i < pos - 1; i++){
            temp = temp.next;
        }
        Node newNode = new Node(val);
        newNode.next = temp.next;
        temp.next = newNode;
        newNode.prev = temp;
    }

    void printDLL() {
        Node currentNode = head;
        if (head == null) {
            System.out.println("Doubly Linked List is empty");
            return;
        }
        System.out.println("\nNodes in Doubly Linked List: ");
        while (currentNode != null) {
            System.out.print(currentNode.val + " ");
            currentNode = currentNode.next;
        }

    }
}

public class PT3 {
    public static void main(String[] args) {
        DoublyLinkedList dll = new DoublyLinkedList();
        dll.append(26);
        dll.append(40);
        dll.printDLL();
        dll.insert(76, 1);
        dll.printDLL();
    }
}
