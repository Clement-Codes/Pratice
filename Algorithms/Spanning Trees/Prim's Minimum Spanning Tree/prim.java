
class Graph{
    int vertex;
    int graph[][];

    Graph(int vertex){
        this.vertex = vertex;
    }

    void addEdges(int edges[][]){
        this.graph = new int[vertex][vertex];
        for(int i = 0; i< 5; i++){
            for(int j = 0; j< 5; j++){
                this.graph[i][j] = edges[i][j];
            }
        }
    }

    int minDistance(int distance[], boolean processed[]){
        int minDistance = Integer.MAX_VALUE;
        int minIndex = -1;
        for(int i=0; i<vertex; i++){
            if(distance[i]<minDistance && !processed[i]){
                minDistance = distance[i];
                minIndex = i;
            }
        }
        return minIndex;
    }

    void prim(){
        int parent[] = new int[vertex];
        boolean processed[] = new boolean[vertex];
        int distance[] = new int[vertex];
        for(int i=0;i<this.vertex;i++){
            parent[i] = i;
            processed[i] = false;
            distance[i] = Integer.MAX_VALUE;
        }

        parent[0] = -1;
        distance[0] = 0;

        for(int i = 0; i < this.vertex; i++){
            int minIndex = minDistance(distance, processed);
            processed[minIndex] = true;
            for(int j = 0; j < this.vertex; j++){
                if(this.graph[minIndex][j]>0 && this.graph[minIndex][j]< distance[j] && !processed[j]){
                    parent[j]=minIndex;
                    distance[j] = this.graph[minIndex][j];
                }
            }
        }

        for(int i = 1; i < this.vertex; i++){
            System.out.printf("%d - %d %d\n",parent[i], i, distance[i]);
        }
    }


};

public class prim {
    public static void main(String args[]){
        Graph g = new Graph(5);
        int edges[][] =  {{0, 2, 0, 6, 0},
                            {2, 0, 3, 8, 5},
                            {0, 3, 0, 0, 7},
                            {6, 8, 0, 0, 9},
                            {0, 5, 7, 9, 0}};
        g.addEdges(edges);
        g.prim();
    }
}
