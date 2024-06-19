# include<iostream>
using namespace std;
class Node{
    public:
        char data;
        Node* next = nullptr;
    
    public:
        Node(char data1){
            data = data1;
        }
};

void traverse(Node *cll){
    cout << "tail= "<< cll->data << endl;
    cout << "traverse= ";
    Node* head =  cll->next;
    if(cll->next != nullptr){
        do{
            cout << head->data << " ";
            head = head->next;
        }while(head != cll->next);
    }
    else{
        cout << cll->data << endl;
    }
}

void insertAtBegining(Node** cll, char data){
    Node* temp = new Node(data);
    if(cll!=nullptr){
        if((*cll)->next!=nullptr){
            temp->next = (*cll)->next;
        }
        else{
             temp->next = *cll;
        }
        (*cll)->next = temp;
    }
    else{
        *cll = temp;
    }
}

void insertAtEnd(Node** cll, char data){
    Node* temp = new Node(data);
    if(*cll != nullptr){
        temp->next = (*cll)->next;
        (*cll)->next = temp;
        (*cll) = temp;
    }
    else{
        *cll = temp;
    }
}

void insertAtPosition(Node** cll, int position, char data){
    Node* temp = new Node(data);
    if(*cll != nullptr){
        Node* positionPointer = (*cll)->next;
        for(int i = 1; i<position && positionPointer != nullptr && positionPointer->next!=nullptr; i++){
            positionPointer = positionPointer->next;
        }
        temp->next = positionPointer->next;
        positionPointer->next = temp;
        if(positionPointer == *cll){
            *cll = temp;
        }
    }
    else{
        *cll = temp;
    }
}

int main(){
    Node* cll = new Node('D');
    traverse(cll);
    insertAtBegining(&cll, 'C');
    insertAtBegining(&cll, 'B');
    insertAtBegining(&cll, 'A');
    insertAtEnd(&cll, 'F');
    insertAtPosition(&cll, 4, 'E');
    insertAtPosition(&cll, 6, 'G');
    traverse(cll);
    return 0;
}