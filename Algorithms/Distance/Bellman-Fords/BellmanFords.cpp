#include<iostream>
#include<vector>
using namespace std;

class Graph{
    public:
    int vertex;
    vector<vector<int>> graph;
    Graph(int vertex1){
        vertex = vertex1;
    }
    
    void addEdge(int u, int v, int d){
        vector<int> temp = {u, v, d};
        graph.push_back(temp); 
    }

    void BellmanFordAlgo(int startVertex){
        int* dist = new int[vertex];
        for(int i = 0; i < vertex; i++){
            dist[i] = INT_MAX;
        }
        dist[startVertex] = 0;

        for(int i = 0; i< vertex - 1; i++){
            for(int i = 0; i < graph.size(); i++){
                if(dist[graph.at(i).at(0)] != INT_MAX && dist[graph.at(i).at(0)] + graph.at(i).at(2) < dist[graph.at(i).at(1)]){
                    dist[graph.at(i).at(1)] = dist[graph.at(i).at(0)] + graph.at(i).at(2);
                }
            }
        }
        for(int i = 0; i < graph.size(); i++){
            if(dist[graph.at(i).at(0)] != INT_MAX && dist[graph.at(i).at(0)] + graph.at(i).at(2) < dist[graph.at(i).at(1)]){
                cout << "Negative Cycle";
            }
        }
        print(dist);
    }

    void print(int dist[]){
        for(int i = 0; i < vertex; i++){
            cout << i << " " << dist[i]<< "\n";
        }
    }
};

int main(){
    Graph g = Graph(5);    
    g.addEdge(0, 1, -1);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 2);
    g.addEdge(1, 4, 2);
    g.addEdge(3, 2, 5);
    g.addEdge(3, 1, 1);
    g.addEdge(4, 3, -3);

    g.BellmanFordAlgo(0);
    return 0;
}