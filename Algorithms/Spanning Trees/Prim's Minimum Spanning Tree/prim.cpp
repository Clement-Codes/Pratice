#include<iostream>
#include<vector>
using namespace std;

class Graph{
    public:
    int vertex;
    int graph[5][5];

    Graph(int vertex1){
        vertex = vertex1;
    }

    void addEdges(int edges[5][5]){
        for(int i = 0; i< 5; i++){
            for(int j = 0; j< 5; j++){
                graph[i][j] = edges[i][j];
            }
        }
    }

    int minDistance(int* distance, bool* processed){
        int minDistance = INT_MAX;
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
        int* parent = new int[vertex];
        bool* processed = new bool[vertex];
        int* distance = new int[vertex];
        for(int i=0;i<vertex;i++){
            parent[i] = i;
            processed[i] = false;
            distance[i] = INT_MAX;
        }

        parent[0] = -1;
        distance[0] = 0;

        for(int i = 0; i < vertex; i++){
            int minIndex = minDistance(distance, processed);
            processed[minIndex] = true;
            for(int j = 0; j < vertex; j++){
                if(graph[minIndex][j]>0 && graph[minIndex][j]< distance[j] && !processed[j]){
                    parent[j]=minIndex;
                    distance[j] = graph[minIndex][j];
                }
            }
        }

        for(int i = 1; i < vertex; i++){
            cout<<parent[i]<<" - "<<i<<" "<<distance[i]<<"\n";
        }
    }


};

int main(){
    Graph g = Graph(5);
    int edges[5][5] =  {{0, 2, 0, 6, 0},
                        {2, 0, 3, 8, 5},
                        {0, 3, 0, 0, 7},
                        {6, 8, 0, 0, 9},
                        {0, 5, 7, 9, 0}};
    g.addEdges(edges);
    g.prim();
    return 0;
}