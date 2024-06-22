
class Node{
    char data;
    Node next = null;
    
    Node(char data){
        this.data = data;
    }
}

public class CircularLinkedList {
    static Node cll = new Node('D');

    static void traverse(){
        System.out.printf("tail= %c", cll.data);
        System.out.print("traverse= ");
        Node head =  cll.next;
        if(cll.next != null){
            do{
                System.out.printf("%c ",head.data);
                head = head.next;
            }while(head != cll.next);
        }
        else{
            System.out.print(cll.data);
        }
    }

    static void insertAtBegining(char data){
        Node temp = new Node(data);
        if(cll!=null){
            if((cll).next!=null){
                temp.next = (cll).next;
            }
            else{
                temp.next = cll;
            }
            (cll).next = temp;
        }
        else{
            cll = temp;
        }
    }

    static void insertAtEnd(char data){
        Node temp = new Node(data);
        if(cll != null){
            temp.next = (cll).next;
            (cll).next = temp;
            cll = temp;
        }
        else{
            cll = temp;
        }
    }

    static void insertAtPosition(int position, char data){
        Node temp = new Node(data);
        if(cll != null){
            Node positionPointer = cll.next;
            for(int i = 1; i<position && positionPointer != null && positionPointer.next!=null; i++){
                positionPointer = positionPointer.next;
            }
            temp.next = positionPointer.next;
            positionPointer.next = temp;
            if(positionPointer == cll){
                cll = temp;
            }
        }
        else{
            cll = temp;
        }
    }

    static void deleteAtBeginning(){
        if((cll) == null){
            System.out.println("No Node");
            return;
        }
        if((cll).next == null){
            cll = null;
            return;
        }
        if((cll).next.next == null){
            (cll).next = null;
            return;
        }
        (cll).next = (cll).next.next;
        return;
    }

    static void deleteAtEnd(){
        Node temp = cll;
        while(temp!=null && temp.next!=null && temp.next!=cll){
            temp = temp.next;
        }
        if(temp==null||temp.next==null){
            cll = null;
            return;
        }
        temp.next = (cll).next;
        cll = temp; 
    }

    static void deleteAtPosition(int position){
        Node temp = (cll).next;
        for(int i = 1; i<position && temp!=null && temp.next!=null && temp.next!=cll; i++){        
            temp = temp.next;
        }
        if(temp==null||temp.next==null){
            cll = null;
            return;
        }
        if(temp.next == cll){
            temp.next = temp.next.next;
            (cll) = temp;
            return;
        }
        temp.next = temp.next.next;
        
    }

    public static void main(String [] args){
        traverse();
        insertAtBegining('C');
        insertAtBegining('B');
        insertAtBegining('A');
        insertAtEnd('F');
        insertAtPosition(4, 'E');
        insertAtPosition(6, 'G');
        traverse();
        deleteAtBeginning();
        deleteAtEnd();
        traverse();
        deleteAtPosition(3);
        traverse();
    }
}
