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

        void dijkstras(int startIndex){
            int *dist =  new int[vertex];
            for(int i = 0; i < vertex; i++)
                dist[i] = INT_MAX;
            
            bool *done = new bool[vertex];
            for(int i = 0; i < vertex; i++)
                done[i] = false;

            dist[startIndex] = 0;

            for(int count = 0; count < vertex; count++){
                int x = minDistance(dist, done);
                done[x] = true;

                for(int y = 0; y < vertex; y++){
                    if(graph[x][y] && !done[y] && dist[y] > dist[x] + graph[x][y]){
                        dist[y] = dist[x] + graph[x][y];

                    }
                }
            }

            print(dist);

        }

        void print(int* dist){
            for(int i=0 ;i<vertex; i++){
                cout<<i<<"  "<<dist[i]<<"\n";
            }
        }

        int minDistance(int * dist, bool * done){
            int min = INT_MAX;
            int min_index;
            for(int i = 0; i < vertex; i++){
                if(dist[i]<min && !done[i]){
                    min = dist[i];
                    min_index = i;
                }
            }
            return min_index;
        }
};

int main(){
    Graph g = Graph(9);
    g.graph = { {0, 4, 0, 0, 0, 0, 0, 8, 0},
                {4, 0, 8, 0, 0, 0, 0, 11, 0},
                {0, 8, 0, 7, 0, 4, 0, 0, 2},
                {0, 0, 7, 0, 9, 14, 0, 0, 0},
                {0, 0, 0, 9, 0, 10, 0, 0, 0},
                {0, 0, 4, 14, 10, 0, 2, 0, 0},
                {0, 0, 0, 0, 0, 2, 0, 1, 6},
                {8, 11, 0, 0, 0, 0, 1, 0, 7},
                {0, 0, 2, 0, 0, 0, 6, 7, 0}};
    g.dijkstras(0);
    return 0;
}
    