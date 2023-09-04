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
    int index = 0;
    ListNode *ans = nullptr;
    ListNode* middleNode(ListNode* head) {
        if(head == nullptr){
            return nullptr;
        }
        int cur = index;
        index++;
        middleNode(head->next);
        if(index/2 == cur)
            ans = head;
        return ans;
    }
};