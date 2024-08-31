import java.util.Vector;

class Graph{
    int vertex;
    int graph [][];

    Graph(int vertex){
        this.vertex = vertex;
        this.graph = new int[vertex][vertex];
    }

    int minDistance(int dist[], boolean done[]){
        int min = Integer.MAX_VALUE;
        int min_index = 0;

        for(int i = 0; i< this.vertex; i++){
            if(min > dist[i] && !done[i]){
                min = dist[i];
                min_index = i; 
            }
        }

        return min_index;

    }

    void dijkstras(int startVertex){
        int dist[] = new int[this.vertex];
        boolean done[] = new boolean[this.vertex];
        for(int i = 0; i < this.vertex; i++){
            dist[i] = Integer.MAX_VALUE;
            done[i] = false;
        }

        dist[startVertex] = 0;
        
        for(int c = 0; c < this.vertex; c++){
            int min = minDistance(dist, done);
            done[min] = true;

            for(int i = 0; i < this.vertex; i++){
                if(graph[min][i] != 0 && !done[i] && dist[i] > dist[min] + graph[min][i] ){
                    dist[i] = dist[min] + graph[min][i];
                }
            }
        }

        print(dist);
    }

    void print(int dist[]){
        for(int i = 0; i < this.vertex; i++){
            System.out.printf("%d  %d\n", i, dist[i]);
        }
    }

}
public class dijkstras {
    public static void main(String args []){
        Graph g = new Graph(9);
        g.graph = new int [][]{ {0, 4, 0, 0, 0, 0, 0, 8, 0}, {4, 0, 8, 0, 0, 0, 0, 11, 0}, {0, 8, 0, 7, 0, 4, 0, 0, 2}, {0, 0, 7, 0, 9, 14, 0, 0, 0}, {0, 0, 0, 9, 0, 10, 0, 0, 0}, {0, 0, 4, 14, 10, 0, 2, 0, 0}, {0, 0, 0, 0, 0, 2, 0, 1, 6}, {8, 11, 0, 0, 0, 0, 1, 0, 7}, {0, 0, 2, 0, 0, 0, 6, 7, 0}};
        g.dijkstras(0);
    }
}
