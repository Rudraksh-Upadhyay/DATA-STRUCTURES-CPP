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

Node* builtBST(int value, Node* root){
    if(root == NULL){
        root = new Node(value);
        return root;
    }

    else{
        if(value < root->data){
            root->left = builtBST(value, root->left);
        }
        else{
            root->right = builtBST(value, root->right);
        }
    }
    return root;
}

void createTree(Node* &root){
    cout<<"Enter the value for Node:"<<endl;
    int val;
    cin >> val;

    while(val != -1){
        root = builtBST(val, root);
        cout<<"Enter the value for Node:"<<endl;
        cin >> val;
    }    
}


int getMin(Node* root){
    if(root == NULL){
        return 0;
    }

    while(root->left != NULL){
        root = root->left;
    }

    return root->data;
}

int getMax(Node* root){
    if(root == NULL){
        return 0;

    }

    while(root->right != NULL){
        root = root->right;
    }
    return root->data;
}

int main(){

    return 0;
}