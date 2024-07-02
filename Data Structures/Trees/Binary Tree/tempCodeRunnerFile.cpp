
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
        Node* temp = q.front();
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
        deletionDeep(&head, temp);
    }
}
