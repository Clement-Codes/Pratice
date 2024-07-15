#include<vector>
#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
        int n = 0;
        vector<int> keys;
        vector<Node*> childs;
        bool leaf;
    
    public:
        Node(bool leaf1){
            leaf = leaf1;
        }
};

class BST{
    public:
        int t;
        Node* root = new Node(true);

    public:
        BST(int t1){
            t = t1;
        }

        void insertion(int key){
            if (root->n == 0){
                root->keys.push_back(key);
                root->n += 1;
                return;
            }
            
            if (root->n == (2*t) -1){
                    Node* temp = new Node(false);
                    temp->childs.push_back(root);
                    root = temp;
                    split(root, 0);
                    insertion_null(root, key);
            }
            else{
                insertion_null(root, key);
            }


        }

        void insertion_null(Node* node, int key){
            int i = 0;
            while(key>node->keys[i] && i < node->n){
                
                i += 1;
            }
            if(node->leaf){
                node->keys.push_back(0);
                for(int ii = node->n-1; ii>i; ii++){
                    node->keys[ii] = node->keys[ii-1];
                }
                node->keys[i] = key;
                node->n += 1;
            }
            else{
                if(node->childs[i]->n == (2*t) -1){
                    split(node, i);
                    if(key > node->keys[i]){
                        i += 1;
                    }
                }
                insertion_null(node->childs[i], key);
            }
        }

        void split(Node* node, int i){
            Node* temp = new Node(node->childs[i]->leaf);
            for(int ii=t; ii< (2*t) -1; ++ii){
                temp->keys.push_back(node->childs[i]->keys[ii]);
            }

            for(int ii=t; ii< (2*t) -1; ii++){
                node->childs[i]->keys.erase(node->childs[i]->keys.begin()+ii);
            }                        

            node->keys.push_back(node->childs[i]->keys[t-1]);
            node->childs[i]->keys.erase(node->childs[i]->keys.begin()+t-1);

            if(! node->childs[i]->leaf){
                for(int ii=t; ii< (2*t); ii++){
                    temp->childs.push_back(node->childs[i]->childs[ii]);
                }

                for(int ii=t; ii< (2*t); ii++){
                    node->childs[i]->childs.erase(node->childs[i]->childs.begin()+ii);
                }
            }
            temp->n = ((2*t) -1 - t);
            node->childs[i]->n = t - 1;
            node->n += 1;
            node->childs.push_back(temp);

        }

        void levelOrder(){
            queue<int> level;
            level.push(0);
            queue<Node*> q;
            q.push(root);
            while(!q.empty()){
                Node* temp = q.front();
                int l = level.front();
                cout << "Level " << l <<": ";
                for(int i: temp->keys) cout<<i<<" ";
                q.pop();
                level.pop();
                cout<<endl;
                if (!temp->leaf){
                    for(Node* i: temp->childs){
                        q.push(i);
                        level.push(l+1);
                    }
                    
                }
                
            }
        }

        int getMinimum(Node* node,int x){
            int i = 0;
            while(x > (*node).keys[i] && i<node->n){
                i += 1;
            }
            return i;
        }

        void deletion_pre(int x){
            if (root->n == 0||root == nullptr){
                cout << "non";
            }
            deletion(root, x);      

            if(root->n==0){
                if(root->leaf){
                    root = nullptr;
                }
                else{
                    root = root->childs[0];
                }
            }
        }


        int getPredecessor(Node* node, int i){
            Node* temp = node->childs[i];
            while(!temp->leaf){
                temp = temp->childs[temp->n];
            }
            return temp->keys[temp->n - 1];
        }
        
        int getSuccessor(Node* node, int i){
            Node* temp = node->childs[i+1];
            while(!temp->leaf){
                temp = temp->childs[0];
            }
            return temp->keys[0];
        }

        void merge(Node* node, int i){
            

            Node* child = node->childs[i];
            Node* prev = node->childs[i+1];
            

            child->keys.push_back(node->keys[i]);

            node->keys.erase(node->keys.begin() + i);
            for(int ii: prev->keys) child->keys.push_back(ii);
            for(int ii: prev->keys) prev->keys.erase(prev->keys.begin());

            if(!child->leaf){
                for(Node* ii: prev->childs) child->childs.push_back(ii);
                for(Node* ii: prev->childs) prev->childs.erase(prev->childs.begin());
            }
            node->childs.erase(node->childs.begin() + (i + 1));
            child->n += prev->n + 1;
            node->n -= 1;
            prev->n = 0;
        }


        void borrowFromPrev(Node* node, int i){
            Node* child = node->childs[i];
            Node* prev = node->childs[i-1];
            child->keys.push_back(node->keys[i]);
            node->keys.erase(node->keys.begin() + i);
            node->keys.insert(node->keys.begin() + i, prev->keys[prev->n - 1]);
            prev->keys.pop_back();
            if(!child->leaf){
                node->childs.insert(node->childs.begin() + i, prev->childs[prev->n]);
                prev->childs.pop_back();
            }
            child->n += 1;
            prev->n -= 1;
        }

        void borrowFromSucc(Node* node, int i){
            Node* child = node->childs[i];
            Node* next = node->childs[i+1];
            child->keys.push_back(node->keys[i]);
            node->keys.erase(node->keys.begin() + i);
            node->keys.insert(node->keys.begin() + i, next->keys[0]);
            next->keys.erase(node->keys.begin());
            if(!child->leaf){
                node->childs.insert(node->childs.begin() + i, next->childs[0]);
                next->childs.erase(next->childs.begin());
            }
            child->n += 1;
            next->n -= 1;
        }

        void fill(Node* node, int x){
            if(x != 0 && node->childs[x-1]->n >= t){
                borrowFromPrev(node, x);
            }
            else if(x != node->n && node->childs[x]->n >= t){
                borrowFromSucc(node, x);
            }
            else{
                if(x!= node->n){
                    merge(node, x);
                }
                else{
                    merge(node, x - 1);
                }
            }
        }
        void deletion(Node* node, int x){
            int i = getMinimum(node, x);
            for(int temp: node->keys) cout << temp << " ";
            cout << "-"<<x<<endl;
            if(i < node->n && node->keys[i] == x){
                if(node->leaf){
                    node->keys.erase(node->keys.begin() + i);
                    node->n -=1;
                }
                else{
                    if (node->childs[i]->n >= t){
                        int temp = getPredecessor(node, i);
                        node->keys[i] = temp;
                        deletion(node->childs[i], temp);
                    } 
                    else if (node->childs[i + 1]->n >= t){
                        int temp = getSuccessor(node, i);
                        node->keys[i] = temp;
                        deletion(node->childs[i+1], temp);
                    }
                    else{
                        merge(node,i);
                        deletion(node, x);
                    }
                }
            }
            else{
                if(node->leaf){
                    cout<<"None";
                }
                else{
                    bool flag = i == node->n;
                    if (node->childs[i]->n < t){
                        fill(node, i);
                    }
                    

                    if(flag && i > node->n){
                        deletion(node->childs[i-1], x);
                    }
                    else{
                        deletion(node->childs[i], x);
                    }
                }
            }
        }
};

int main(){
    BST bst = BST(3);

    for(int i = 0; i<20; i++) bst.insertion(i);

    bst.levelOrder();


    for(int i = 0; i<20; i++) {
        bst.deletion_pre(i);
        bst.levelOrder();
    }
    

    return 0;
}