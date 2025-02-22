#include<iostream>
#include<queue>

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


void levelOrderTraversal(Node* root){
    queue<Node*> q;

    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* front = q.front();
        q.pop();

        if(front == NULL){
            cout <<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << front->data << " ";
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
        }
    }
}





int main(){

    Node* root = NULL;

    createTree(root);

    levelOrderTraversal(root);


    return 0;
}