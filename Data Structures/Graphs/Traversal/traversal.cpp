#include"iostream"
#include"vector"
#include"queue"
#include<unordered_map>
#include<ranges>
using namespace std;

class Graph{
    public:
        int vertex;
        vector<vector<int>> g;

    public:
        Graph(int vertex1){
            vertex = vertex1;
            vector<int> temp;
            for(int j=0; j<vertex; j++)
                temp.push_back(0);
            for(int i=0; i<vertex; i++)
                g.push_back(temp);
        }

        void addEdge(int x, int y){
            g[x][y] = 1;
            g[y][x] = 1;
        }

        void print(){
            for(int i=0; i<vertex; i++){
                for(int j=0; j<vertex; j++){
                    cout << g[i][j] << " ";
                }
                cout << "\n";
            }
        }

        void BST(int startIndex){
            queue<int> q;
            q.push(startIndex);
            unordered_map<int,int> visited;
            visited[startIndex] = 1;
            while (!q.empty())
            {
                int curr = q.front();
                q.pop();
                
                cout << curr;
                vector<int> temp = g[curr];
                for(int i = 0; i< vertex; i ++){
                    if (temp[i] == 1  && !visited[i]){
                        q.push(i);
                        visited[i] = 1;
                    }
                }
                
            }
        }

        void DFS(int curr, vector<int> *done){
            vector<int> temp = g[curr];
            for(int i=0; i<vertex ;i++){
                if(temp[i] == 1 && !contains(done, i)){
                    done->push_back(i);
                    DFS(i, done);
                }
            }
        }

        bool contains(vector<int> *temp, int i){
            for(int j = 0; j<temp->size(); j++){
                if(temp->at(j) == i)
                    return true;
            }
            return false;
        }
};

int main(){
    Graph g = Graph(6);
    g.addEdge(1, 2);
    g.addEdge(1, 0);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(2, 4);

    g.print();

    g.BST(0);
    cout << "\n";
    vector<int>DFS = {0};
    g.DFS(0, &DFS);
    for(int i: DFS){
        cout << i;
    }
    return 0;
}