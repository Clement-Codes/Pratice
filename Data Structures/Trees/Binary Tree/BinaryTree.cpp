#include <iostream>
#include<queue>
using namespace std;

class Node{
    public: 
    int data;
    Node* left;
    Node* right;

    public:
    Node(int data1){
        data = data1;
        left = NULL;
        right = NULL;
    }
};

void insertion(Node ** head, int data){
    Node* x = new Node(data);
    if(head == NULL){
        *head = x;
        return;
    }
    queue<Node*> q;
    q.push(*head);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp->left == NULL){
            temp->left = x;
            return;
        }
        else{
            q.push(temp->left);
        }
        if(temp->right == NULL){
            temp->right = x;
            return;
        }
        else{
            q.push(temp->right);
        }    
    }

}

void preorder(Node* head){
    if (head==NULL){
        return;
    }
    cout << head->data << ",";
    preorder(head->left);
    preorder(head->right);
}

void inorder(Node* head){
    if (head==NULL){
        return;
    }
    inorder(head->left);
    cout << head->data << ",";
    inorder(head->right);
}

void postorder(Node* head){
    if (head==NULL){
        return;
    }
    postorder(head->left);
    postorder(head->right);
    cout << head->data << ",";
}

void levelorder(Node* head){
    queue<Node*> q;
    q.push(head);
    while(!q.empty()){

        Node* temp = q.front();
        cout << temp->data << ",";
        q.pop();

        if(temp->left != NULL){
            q.push(temp->left);
        }
        
        if(temp->right != NULL){
            q.push(temp->right);
        }

    }
}


void deletionDeep(Node * head, Node * x){
    queue<Node*> q;
    q.push(head);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == x){
            temp = NULL;
            delete x;
            return;
        }
        if(temp->left == x){
            temp->left = NULL;
            delete x;
            return;
        }
        else{
            q.push(temp->left);
        }
        if(temp->right == x){
            temp->right = NULL;
            delete x;
            return;
        }
        else{
            q.push(temp->right);
        }    
    }

}

void deletion(Node * head, int data){
    queue<Node*> q;
    q.push(head);
    Node* temp;
    Node* keyNode = NULL;
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp->data == data){
            keyNode = temp;
        }
        if(temp->left != NULL){
            q.push(temp->left);
        }
        if(temp->right != NULL){
            q.push(temp->right);
        }  
    }
    if(keyNode != NULL){
        int x = temp->data;
        keyNode->data = x;
        deletionDeep(head, temp);
    }
}


int main(){
    Node* head = new Node(1);
    insertion(&head, 2);
    insertion(&head, 3);
    insertion(&head, 4);
    insertion(&head, 5);

    cout <<"preorder: ";
    preorder(head);
    cout << endl;

    cout <<"inorder: ";
    inorder(head);
    cout << endl;

    cout <<"postorder: ";
    postorder(head);
    cout << endl;

    cout <<"levelorder: ";
    levelorder(head);
    cout << endl;

    deletion(head, 3);

    cout <<"levelorder: ";
    levelorder(head);
    cout << endl;
    return 0;


}
