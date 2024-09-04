#include<vector>
#include<iostream>
#include <bits/stdc++.h> 
using namespace std;

class Graph{
    public:
    int vertex;
    vector<vector<int>> graph;

    Graph(int vertex1){
        vertex = vertex1;
    }

    void addEdge(int u, int v, int w){
        vector<int> temp;
        temp.push_back(w);
        temp.push_back(u);
        temp.push_back(v);
        graph.push_back(temp);
    }


    int getParent(int* parent, int i){
        if(parent[i] != i){
            parent[i] = getParent(parent, parent[i]);
        }
        return parent[i];
    }

    void unioning(int* rank, int* parent, int u, int v){
        if(rank[u] > rank[v]){
            parent[v] = u;
        }
        else if(rank[u] < rank[v]){
            parent[u] = v;
        }
        else{
            parent[v] = u;
            rank[u] += 1;
        }
    }

    void kuskals(){
        int e = 0;
        int* parent = new int[vertex];
        int* rank = new int[vertex];
        sort(graph.begin(), graph.end());
        vector<vector<int>> result;
        for (int i = 0; i < vertex; i++){
            parent[i] = i;
            rank[i] = 0;
        }
        int i = 0;
        while (e < vertex - 1){
            int u = graph.at(i).at(1), v = graph.at(i).at(2), w = graph.at(i).at(0);
            int x = getParent(parent, u);
            int y = getParent(parent, v);
            if (x != y){
                e++;
                result.push_back(graph.at(i));
                unioning(rank, parent, x, y);
            } 
            i++;    
        }
        for(int i = 0; i < result.size(); i++){
            cout << result.at(i).at(1) << " " << result.at(i).at(2) << " " << result.at(i).at(0) << "\n";
        }
    }
};

int main(){
    Graph g = Graph(4);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5); 
    g.addEdge(1, 3, 15); 
    g.addEdge(2, 3, 4); 

    g.kuskals();
    return 0;
}