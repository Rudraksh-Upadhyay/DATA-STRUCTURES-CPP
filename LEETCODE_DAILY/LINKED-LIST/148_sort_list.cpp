#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{
    private:
        ListNode* middleNode(ListNode* head){
            ListNode* slow = head;
            ListNode* fast = fast;

            while(fast != NULL && fast->next != NULL){
                slow = slow->next;
                fast = fast->next->next;
            }
            ListNode* mid = slow->next;
            slow->next = NULL;
            return mid;
        }
    public:
        ListNode* sortList(ListNode* head) {
            if(head == NULL || head->next == NULL){
                return head;
            }
            ListNode* mid  = middleNode(head);
            ListNode* left = sortList(head);
            ListNode* right = sortList(mid);
            return merge(left, right);
        }
};

int main(){



    return 0;
}