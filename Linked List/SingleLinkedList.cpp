#include<iostream>
using namespace std;

class SingleLinkedList{
    public:
    string data;
    SingleLinkedList* next;

    public:
    SingleLinkedList(int data1){
        data = data1;
        next = nullptr;
    }
};

bool search(SingleLinkedList)

void traverse(SingleLinkedList* node){
    while(node!=nullptr){
        cout<< node->data<<endl;
        node = node->next;
    }
}

int main(){
    SingleLinkedList* a =  new SingleLinkedList('A');
    SingleLinkedList* b =  new SingleLinkedList('B');
    SingleLinkedList* c =  new SingleLinkedList('C');
    a->next = b;
    b->next = c;
    traverse(a);
    return 0;
}