import java.util.Vector;
class Node{
    int data;
    Node next;
    Node(int data){
        this.data = data;
        next = null;
    }
}

class GraphByList{
    int vertex;
    Vector<Node> graph = new Vector<Node>();

    GraphByList(int vertex){
        this.vertex = vertex;
        for(int i = 0; i < vertex; i++)
            graph.add(null);
    }

    void print(){
        for(int i = 0; i < vertex; i++)
        {
            System.out.print(i);
            Node temp = this.graph.get(i);
            while(temp != null){
                System.out.printf(" -> %d", temp.data);
                temp = temp.next;
            }
            System.out.println("\n");
        }
    }

    void addEdge(int x, int y){
        Node temp = new Node(y);
        temp.next = this.graph.get(x);
        graph.set(x, temp);

        temp = new Node(x);
        temp.next = this.graph.get(y);
        graph.set(y, temp);
    }

    void removeEdge(int x, int y){
        Node temp = this.graph.get(x);
        if(temp.data == y){
            this.graph.set(x, temp.next);
        }
        else{
            while(temp != null){
                if(temp.next.data == y){
                    temp.next= temp.next.next;
                    break;
                }
                temp = temp.next;
            }
        }

        temp = this.graph.get(y);
        if(temp.data == x){
            this.graph.set(y, temp.next);
        }
        else{
            while(temp != null){
                if(temp.next.data == x){
                    temp.next= temp.next.next;
                    break;
                }
                temp = temp.next;
            }
        }
    }

    void addVertex(int x, int y, int z){
        addEdge(y, x);
        addEdge(x, z);
    }

    void removeVertex(int x){
        for(int i = 0; i<this.vertex; i++){
            Node temp = graph.get(i);
            if(i == x){
                graph.set(i, temp.next);
                temp = graph.get(i);
            }
            while(temp!=null){
                if(temp.data == x){
                    break;
                }
                Node prev = temp;
                temp = temp.next;
                if(temp == null){
                    continue;
                }
                prev.next = temp.next;
                temp = null;
            }
        }
    }
}

public class Graph {
    public static void main(String str[]){
        GraphByList g = new GraphByList(6);

        g.addEdge(0, 1);
        g.addEdge(0, 3);
        g.addEdge(0, 4);
        g.addEdge(1, 2);
        g.addEdge(3, 2);
        g.addEdge(4, 3);
    
        g.addVertex(5, 3, 2);
        g.print();
        System.out.println("__________");
        g.removeVertex(4);
        g.print();
    }
}
