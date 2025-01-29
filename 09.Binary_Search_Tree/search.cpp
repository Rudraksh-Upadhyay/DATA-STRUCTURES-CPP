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


bool searchElement(Node* root, int target){
    //base cases
    if(root == NULL){
        return false;
    }

    if(root->data == target){
        return true;
    }

    if(target < root->data){
        return searchElement(root->left, target);
    }

    if(target > root->data){
        return searchElement(root->right, target);
    }


}





int main(){

    Node* root = NULL;
    createTree(root);

    //100 50 20 120 150 -1

    int target;
    cout<<"Enter the target value: "<<endl;
    cin >> target;

    bool ans = searchElement(root, target);

    cout << ans <<endl;


    return 0;
}