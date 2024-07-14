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
        Node(){
            leaf = false;
        }

        Node(bool leaf1){
            leaf = leaf1;
        }
};

class BST{
    public:
        int t;
        Node* root = new Node();

    public:
        BST(int t1){
            t = t1;