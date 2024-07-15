import java.util.Vector;
import java.util.Queue;
import java.util.LinkedList;

public class BTree  {
    public static void main(String[] args){
        BST bst = new BST(3);

        for(int i = 0; i<20; i++) bst.insertion(i);
    
        bst.levelOrder();

        for(int i = 0; i<20; i++) bst.deletion_pre(i);
    
        bst.levelOrder();
    }
};


 class Node{
    int n = 0;
    Vector<Integer> keys = new Vector<>() ;
    Vector<Node> childs = new Vector<>();
    boolean leaf;
    
    
    Node(boolean leaf){
        this.leaf = leaf;

    }
};

class BST{
    int t;
    Node root = new Node(true);


    BST(int t1){
        t = t1;
    }

    void insertion(int key){
        if (root.n == 0){
            root.keys.add(key);
            root.n += 1;
            return;
        }
        
        if (root.n == (2*t) -1){
                Node temp = new Node(false);
                temp.childs.add(root);
                root = temp;
                split(root, 0);
                insertion_null(root, key);
        }
        else{
            insertion_null(root, key);
        }


    }

    void insertion_null(Node node, int key){
        int i = 0;
        
        while(i < node.n && key>node.keys.elementAt(i) ){
            
            i += 1;
        }
        if(node.leaf){
            node.keys.add(0);
            for(int ii = node.n-1; ii>i; ii++){
                node.keys.set(ii,node.keys.get(i));
            }
            node.keys.set(i, key);
            node.n += 1;
        }
        else{
            if(node.childs.get(i).n == (2*t) -1){
                split(node, i);
                if(key > node.keys.get(i)){
                    i += 1;
                }
            }
            insertion_null(node.childs.get(i), key);
        }
    }

    void split(Node node, int i){
        Node temp = new Node(node.childs.get(i).leaf);
        for(int ii=t; ii< (2*t) -1; ++ii){
            temp.keys.add(node.childs.get(i).keys.get(ii));
        }
        
        for(int ii=t; ii< (2*t) -1; ++ii){
            node.childs.get(i).keys.removeLast();
        }                        

        node.keys.add(node.childs.get(i).keys.get(t-1));
        node.childs.get(i).keys.remove(t-1);

        if(! node.childs.get(i).leaf){
            for(int ii=t; ii< (2*t); ii++){
                temp.childs.add(node.childs.get(i).childs.get(ii));
            }

            for(int ii=t; ii< (2*t); ii++){
                node.childs.get(i).childs.removeLast();
            }
        }
        temp.n = ((2*t) -1 - t);
        node.childs.get(i).n = t - 1;
        node.n += 1;
        node.childs.add(temp);

    }

    void levelOrder(){
        if (root==null||root.n ==0){
            System.out.println("Empty");
            return;
        }
        Queue<Integer> level = new LinkedList<>();
        level.add(0);
        Queue<Node> q = new LinkedList<>();
        q.add(root);
        while(!q.isEmpty()){
            Node temp = q.peek();
            int l = level.peek();
            System.out.printf("Level %d: ", l);
            for(int i: temp.keys) System.out.printf("%d ", i);
            q.remove();
            level.remove();
            System.out.println();
            if (!temp.leaf){
                for(Node i: temp.childs){
                    q.add(i);
                    level.add(l+1);
                }
                
            }
            
        }
    }


    int getMinimum(Node node,int x){
        int i = 0;
        while(x > node.keys.get(i) && i<node.n){
            i += 1;
        }
        return i;
    }

    void deletion_pre(int x){
        if (root.n == 0||root == null){
            System.out.println("non");
        }
        deletion(root, x);      

        if(root.n==0){
            if(root.leaf){
                root = null;
            }
            else{
                root = root.childs.get(0);
            }
        }
    }


    int getPredecessor(Node node, int i){
        Node temp = node.childs.get(i);
        while(!temp.leaf){
            temp = temp.childs.get(temp.n);
        }
        return temp.keys.get(temp.n - 1);
    }
    
    int getSuccessor(Node node, int i){
        Node temp = node.childs.get(i+1);
        while(!temp.leaf){
            temp = temp.childs.get(0);
        }
        return temp.keys.get(0);
    }

    void merge(Node node, int i){
        

        Node child = node.childs.get(i);
        Node prev = node.childs.get(i + 1);
        

        child.keys.add(node.keys.get(i));

        node.keys.remove(i);
        for(int ii: prev.keys) child.keys.add(ii);
        for(int ii: prev.keys) prev.keys.removeFirst();

        if(!child.leaf){
            for(Node ii: prev.childs) child.childs.add(ii);
            prev.childs = new Vector<Node>();
        }

        node.childs.remove(i + 1);
        child.n += prev.n + 1;
        node.n -= 1;
        prev.n = 0;
    }


    void borrowFromPrev(Node node, int i){
        Node child = node.childs.get(i);
        Node prev = node.childs.get(i-1);
        child.keys.add(node.keys.get(i));
        node.keys.remove(i);
        node.keys.add(i, prev.keys.get(prev.n - 1));
        prev.keys.removeLast();
        if(!child.leaf){
            node.childs.add(i, prev.childs.get(prev.n));
            prev.childs.removeLast();
        }
        child.n += 1;
        prev.n -= 1;
    }

    void borrowFromSucc(Node node, int i){
        Node child = node.childs.get(i);
        Node next = node.childs.get(i+1);
        child.keys.add(node.keys.get(i));
        node.keys.remove(i);
        node.keys.add(i, next.keys.get(0));
        next.keys.removeFirst();
        if(!child.leaf){
            node.childs.add(i, next.childs.get(0));
            next.childs.removeFirst();
        }
        child.n += 1;
        next.n -= 1;
    }

    void fill(Node node, int x){
        if(x != 0 && node.childs.get(x-1).n >= t){
            borrowFromPrev(node, x);
        }
        else if(x != node.n && node.childs.get(x+1).n >= t){
            borrowFromSucc(node, x);
        }
        else{
            if(x!= node.n){
                merge(node, x);
            }
            else{
                merge(node, x - 1);
            }
        }
    }
    void deletion(Node node, int x){
        int i = getMinimum(node, x);

        if(i < node.n && node.keys.get(i) == x){
            if(node.leaf){
                node.keys.remove(i);
                node.n -=1;
            }
            else{
                if (node.childs.get(i).n >= t){
                    int temp = getPredecessor(node, i);
                    node.keys.set(i,temp);
                    deletion(node.childs.get(i), temp);
                } 
                else if (node.childs.get(i + 1).n >= t){
                    int temp = getSuccessor(node, i);
                    node.keys.set(i,temp);
                    deletion(node.childs.get(i+1), temp);
                }
                else{
                    merge(node,i);
                    deletion(node, x);
                }
            }
        }
        else{
            if(node.leaf){
                System.out.println("None");
            }
            else{
                boolean flag = i == node.n;
                if (node.childs.get(i).n < t){
                    fill(node, i);
                }
                

                if(flag && i > node.n){
                    deletion(node.childs.get(i - 1), x);
                }
                else{
                    deletion(node.childs.get(i), x);
                }
            }
        }
    }
};

