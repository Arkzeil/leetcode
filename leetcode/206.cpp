/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *LastNode = nullptr;

    ListNode* reverseList(ListNode* head) {
        if(head == nullptr)
            return LastNode;

        ListNode *temp = head->next;
        ListNode *t2;
        head->next = LastNode;

        if(temp == nullptr)
            return head;
        
        LastNode = temp;
        t2 = temp->next;
        temp->next = head;

        return reverseList(t2);
    }

};