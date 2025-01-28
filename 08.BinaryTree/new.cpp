#include<iostream>

using namespace std;

class Node{

    public:

        int data;
        Node* left;
        Node* right;

        Node(int value){
            this->data = value;
            this->left = NULL;
            this->right = NULL;
        }     

};

Node* createNode(int size, int flag){

    if(size == -1){
        return NULL;
    }
    int value;
    cin >>value;

    Node* root = new Node(value);

    if(flag == 0){
        return root;
    }

    root->left=  createNode(size-1, 0);
    root->right = createNode(size-1, 0);

    return root;
}


int main(){

    Node* root ;
    root = createNode(3, 1);

    cout <<"created"<<endl;

    return 0;
}