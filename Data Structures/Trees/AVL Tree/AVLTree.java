
import java.util.Queue;
import java.util.LinkedList;

class Node{
    int data;
    Node left;
    Node right;
    int height;

    Node(int data1){
        data = data1;
        left = null;
        right = null;
        height = 1;
    }
};

public class AVLTree {
    public static Node head = new Node(13);


    public static int max(int a, int b){
        return (a>=b)?a:b;
    }

    public static int height(Node head){
        if(head == null){
            return 0;
        }
        return head.height;
    }

    public static int balance(Node head){
        return height(head.left) - height(head.right);
    }

    public static Node rightRotation(Node head){
        Node temp = head.left;
        head.left = temp.right;
        temp.right = head;
        temp.height = max(height(temp.left), height(temp.right)) + 1;
        head.height = max(height(head.left), height(head.right)) + 1;
        return temp;
    }

    public static Node leftRotation(Node head){
        Node temp = head.right;
        head.right = temp.left;
        temp.left = head;
        temp.height = max(height(temp.left), height(temp.right)) + 1;
        head.height = max(height(head.left), height(head.right)) + 1;
        return temp;
    }

    public static Node insertion(Node  head, int data){
        if (head == null){
            return new Node(data);
        }
        else if (data < head.data){
            head.left = insertion(head.left, data);
        }
        else if (data > head.data) {
            head.right = insertion(head.right, data);
        }
        else{
            return head;
        }
        head.height = max(height(head.left), height(head.right)) + 1;
        int bst = balance(head);
        if(bst > 1 && data < head.left.data){
            return rightRotation(head);
        }
        else if(bst < -1 && data > head.right.data){
            return leftRotation(head);
        }
        else if(bst > 1 && data > head.left.data){
            head.left = leftRotation(head.left);
            return rightRotation(head);
        }
        else if(bst < -1 && data < head.right.data){
            head.right = rightRotation(head.right);
            return leftRotation(head);
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
    
    head = insertion(head, 10);
    head = insertion(head, 15);
    head = insertion(head, 5);
    head = insertion(head, 11);
    head = insertion(head, 16);
    head = insertion(head, 4);
    head = insertion(head, 6);

    // System.out.printf("preorder: ");
    // preorder(head);
    // System.out.printf("\n");

    // System.out.printf("inorder: ");
    // inorder(head);
    // System.out.printf("\n");

    // System.out.printf("postorder: ");
    // postorder(head);
    // System.out.printf("\n");

    System.out.printf("levelorder: ");
    levelorder(head);
    System.out.printf("\n");

    head = insertion(head, 7);

    System.out.printf("levelorder: ");
    levelorder(head);
    System.out.printf("\n");

}

}
