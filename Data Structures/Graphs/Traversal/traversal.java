import java.util.Vector;
import java.util.Queue;
import java.util.HashMap;
import java.util.LinkedList;

class Graph{
    int vertex = 0;
    Vector<Vector<Integer>> graph = new Vector<Vector<Integer>>();

    Graph(int vertex){
        this.vertex = vertex;
        Vector<Integer> temp = new Vector<Integer>();
        for(int i = 0; i < vertex; i++){
            temp.add(0);
        }
        for(int i = 0; i < vertex; i++){
            graph.add((Vector<Integer>)temp.clone());
        }
    }

    void addEdge(int x, int y){
        graph.get(x).set(y, 1);
        graph.get(y).set(x, 1);
    }

    void print(){
        for(int i = 0; i < this.vertex; i++){
            for(int j = 0; j < this.vertex; j++){
                System.out.printf("%d ", graph.get(i).get(j));
            }
            System.out.println();
        }
    }

    void BFS(int startIndex){
        Queue<Integer> q = new LinkedList<Integer>();
        q.add(startIndex);
        HashMap<Integer, Integer> done = new HashMap<Integer, Integer>(); 
        done.put(startIndex, 0);
        while(!q.isEmpty()){
            int currIndex = q.remove();
            System.out.printf("%d ", currIndex);
            Vector<Integer> temp = graph.get(currIndex);
            for(int i = 0; i < temp.size(); i++){
                if(temp.get(i) == 1 && done.get(i) == null){
                    q.add(i);
                    done.put(i, 1);
                }
            } 
        }
    }

    void DFS(int startIndex, Vector<Integer> done){
        Vector<Integer> temp = graph.get(startIndex);
        for(int i = 0; i < vertex; i++){
            if(temp.get(i) == 1 && !contains(done, i)){
                done.add(i);
                DFS(i, done);
            }
        }
    }

    boolean contains(Vector<Integer> temp, int value){
        for(int i: temp){
            if (i == value){
                return true;
            }
        }
        return false;
    }
}
public class traversal {
    public static void main(String args []){
        Graph g = new Graph(6);
        g.addEdge(1, 2);
        g.addEdge(1, 0);
        g.addEdge(2, 0);
        g.addEdge(2, 3);
        g.addEdge(2, 4);
    
        g.print();
        g.BFS(0);
        System.out.println();
        Vector<Integer> done = new Vector<Integer>(){{add(new Integer(0));}};
        g.DFS(0, done);
        for(int i: done){
            System.out.printf("%d ", i);
        }
    }
}
