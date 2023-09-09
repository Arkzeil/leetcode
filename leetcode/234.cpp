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
    bool isPalindrome(ListNode* head) {
        int array[100001];
        int len = 0;

        while(head != nullptr){
            array[len] = head->val;
            len++;
            head = head->next;
        }

        for(int i = 0, j = len -1; i <= j; i++, j--)
            if(array[i] != array[j])
                return false;

        return true;
    }
};
