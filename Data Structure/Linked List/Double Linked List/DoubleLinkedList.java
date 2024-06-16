class Node{
    String data;
    Node next;
    Node prev;

    public Node(String data){
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}
    

public class DoubleLinkedList {
    static Node head;


    public static Boolean search(String target){
        Node temp = head;

        while(temp!=null){
            if(temp.data == target){
                return true;
            }
            temp = temp.next;
        }
        return false;
    }
    
    public static void traverse(){
        Node temp = head;
        Node temp2 = temp;
        System.out.print("Forward: ");
        while(temp!=null){
            System.out.printf("%d ",temp.data);
            temp2 = temp;
            temp = temp.next;
        }

        System.out.print("Reverse: ");
        while(temp2!=null){
            System.out.printf("%d ",temp2.data);
            temp2 = temp2.prev;
        }
    }
    
    public static int length (){
        int length = 0;
        Node temp = head;
        while (temp!=null)
        {
            length+=1;
            temp=temp.next;
        }
        return length;
    }
    
    public static void insertionAtBeginning(String data){
        Node temp = new Node(data);
        temp.next = head;
        if (head != null){
            head.prev = temp;
        }
        head = temp;
    }
    
    public static void insertionAtEnd(String data){
        Node temp = new Node(data);
        Node head_temp = head;
        if (head == null){
            head = temp;
        }
        else{
            while(head_temp.next != null){
                head_temp = head_temp.next;
            }
            head_temp.next = temp;
        }
    }
    
    public static void insertionAtPosition(int position, String data){
        Node temp = new Node(data);
        Node headTemp = head;
        if(position == 0 || headTemp == null){
            temp.next = headTemp;
            headTemp = temp;
            return;
        }
    
        for(int i = 0; i < position && headTemp.next != null; i++){
            headTemp = headTemp.next;
        }
        temp.next = headTemp.next;
        headTemp.next = temp;
    }
    
    public static void deletionAtBeginning(){
        if(head == null){
            System.out.println("No node");
            return;
        }
        head = (head).next;
    }
    
    public static void deletionAtEnd(){
        if(head == null){
            System.out.println("No node");
            return;
        }

        if((head).next == null){
            head = null;
            return;
        }
    
        Node temp = head;
    
        while(temp.next.next != null){
            temp = temp.next;
        }
    
        temp.next = null;
    }
    
    public static void deletionAtPosition(int position){
        if(head == null){
            System.out.println("No node");
            return;
        }
    
        if(position==0){
            head = head.next;
            return;
        }
    
        Node  temp = head;
    
        for(int i = 1; i<position && temp.next != null; i++){
            temp = temp.next;
        }
    
        if(temp.next != null){
            temp.next = temp.next.next;
        }
        else{
            System.out.println("No node");
            return;
        }
    }


    public static void main(String [] args){
        insertionAtEnd("B");
        insertionAtEnd("C");
        insertionAtEnd("D");
        traverse();
        System.out.println(search("D"));
        System.out.printf("Length %d\n", length());
        insertionAtBeginning("A");
        insertionAtEnd("F");
        insertionAtPosition( 3, "E");
        deletionAtBeginning();
        deletionAtEnd();
        deletionAtPosition(1);
        traverse();
    }
}

