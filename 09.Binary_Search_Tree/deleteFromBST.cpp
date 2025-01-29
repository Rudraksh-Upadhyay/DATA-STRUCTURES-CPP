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


class Solution{
    public:
        int getMax(Node* root){
            if(root == NULL){
                return -1;
            }
            while(root->right != NULL){
                root=  root->right;
            }
            return root->data;
        }

        Node* deleteNode(Node* root, int target){
            if(root == NULL){
                return NULL;
            }

            if(root->data == target){

                //4 cases 

                //1. no child
                if(root->left == NULL && root->right == NULL){
                    delete root;
                    return NULL;
                }

                //2. only left child
                if(root->left != NULL && root->right == NULL){
                    Node* temp = root->left;
                    root->left =NULL;
                    delete root;
                    return temp;
                }

                //3. only right child
                if(root->left == NULL && root->right != NULL){
                    Node* temp = root->right;
                    root->right = NULL;
                    delete root;
                    return temp;
                }

                //4. both child
                if(root->left != NULL && root->right != NULL){
                    int max = getMax(root->left);
                    root->data = max;
                    root->left = deleteNode(root->left, max);
                    return root;
                }

            }
            else{
                if(root->data < target){
                    root->right = deleteNode(root->right, target);
                }
                else{
                    root->left = deleteNode(root->left, target);
                }
            }

            return root;
        }
};

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

    int target;
    cout << "Enter the target value to be deleted:"<<endl;
    cin >>target;

    Solution sol = Solution();

    root = sol.deleteNode(root, target);


    levelOrderTraversal(root);

    return 0;
}