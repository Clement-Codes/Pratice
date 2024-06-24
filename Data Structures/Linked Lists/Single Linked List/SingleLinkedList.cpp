#include<iostream>
using namespace std;

class SingleLinkedList{
    public:
    string data;
    SingleLinkedList* next;

    public:
    SingleLinkedList(string data1){
        data = data1;
        next = nullptr;
    }
};

bool search(SingleLinkedList* node, string target){
    while(node->next != nullptr){
        if(node->data == target){
            return true;
        }
        node = node->next;
    }
    return false;
}

void traverse(SingleLinkedList* node){
    while(node!=nullptr){
        cout<< node->data<<endl;
        node = node->next;
    }
}

int length (SingleLinkedList* node){
    int temp = 0;
    while (node->next != nullptr)
    {
        temp+=1;
        node=node->next;
    }
    return temp;
}

void insertionAtBeginning(SingleLinkedList** head, string data){
    SingleLinkedList* temp = new SingleLinkedList(data);
    temp->next = *head;
    *head = temp;
}

void insertionAtEnd(SingleLinkedList** Node, string data){
    SingleLinkedList* temp = new SingleLinkedList(data);
    SingleLinkedList* head_temp = *Node;
    if ((*Node) == nullptr){
        (*Node) = temp;
    }
    else{
        while(head_temp->next != nullptr){
            head_temp = head_temp->next;
        }
        head_temp->next = temp;
    }
}

void insertionAtPosition(SingleLinkedList** Node, int position, string data){
    SingleLinkedList* temp = new SingleLinkedList(data);
    SingleLinkedList* headTemp = *Node;
    if(position == 0 || headTemp == nullptr){
        temp->next = headTemp;
        headTemp = temp;
        return;
    }

    for(int i = 0; i < position && headTemp->next != nullptr; i++){
        headTemp = headTemp->next;
    }
    temp->next = headTemp->next;
    headTemp->next = temp;
}

void deletionAtBeginning(SingleLinkedList** Node){
    if(*Node == nullptr){
        cout << "No node" << endl;
        return;
    }
    SingleLinkedList* temp = *Node;
    *Node = (*Node)->next;
    delete temp;
}

void deletionAtEnd(SingleLinkedList** Node){
    if(*Node == nullptr){
        cout << "No node" << endl;
        return;
    }

    if((*Node)->next == nullptr){
        delete *Node;
        *Node = nullptr;
        return;
    }

    SingleLinkedList* temp = *Node;

    while(temp->next->next != nullptr){
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
}

void deletionAtPosition(SingleLinkedList** Node, int position){
    if(*Node == nullptr){
        cout<<"No node";
        return;
    }

    if(position==0){
        SingleLinkedList * temp = *Node;
        *Node = (*Node)->next;
        delete temp;
        return;
    }

    SingleLinkedList * temp = *Node;

    for(int i = 1; i<position && temp->next != nullptr; i++){
        temp = temp->next;
    }

    if(temp->next != nullptr){
        SingleLinkedList * temp2 = temp->next;
        temp->next = temp->next->next;
        delete temp2;
    }
    else{
        cout << "No node";
        return;
    }
}

int main(){
    SingleLinkedList* a =  new SingleLinkedList("B");
    SingleLinkedList* b =  new SingleLinkedList("C");
    SingleLinkedList* c =  new SingleLinkedList("D");
    a->next = b;
    b->next = c;
    traverse(a);
    cout<<search(a,"D")<<endl;
    cout<<"Length: "<<length(a)<<endl;
    insertionAtBeginning(&a,"A");
    insertionAtEnd(&a,"F");
    insertionAtPosition(&a, 3, "E");
    // deletionAtBeginning(&a);
    // deletionAtEnd(&a);
    deletionAtPosition(&a, 1);
    traverse(a);
    return 0;
}