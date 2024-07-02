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

public class BinaryTree {
    public static Node head = new Node(1);

    public static void insertion(Node  head, int data){
    Node x = new Node(data);
    if(head == null){
        head = x;
        return;
    }
    Queue<Node> q = new LinkedList<>();
    q.add(head);
    while(!q.isEmpty()){
        Node temp = q.peek();
        q.remove();
        if(temp.left == null){
            temp.left = x;
            return;
        }
        else{
            q.add(temp.left);
        }
        if(temp.right == null){
            temp.right = x;
            return;
        }
        else{
            q.add(temp.right);
        }    
    }

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


public static void deletionDeep(Node  head, Node  x){
    Queue<Node> q = new LinkedList<>();
    q.add(head);
    while(!q.isEmpty()){
        Node temp = q.peek();
        q.remove();
        if(temp == x){
            temp = null;
            return;
        }
        if(temp.left == x){
            temp.left = null;
            return;
        }
        else{
            q.add(temp.left);
        }
        if(temp.right == x){
            temp.right = null;
            return;
        }
        else{
            q.add(temp.right);
        }    
    }

}

public static void deletion(Node  head, int data){
    Queue<Node> q = new LinkedList<>();
    q.add(head);
    Node temp = head;
    Node keyNode = null;
    while(!q.isEmpty()){
        temp = q.peek();
        q.remove();
        if(temp.data == data){
            keyNode = temp;
        }
        if(temp.left != null){
            q.add(temp.left);
        }
        if(temp.right != null){
            q.add(temp.right);
        }  
    }
    if(keyNode != null){
        int x = temp.data;
        keyNode.data = x;
        deletionDeep(head, temp);
    }
}


public static void main(String args[]){
    
    insertion(head, 2);
    insertion(head, 3);
    insertion(head, 4);
    insertion(head, 5);

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

    deletion(head, 3);

    System.out.printf("levelorder: ");
    levelorder(head);
    System.out.printf("\n");

}

}
