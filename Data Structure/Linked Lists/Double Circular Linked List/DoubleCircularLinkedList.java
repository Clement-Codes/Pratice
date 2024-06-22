class Node{
    char data;
    Node prev;
    Node next;

    Node(char data){
        this.data = data;
        this.prev = null;
        this.next = null;
    }
};

class DoubleCircularLinkedList{

    static Node DCLL = new Node('D');
    
    static void traverse(){
        Node temp = DCLL;
        Node temp2;
        System.out.println("Forward: ");
        do{
            temp2 = temp;
            System.out.printf("%c ",temp.data);
            temp = temp.next;
        }while (temp != null && temp!=DCLL);
        System.out.println("Backward: ");
        do{
            System.out.printf("%c ",temp2.data);
            temp2 = temp2.prev;
        }while (temp2 != null && temp2!=DCLL.prev);
    }
    
    static void insertAtBeginning(char data){
        Node temp = new Node(data);
        if(DCLL==null){
            (DCLL) = temp;
            return;
        }
        else{
            temp.next = (DCLL);
            (DCLL).prev = temp;
            Node temp2 = (DCLL);
            while(temp2.next != null && temp2.next != DCLL){
                temp2 = temp2.next;
            }
            temp2.next = temp;
            temp.prev = temp2;
            (DCLL) = temp;
            return;
        }
    }
    
    static void insertAtEnd(char data){
        Node temp = new Node(data);
        if(DCLL==null){
            (DCLL) = temp;
            return;
        }
        else{
            Node temp2 = (DCLL);
            while(temp2.next != null && temp2.next != DCLL){
                temp2 = temp2.next;
            }
            temp.next = temp2.next;
            temp2.next.prev=temp;
            temp2.next = temp;
            temp.prev = temp2;
            return;
        }
    }
    
    static void insertAtPosition(int position, char data){
        Node temp = new Node(data);
        if(DCLL==null){
            (DCLL) = temp;
            return;
        }
        else{
            Node temp2 = (DCLL);
            for(int i = 1; i<position && temp2.next != null && temp2.next != DCLL; i++){
                temp2 = temp2.next;
            }
            temp.next = temp2.next;
            temp2.next.prev=temp;
            temp2.next = temp;
            temp.prev = temp2;
            return;
        }
    }
    
    static void deleteAtBeginning(){
        if(DCLL == null){
            System.out.println("No Data");
        }
        else{
            Node temp = (DCLL).next;
            temp.prev = (DCLL).prev; 
            (DCLL).prev.next = temp;
            (DCLL) = temp;
        }
    }
    
    static void deleteAtEnd(){
        if(DCLL == null){
            System.out.println("No Data");
        }
        else{
            Node temp = (DCLL);
            while(temp.next != null && temp.next != (DCLL)){
                temp = temp.next;
            }
            temp.next.prev=temp.prev;
            temp.prev.next=temp.next;
        }
    }
    
    static void deleteAtPosition(int position){
        if(DCLL == null){
            System.out.println("No Data");
        }
        else{
            Node temp = (DCLL);
            for(int i = 0; i<position && temp.next != null && temp.next != (DCLL);i++){
                temp = temp.next;
            }
            temp.next.prev=temp.prev;
            temp.prev.next=temp.next;
        }
    }
    
    public static void main(String[] args){
        insertAtBeginning('C');
        insertAtBeginning('B');
        insertAtBeginning('A');
        insertAtEnd('G');
        insertAtPosition(4, 'E');
        insertAtPosition(5, 'F');
        traverse();
        deleteAtBeginning();
        deleteAtEnd();
        deleteAtPosition(3);
        traverse();
    }
    
}
