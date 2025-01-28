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

Node* createTree(){
    cout <<"Enter the Node value->"<<endl;
    int value; 
    cin >>value;

    if(value == -1){
        return NULL;

    }

    else{
        Node* root = new Node(value);//yeh meine ek case solve kiya


        //baaki recurrsion krega

        cout << "left child->"<<endl;
        root->left = createTree();
        

        cout <<"right child->"<<endl;
        root->right =  createTree();


        return root;    
    }

}


int main(){


    Node* root;

    root = createTree();

    cout << "printing tree->" << root->data <<endl;
    return 0;
}