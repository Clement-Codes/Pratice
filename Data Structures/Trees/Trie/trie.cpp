#include<iostream>

using namespace std;

class TrieNode{
    public:
    TrieNode* child[26];
    bool endWord;

    TrieNode(){
        for(int i=0; i<26; i++){
            child[i] = nullptr;
        }
        endWord = false;
    }
};

void insert_key(TrieNode* root, string word){
    for(char i: word){
        int index = int(i) - int('a');
        if(root->child[index] == nullptr){
            TrieNode* temp = new TrieNode();
            root->child[index] = temp;
        }
        root = root->child[index];
    }
    root->endWord = true;
};



bool search_key(TrieNode* root, string word){
    for(char i: word){
        int index = int(i) - int('a');
        if(root->child[index] == nullptr){
            return false;
        }
        root = root->child[index];
    }
    return root->endWord;
};

int main(){
    TrieNode* root = new TrieNode();
    string arr[6] = {"and", "ant", "do", "geek", "dad", "ball"};
    for(string word :arr)
        insert_key(root, word);

    string search_keys[3] = {"do", "gee", "bat"};
    for (string s : search_keys){
        cout << "Key : "<< s;
        if (search_key(root, s)){
            cout << " Present\n" ;
        }
        else{
            cout << " Not Present\n";
        }
    }
        
    return 0;
}