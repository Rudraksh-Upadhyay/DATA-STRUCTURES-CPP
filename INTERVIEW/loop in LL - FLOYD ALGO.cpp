/*
FLOYD'S CYCLE-DETECTION ALGORITHM

it uses two pointers, often called "tortoise" and "hare", that traverse the LL at difference speeds


*/


#include<bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    Node* next ;

    Node(int x) : val(x) , next(NULL) {}
};

bool detectCycle(Node* head){
    if(head == NULL || head->next == NULL){
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            return true; // cycle mil gaya
        }
    }
    return false; // no cycle...agar cycle hai ..toh..fast kabhi NULL nahi hoga
    //agar fast null ho gaya...means...LINEAR LL hai...hence NO CYCLE-> FALSE

}

//FIND THE STARTING NODE of the CYCLE
Node* detectCycleStart(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(slow && fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}

int main(){

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = head->next;

    if(detectCycle(head)){
        cout<<"CYCLE PRESENT"<<endl;
        Node* start = detectCycleStart(head);
        cout<<"STARTING NODE OF THE CYCLE IS : "<<start->val<<endl;
    }
    return 0;
}