import java.util.Vector;
import java.util.*;

class Graph{
    int vertex;
    Vector<Vector<Integer>> graph = new Vector<Vector<Integer>>();

    Graph(int vertex){
        this.vertex = vertex;
    }

    void addEdge(int u, int v, int w){
        Vector<Integer> temp = new Vector<>();
        temp.add(w);
        temp.add(u);
        temp.add(v);
        this.graph.add(temp);
    }

    void printIt(){
        for(int i = 0; i < this.graph.size(); i++){
            System.out.printf("%d %d %d\n", this.graph.get(i).get(1), this.graph.get(i).get(2), this.graph.get(i).get(0));
        }
    }

    void sort(){
        System.out.println("Before Sorting");
        printIt();
        for(int i = 0; i < this.graph.size(); i++){
            Vector<Integer> sorted = new Vector<>();
            int j = i + 1;
            int temp = i;
            while(j < this.graph.size()){
                if(this.graph.get(temp).get(0)>this.graph.get(j).get(0)){
                    temp = j;
                }
                j++;
            }
            sorted = this.graph.get(i);
            this.graph.setElementAt(this.graph.get(temp), i);
            this.graph.setElementAt(sorted, temp);
        }
        System.out.println("After Sorting");
        printIt();
        System.out.println("________________");
    }

    int getParent(int parent[], int i){
        if(parent[i] != i){
            parent[i] = getParent(parent, parent[i]);
        }
        return parent[i];
    }

    void union(int rank[], int parent [], int u, int v){
        if(rank[u] < rank[v]){
            parent[u] = v;
        }
        else if(rank[u] > rank[v]){
            parent[v] = u;
        }
        else{
            parent[v] = u;
            rank[u] += 1;
        }
    }

    void kuskals(){
        int parent[] = new int[vertex];
        int rank[] = new int[vertex];
        Vector<Vector<Integer>> result = new Vector<Vector<Integer>>();
        sort();

        for(int i = 0; i < vertex; i++){
            parent[i] = i;
            rank[i] = 0;
        }

        int i = 0;
        int e = 0;
        while(e < this.vertex - 1){
            int u = this.graph.get(i).get(1), v = this.graph.get(i).get(2), w = this.graph.get(i).get(0);
            int x = getParent(parent, u);
            int y = getParent(parent, v);
            if(x != y){
                Vector<Integer> temp = new Vector<Integer>();
                e++;
                union(rank, parent, x, y);
                temp.add(w);
                temp.add(u);
                temp.add(v);
                result.add(temp);
            }

            i++;
        }
        
        for(int j = 0; j < result.size(); j++){
            System.out.printf("%d %d %d\n", result.get(j).get(1), result.get(j).get(2), result.get(j).get(0));
        }
    } 
}

public class kuskals {
    public static void main(String args[]){
        Graph g = new Graph(4);
        g.addEdge(0, 1, 10);
        g.addEdge(0, 2, 6);
        g.addEdge(0, 3, 5); 
        g.addEdge(1, 3, 15); 
        g.addEdge(2, 3, 4); 
    
        g.kuskals();
    }
}