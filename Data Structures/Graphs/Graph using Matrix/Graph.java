import java.util.Vector;

class GraphByMatrix{
    int n;
    Vector<Vector<Integer>> graph = new Vector<Vector<Integer>>();
    GraphByMatrix(int n){
        this.n = n;
        Vector<Integer> temp = new Vector<Integer>();
        for(int i = 0; i< this.n; i++){
            temp.add(0);
        }
        for(int i = 0; i< this.n; i++){
            graph.add((Vector)temp.clone());
        }
    }

    void print(){
        for(int i = 0; i< this.n; i++){
            for(int j = 0; j< this.n; j++){
                System.out.printf("%d ",graph.get(i).get(j));
            }
            System.out.printf("\n");
        }
    }

    void addEdge(int x, int y){
        if(x >= this.n || y>= this.n){
            System.out.println("No Vertex");
        }
        else if(x == y){
            System.out.println("Same Vertex");
        }
        else{
            this.graph.elementAt(x).set(y, 1);
            this.graph.elementAt(y).set(x, 1);
        }
    }

    void removeEdge(int x, int y){
        if(x >= this.n || y>= this.n){
            System.out.println("No Vertex");
        }
        else if(x == y){
            System.out.println("Same Vertex");
        }
        else{
            this.graph.elementAt(x).set(y, 0);
            this.graph.elementAt(y).set(x, 0);
        }
    }

    void addVertex(){
        Vector<Integer> temp = new Vector<Integer>();
        for(int i = 0; i< this.n; i++){
            this.graph.elementAt(i).add(0);
        }
        this.n += 1;
        for(int i = 0; i< this.n; i++){
            temp.add(0);
        }
        this.graph.add(temp);
    }

    void removeVertex(int x){
        if(x >= this.n){
            System.out.println("No Vertex found");
        }
        else{
            while(x < this.n -1){
                for(int i = 0; i<this.n ;i++){
                    this.graph.get(i).set(x, graph.get(i).get(x + 1));
                }
                for(int i = 0; i<this.n ;i++){
                    this.graph.get(x).set(i, graph.get(x + 1).get(i));
                }
                x++;
            }
            this.n -= 1;
        }
    }
}

/**
 * Graph
 */
public class Graph {
    public static void main(String args[]){
        GraphByMatrix g = new GraphByMatrix(4);
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 2);
        g.addEdge(2, 3);    
        g.addVertex();
        g.addEdge(4, 1);
        g.addEdge(4, 3);
        g.print();
            
        g.removeVertex(1);
        g.print();
    }
}