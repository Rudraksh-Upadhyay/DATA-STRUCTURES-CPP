#include<iostream>
#include<string>

using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int value){
        data = value;
        next = NULL;
    }
};


Node* reverseLL(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

void LLtoString(Node* head, string &s){
    Node* temp = head;
    // string s;

    while(temp != NULL){
        string c = to_string(temp->data);
        // s.push_back(c);
        s += c;
        temp = temp->next;
    }
}

void printLL(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL " <<endl;
}

int main(){

    //LL->  1 -> 2 -> 3 -> NULL

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    printLL(head);

    head = reverseLL(head);

    printLL(head);

    string num1;

    LLtoString(head, num1);

    int num = stoi(num1);
    cout << num << endl;


    return 0;
}