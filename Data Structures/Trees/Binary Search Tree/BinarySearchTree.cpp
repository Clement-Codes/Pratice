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

Node* insertion(Node* head, int data){
    if (head == NULL){
        Node* temp = new Node(data);
        return temp;
    }
    else if (data <= (head)->data){
        head->left = insertion((head)->left, data);
    }
    else if (data > (head)->data){
        head->right =  insertion((head)->right, data);
    }
    return head;
}

// void insertion(Node ** head, int data){
//     Node* x = new Node(data);
//     if(head == NULL){
//         *head = x;
//         return;
//     }
//     queue<Node*> q;
//     q.push(*head);
//     while(!q.empty()){
//         Node* temp = q.front();
//         q.pop();
//         if(temp->left == NULL){
//             temp->left = x;
//             return;
//         }
//         else{
//             q.push(temp->left);
//         }
//         if(temp->right == NULL){
//             temp->right = x;
//             return;
//         }
//         else{
//             q.push(temp->right);
//         }    
//     }

// }

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


Node* getMinimum(Node* head){
    if (head->left != NULL){
        getMinimum(head->left);
    }
    return head;
}

Node* deletion(Node* head, int x){
    if(head == NULL){
        return head;
    }
    else if(x < head->data){
        head->left = deletion(head->left, x);
    }
    else if(x > head->data){
        head->right = deletion(head->right, x);
    }
    else{
        if(head->left == NULL){
            Node* temp = head->right;
            free(head);
            return temp;
        }
        else if(head->right == NULL){
            Node* temp = head->left;
            free(head);
            return temp;        }
        else{
            Node* temp = getMinimum(head->right);
            cout << "Output: " << temp->data;
            head->data = temp->data;

            head->right = deletion(head->right, temp->data);
            
        }
        
    }
    return head;
}

int main(){
    Node* head = new Node(50);
    head = insertion(head, 30);
    head = insertion(head, 20);
    head = insertion(head, 40);
    head = insertion(head, 70);
    head = insertion(head, 60);
    head = insertion(head, 80);

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

    head = deletion(head, 30);

    cout <<"levelorder: ";
    levelorder(head);
    cout << endl;
    return 0;


}
