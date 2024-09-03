class Graph{
    int vertex;
    int graph [][];
    int cur = 0;
    
    Graph(int vertex){
        this.vertex = vertex;
        this.graph = new int[8][3];
    }
    
    void addEdge(int u, int v, int d){
        this.graph[this.cur][0] = u;
        this.graph[this.cur][1] = v; 
        this.graph[this.cur][2] = d;
        this.cur += 1; 
    }

    void BellmanFordAlgo(int startVertex){
        int[] dist = new int[vertex];
        for(int i = 0; i < vertex; i++){
            dist[i] = Integer.MAX_VALUE;
        }
        dist[startVertex] = 0;
        for(int i = 0; i< vertex - 1; i++){
            for(int j = 0; j < graph.length; j++){
                if(dist[graph[j][0]] != Integer.MAX_VALUE && dist[graph[j][0]] + graph[j][2] < dist[graph[j][1]]){
                    dist[graph[j][1]] = dist[graph[j][0]] + graph[j][2];
                }
            }
        }
        for(int i = 0; i < graph.length; i++){
            if(dist[graph[i][0]] != Integer.MAX_VALUE && dist[graph[i][0]] + graph[i][2] < dist[graph[i][1]]){
                System.out.println("Negative Cycle");
            }
        }
        print(dist);
    }

    void print(int dist[]){
        for(int i = 0; i < vertex; i++){
            System.out.printf("%d %d\n",i,dist[i]);
        }
    }
};

public class BellmanFords {
    public static void main(String args []){
        Graph g = new Graph(5);    
        g.addEdge(0, 1, -1);
        g.addEdge(0, 2, 4);
        g.addEdge(1, 2, 3);
        g.addEdge(1, 3, 2);
        g.addEdge(1, 4, 2);
        g.addEdge(3, 2, 5);
        g.addEdge(3, 1, 1);
        g.addEdge(4, 3, -3);
    
        g.BellmanFordAlgo(0);
    }
}
