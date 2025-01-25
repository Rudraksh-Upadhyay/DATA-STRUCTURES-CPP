#include<iostream>

using namespace std;

class Node{
    public:

    int data;
    Node* next;

    //constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

};

//RETURNS HEAD OF THE LINKED LIST
Node* insertAtHead(int value, Node* &head, Node* &tail){
    //LL is empty
    //we are creating first node of linked list
    if(head == NULL && tail == NULL){
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
    }
    else{
    //LL is not empty
    //we are creating a new node and uske next ko head se connect
    //kr rhe hai
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    return head;
}

Node* insertAtTail(int value, Node* &head, Node* &tail){
    //LL is empty
    //we will create first node of linked list
    if(head == NULL && tail == NULL){
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;

    }

    //LL is not empty
    //we will create a new node and uske next ko NULL se connect
    //kr rhe hai
    else{
        Node* newNode = new Node(value);
        tail->next = newNode;
        tail = newNode;
    }
    return head;
}

Node* insertAtPosition(int pos, int value, Node* &head, Node* &tail){
    if(pos == 0){
        return insertAtHead(value, head, tail);
    }
    else if (pos == -1)
    {
        return insertAtTail(value, head, tail);
    }

    int count = pos-1;
    Node* temp = head;
    while(count > 0){
        temp = temp->next;
        count--;
    }
    Node* newNode = new Node(value);
    newNode->next = temp->next;
    temp->next = newNode;

    return head;

}


//LINEAR SEARCH
bool search(Node* head, int target){
    Node* temp = head;

    while(temp != NULL){
        if(temp->data == target){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void deleteNode(int pos, Node* &head, Node* &tail){
    //empty LL
    if(head == NULL && tail == NULL){
        cout << "LL is empty" << endl;
        return;
    }

    //single node
    if(head == tail){
        Node* temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return;
    }

    else{
        //multiple nodes inside LL

        if(pos == 0){
            Node* temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }

        else if(pos == -1){
            Node* temp = head;
            while(temp->next->next != NULL){
                temp = temp->next;
            }
            Node* temp2 = temp->next;
            temp->next = NULL;
            tail = temp;
            delete temp2;
        }

        else{
            Node* temp = head;
            int count = pos-1;
            while(count > 0){
                temp = temp->next;
                count--;
            }

            Node* temp2 = temp->next;

            temp->next = temp2->next;
            temp2->next = NULL;
            delete temp2;
        }
    }
}

void print(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main(){

//initialization
    //static
    // Node first ;

    //dynamic
    // Node* second = new Node(10);
    // cout << second->data <<endl;


    Node* head = NULL;
    Node* tail = NULL;

    head = insertAtHead(10, head, tail);
    //10->null

    head = insertAtHead(20, head, tail);
    //20->10->null

    head = insertAtHead(30, head, tail);
    //30->20->10->null

    head = insertAtHead(40, head, tail);
    //40->30->20->10->null

//-------------------------------------------------------------.//
    head = insertAtTail(50, head, tail);
    //40->30->20->10->50->null

    head = insertAtTail(60, head, tail);
    //40->30->20->10->50->60->null

//-------------------------------------------------------------.//
    head = insertAtPosition(2, 100, head, tail);
    //40->30->100->20->10->50->60->null

    head = insertAtPosition(0, 200, head, tail);
    //200->40->30->100->20->10->50->60->null

//-------------------------------------------------------------.//

    //DELETION

    print(head);

    deleteNode(0, head, tail);
    print(head);

    deleteNode(-1, head, tail);
    print(head);

    deleteNode(3, head, tail);
    print(head);


    bool ans = search(head, 30);
    cout << ans << endl;
    

    return 0;
}