#include<vector>
#include<iostream>
using namespace std;

class GraphByMatrix{
    public:
        int n;
        vector<vector<int>> graph;

    public:
        GraphByMatrix(int n1){
            n = n1;
            vector<int> temp;
            for(int i = 0; i< n1; i++){
                for(int j = 0; j< n1; j++){
                    temp.insert(temp.end(), 0);                    
                }
                graph.insert(graph.end(), temp);
            }
        }

        void print(){
            for(int i = 0; i< n; i++){
                for(int j = 0; j< n; j++){
                    cout << graph[i][j] << ' ';                 
                }
                cout << '\n';
            }
        }

        void addEdge(int x, int y){
            if(x >=n && y>=n){
                cout << "No Vertex";
            }
            else if(x == y){
                cout << "Same Vertex";
            }
            else{
                graph[x][y] = 1;
                graph[y][x] = 1;
            }
        }

        void removeEdge(int x, int y){
            if(x >=n && y>=n){
                cout << "No Vertex";
            }
            else if(x == y){
                cout << "Same Vertex";
            }
            else{
                graph[x][y] = 0;
                graph[y][x] = 0;
            }
        }

        void addVertex(){
            n += 1;
            vector<int> temp;
            for(int i = 0; i< n; i++){
                temp.insert(temp.end(), 0);                    
            }
            graph.push_back(temp);
        }

        void removeVertex(int x){
            if(x>=n){
                cout<<"Nothing to delete";
            }
            else{

                while(x<n-1){

                    for(int i = 0; i < n; i++){
                        graph[i][x] = graph[i][x+1];
                    }
                    for(int i = 0; i < n; i++){
                        graph[x][i] = graph[x+1][i];
                    }
                    x += 1;
                }
                
                n -= 1;
            }
        }
};

int main(){
    GraphByMatrix g = GraphByMatrix(4);
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