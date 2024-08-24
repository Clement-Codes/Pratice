#include"iostream"
#include"vector"
using namespace std;
class Node{
    public:
        int data;
        Node* next;
    public:
        Node(int data1){
            data = data1;
            next = NULL;
        }
};

class GraphwithList{
    public:
        int vertex;
        vector<Node*> graph = vector<Node*>();
    public:
        GraphwithList(int vertex1){
            vertex = vertex1;
            for(int i = 0; i< vertex1; i++)
                graph.push_back(NULL);
        }

        void print(){
            for(int i = 0; i< vertex; i++){
                cout << i;
                Node* temp = graph[i];
                while (temp != NULL){
                    cout << " -> " << temp->data;
                    temp = temp->next;
                }
                cout << "\n";
            }
        }

        void addEdge(int x, int y){
            Node* temp = new Node(y);
            temp->next = graph[x];
            graph[x] = temp;

            temp = new Node(x);
            temp->next = graph[y];
            graph[y] = temp;
        }
        
        void removeEdge(int x, int y){
            Node* temp  = graph[x];
            if(temp != NULL && temp->data == y){
                graph[x] = temp->next;
            }
            else{
                while(temp != NULL){
                    if(temp->next->data == y){
                        temp->next = temp->next->next;
                        break;
                    }
                    temp = temp->next;
                }
            }

            temp= graph[y];
            if(temp != NULL && temp->data == x){
                graph[y] = temp->next;
            }
            else{
                while(temp != NULL){
                    if(temp->next->data == x){
                        temp->next = temp->next->next;
                        break;
                    }
                    else{
                        temp = temp->next;
                    }
                }
            }
        }

        void addVertex(int x, int y, int z){
            addEdge(y, x);
            addEdge(x, z);
        }

        void removeVertex(int v){
            for(int i=0; i<graph.size(); i++){
                Node* temp = graph[i];
                if(i == v){
                    graph[i] = temp->next;
                    temp = graph[i];
                }
                while(temp != NULL){
                    if(temp->data == v){
                        break;
                    }
                    Node* prev = temp;
                    temp = temp->next;
                    if(temp == NULL){
                        continue;
                    }
                    prev->next = temp->next;
                    temp = NULL;
                }
            }
        }
};

int main(){
    GraphwithList g = GraphwithList(5);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(3, 2);
    g.addEdge(4, 3);

    g.addVertex(5, 3, 2);
    g.print();
    cout<<'_';
    g.removeVertex(4);
    g.print();
    // g.addEdge(0, 1);
    // g.addEdge(0, 4);
    // g.addEdge(1, 2);
    // g.addEdge(1, 3);
    // g.addEdge(1, 4);
    // g.addEdge(2, 3);
    // g.addEdge(3, 4);
 
    // g.print();

    // g.removeEdge(1, 4);
 
    // g.print();
    return 0;
}