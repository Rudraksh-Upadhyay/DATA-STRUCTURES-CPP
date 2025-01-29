#include<iostream>
#include<vector>

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

        void  storeInorder(Node* root, vector<int> &inorder){
            if(root == NULL){
                return ;
            }

            storeInorder(root->left, inorder);
            inorder.push_back(root->data);
            storeInorder(root->right, inorder);

        }

        int kthSmallest(Node* root, int k){
            vector<int> inorder;
            storeInorder(root, inorder);
            return inorder[k-1];
        }
};

int main(){

    Node* root = NULL;
    createTree(root);

    Solution sol = Solution();

    int k ;
    cout <<"enter the kth smallest element->"<<endl;
    cin >> k;

    cout << sol.kthSmallest(root,k)<<endl;

    return 0;
}