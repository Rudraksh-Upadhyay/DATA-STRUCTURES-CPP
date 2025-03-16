#include<bits/stdc++.h>

using namespace std;

struct ListNode{

    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{

    public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        ListNode* temp = l1;
        int num1 = 0;
        int x = 1;

        while(temp!= NULL){
            num1 += temp->val * x;
            x *= 10;
            temp = temp->next;
        }

        temp = l2;
        int num2 = 0;
        x = 1;
        while(temp!= NULL){
            num2 += temp->val * x;
            x *= 10;
            temp = temp->next;
        }

        int num = num1 + num2;

        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(num >0){
            int digit = num % 10;
            ListNode* node = new ListNode(digit);
            if(head == NULL){
                head = node;
                tail = node;
            }
            else{
                tail->next = node;
                tail = tail->next;
            }
            num /= 10;
        }
        return head;
    }
};

int main(){



    return 0;
}