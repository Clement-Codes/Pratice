
import java.util.Queue;
import java.util.LinkedList;

class Node{
    int data;
    Node left;
    Node right;

    Node(int data1){
        data = data1;
        left = null;
        right = null;
    }
};

public class BinarySearchTree {
    public static Node head = new Node(50);

    public static Node insertion(Node  head, int data){
        if (head == null){
            return new Node(data);
        }
        else if (data <= head.data){
            head.left = insertion(head.left, data);
        }
        else {
            head.right = insertion(head.right, data);
        }
        return head;
    }

public static void preorder(Node head){
    if (head==null){
        return;
    }
    System.out.printf("%d,", head.data);
    preorder(head.left);
    preorder(head.right);
}

public static void inorder(Node head){
    if (head==null){
        return;
    }
    inorder(head.left);
    System.out.printf("%d,", head.data);
    inorder(head.right);
}

public static void postorder(Node head){
    if (head==null){
        return;
    }
    postorder(head.left);
    postorder(head.right);
    System.out.printf("%d,", head.data);
}

public static void levelorder(Node head){
    Queue<Node> q = new LinkedList<>();
    q.add(head);
    while(!q.isEmpty()){

        Node temp = q.peek();
        System.out.printf("%d,", temp.data);
        q.remove();

        if(temp.left != null){
            q.add(temp.left);
        }
        
        if(temp.right != null){
            q.add(temp.right);
        }

    }
}

    public static Node getMin(Node head){
        if(head.left != null){
            return getMin(head.left);
        }
        return head;
    }

    public static Node deletion(Node  head, int data){
        if (head == null){
            return head;
        }
        else if (data < head.data){
            head.left = deletion(head.left, data);
        }
        else if (data > head.data){
            head.right = deletion(head.right, data);
        }
        else{
            if(head.left == null){     
                Node temp = head.right;         
                return temp;
            }
            else if(head.right == null){              
                Node temp = head.left;         
                return temp;
            }
            else{
                Node temp = getMin(head.right);
                head.data = temp.data;
                head.right = deletion(head.right, temp.data);
            }
        }
        return head;
    }


public static void main(String args[]){
    
    head = insertion(head, 30);
    head = insertion(head, 20);
    head = insertion(head, 40);
    head = insertion(head, 70);
    head = insertion(head, 60);
    head = insertion(head, 80);

    System.out.printf("preorder: ");
    preorder(head);
    System.out.printf("\n");

    System.out.printf("inorder: ");
    inorder(head);
    System.out.printf("\n");

    System.out.printf("postorder: ");
    postorder(head);
    System.out.printf("\n");

    System.out.printf("levelorder: ");
    levelorder(head);
    System.out.printf("\n");

    deletion(head, 30);

    System.out.printf("levelorder: ");
    levelorder(head);
    System.out.printf("\n");

}

}
