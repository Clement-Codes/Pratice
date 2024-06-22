#include<iostream>
using namespace std;

class Node{
    public:
    char data;
    Node* prev;
    Node* next;

    public:
    Node(char data1){
        data = data1;
        prev = nullptr;
        next = nullptr;
    }
};

void traverse(Node* DCLL){
    Node* temp = DCLL;
    Node* temp2;
    cout << endl << "Forward: ";
    do{
        temp2 = temp;
        cout << temp->data << " ";
        temp = temp->next;
    }while (temp != nullptr && temp!=DCLL);
    cout << endl << "Backward: ";
    do{
        cout << temp2->data << " ";
        temp2 = temp2->prev;
    }while (temp2 != nullptr && temp2!=DCLL->prev);
}

void insertAtBeginning(Node** DCLL, char data){
    Node* temp = new Node(data);
    if(*DCLL==nullptr){
        (*DCLL) = temp;
        return;
    }
    else{
        temp->next = (*DCLL);
        (*DCLL)->prev = temp;
        Node* temp2 = (*DCLL);
        while(temp2->next != nullptr && temp2->next != *DCLL){
            temp2 = temp2->next;
        }
        temp2->next = temp;
        temp->prev = temp2;
        (*DCLL) = temp;
        return;
    }
}

void insertAtEnd(Node** DCLL, char data){
    Node* temp = new Node(data);
    if(*DCLL==nullptr){
        (*DCLL) = temp;
        return;
    }
    else{
        Node* temp2 = (*DCLL);
        while(temp2->next != nullptr && temp2->next != *DCLL){
            temp2 = temp2->next;
        }
        temp->next = temp2->next;
        temp2->next->prev=temp;
        temp2->next = temp;
        temp->prev = temp2;
        return;
    }
}

void insertAtPosition(Node** DCLL, int position, char data){
    Node* temp = new Node(data);
    if(*DCLL==nullptr){
        (*DCLL) = temp;
        return;
    }
    else{
        Node* temp2 = (*DCLL);
        for(int i = 1; i<position && temp2->next != nullptr && temp2->next != *DCLL; i++){
            temp2 = temp2->next;
        }
        temp->next = temp2->next;
        temp2->next->prev=temp;
        temp2->next = temp;
        temp->prev = temp2;
        return;
    }
}

void deleteAtBeginning(Node** DCLL){
    if(DCLL == nullptr){
        cout << "No Data";
    }
    else{
        Node* temp = (*DCLL)->next;
        temp->prev = (*DCLL)->prev; 
        (*DCLL)->prev->next = temp;
        delete *DCLL;
        (*DCLL) = temp;
    }
}

void deleteAtEnd(Node** DCLL){
    if(*DCLL == nullptr){
        cout << "No Data";
    }
    else{
        Node* temp = (*DCLL);
        while(temp->next != nullptr && temp->next != (*DCLL)){
            temp = temp->next;
        }
        temp->next->prev=temp->prev;
        temp->prev->next=temp->next;
    }
}

void deleteAtPosition(Node** DCLL, int position){
    if(*DCLL == nullptr){
        cout << "No Data";
    }
    else{
        Node* temp = (*DCLL);
        for(int i = 0; i<position && temp->next != nullptr && temp->next != (*DCLL);i++){
            temp = temp->next;
        }
        temp->next->prev=temp->prev;
        temp->prev->next=temp->next;
    }
}

int main(){
    Node* DCLL = new Node('D');
    insertAtBeginning(&DCLL, 'C');
    insertAtBeginning(&DCLL, 'B');
    insertAtBeginning(&DCLL, 'A');
    insertAtEnd(&DCLL, 'G');
    insertAtPosition(&DCLL, 4, 'E');
    insertAtPosition(&DCLL, 5, 'F');
    traverse(DCLL);
    deleteAtBeginning(&DCLL);
    deleteAtEnd(&DCLL);
    deleteAtPosition(&DCLL,3);
    traverse(DCLL);
    return 0;
}
