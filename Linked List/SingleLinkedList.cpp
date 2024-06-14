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

int main(){
    SingleLinkedList* a =  new SingleLinkedList("A");
    SingleLinkedList* b =  new SingleLinkedList("B");
    SingleLinkedList* c =  new SingleLinkedList("C");
    a->next = b;
    b->next = c;
    traverse(a);
    cout<<search(a,"D")<<endl;
    cout<<"Length: "<<length(a)<<endl;
    insertionAtBeginning(&a,"D");
    insertionAtEnd(&a,"D");
    traverse(a);
    return 0;
}