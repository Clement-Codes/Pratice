#include<iostream>
using namespace std;

class DoubleLinkedList{
    public:
    string data;
    DoubleLinkedList* next;
    DoubleLinkedList* prev;

    public:
    DoubleLinkedList(string data1){
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};

bool search(DoubleLinkedList* node, string target){
    while(node != nullptr){
        if(node->data == target){
            return true;
        }
        node = node->next;
    }
    return false;
}

void traverse(DoubleLinkedList* node){

    DoubleLinkedList* temp = node;
    DoubleLinkedList* last;
    cout << "Front: ";
    while(node!=nullptr){
        cout<< node->data << " ";
        last = node;
        node = node->next;
    }

    cout << endl << "Reverse: ";
    while(last != nullptr){
        cout << last->data << " ";
        last = last->prev;
    }

    cout << endl;
}

int length (DoubleLinkedList* node){
    int length = 0;
    while (node != nullptr)
    {
        length+=1;
        node=node->next;
    }
    return length;
}

void insertionAtBeginning(DoubleLinkedList** head, string data){
    DoubleLinkedList* temp = new DoubleLinkedList(data);
    temp->next = (*head);

    if((*head) != nullptr){
        (*head)->prev = temp;
    }

    *head = temp;
}

void insertionAtEnd(DoubleLinkedList** Node, string data){
    DoubleLinkedList* temp = new DoubleLinkedList(data);
    DoubleLinkedList* head_temp = *Node;
    if ((*Node) == nullptr){
        (*Node) = temp;
    }
    else{
        while(head_temp->next != nullptr){
            head_temp = head_temp->next;
        }
        head_temp->next = temp;
        temp->prev = head_temp;
    }
}

void insertionAtPosition(DoubleLinkedList** Node, int position, string data){
    DoubleLinkedList* temp = new DoubleLinkedList(data);
    DoubleLinkedList* headTemp = *Node;
    if(position == 0 || headTemp == nullptr){
        headTemp = temp;
        return;
    }

    for(int i = 0; i < position && headTemp->next != nullptr; i++){
        headTemp = headTemp->next;
    }
    temp->next = headTemp->next;
    temp->prev = headTemp;
    headTemp->next->prev = temp;
    headTemp->next = temp;
}

void deletionAtBeginning(DoubleLinkedList** Node){
    if(*Node == nullptr){
        cout << "No node" << endl;
        return;
    }
    DoubleLinkedList* temp = *Node;
    *Node = (*Node)->next;
    (*Node)->prev = nullptr;
    delete temp;
}

void deletionAtEnd(DoubleLinkedList** Node){
    if(*Node == nullptr){
        cout << "No node" << endl;
        return;
    }

    if((*Node)->next == nullptr){
        delete *Node;
        *Node = nullptr;
        return;
    }

    DoubleLinkedList* temp = *Node;

    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    temp->next->prev = nullptr;
    temp->next = nullptr;
    delete temp->next;
    
}

void deletionAtPosition(DoubleLinkedList** Node, int position){
    if(*Node == nullptr){
        cout<<"No node";
        return;
    }

    if(position==0){
        DoubleLinkedList * temp = *Node;
        *Node = (*Node)->next;
        (*Node)->prev = nullptr;
        delete temp;
        return;
    }

    DoubleLinkedList * temp = *Node;

    for(int i = 1; i<position && temp->next != nullptr; i++){
        temp = temp->next;
    }

    if(temp->next != nullptr){
        DoubleLinkedList * temp2 = temp->next;
        temp2->next->prev = temp;
        temp->next = temp->next->next;
        delete temp2;
    }
    else{
        cout << "No node";
        return;
    }
}

int main(){
    DoubleLinkedList* dll =  new DoubleLinkedList("D");
    insertionAtBeginning(&dll,"C");
    insertionAtBeginning(&dll,"B");
    traverse(dll);
    cout << search(dll,"D") << endl;
    cout<<"Length: "<<length(dll)<<endl;
    insertionAtBeginning(&dll,"A");
    insertionAtEnd(&dll,"F");
    insertionAtPosition(&dll, 3, "E");
    deletionAtBeginning(&dll);
    deletionAtEnd(&dll);
    deletionAtPosition(&dll, 1);
    traverse(dll);
    return 0;
}