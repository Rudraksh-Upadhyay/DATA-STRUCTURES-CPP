#include<iostream>

using namespace std;

class Node{
    public:

    Node* prev;
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};


void insertAtHead(int value, Node* &head, Node* &tail){
    //if LL is empty
    if(head == NULL && tail == NULL){
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        return;
    }

    //if ll is not empty
    Node* newNode = new Node(value);
    newNode->next = head;
    head->prev = newNode;
    head = head->prev;
    return;
}

void insertAtTail(int value, Node* &head, Node* &tail){
    //if LL is empty
    if(head == NULL && tail == NULL){
        return insertAtHead(value, head, tail);
    }

    //if ll is not empty
    Node* newNode = new Node(value);
    tail->next = newNode;
    newNode->prev = tail;
    tail = tail->next;
    return;
}

void insertAtPosition(int pos, int value, Node* &head, Node* &tail){
    if(pos == 0){
        return insertAtHead(value, head, tail);
    }
    if(pos == -1){
        return insertAtTail(value, head, tail);
    }

    else{
        int count = pos -1;

        Node* temp = head;
        while(count > 0){
            temp = temp->next;
            count--;
        }
        Node* newNode = new Node(value);
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
        return;
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

    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(10, head, tail);
    //10->null
    print(head);

    insertAtHead(20, head, tail);
    //20->10->null
    print(head);

    insertAtTail(30, head, tail);
    //20->10->30->null
    print(head);

//------------------------------------------------
    insertAtPosition(2, 100, head, tail);
    //20->10->100->30->null
    print(head);


    return 0;
}