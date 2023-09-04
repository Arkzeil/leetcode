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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *top = new ListNode(-1);
        ListNode *merged = top;
        while(1){
            if(list1 == nullptr){
                if(merged == top)//one list is empty, top would no be the same as merged
                    return list2;

                if(list2 != nullptr){
                    merged->val = list2->val;
                    merged->next = list2->next;
                }
                else
                    merged = nullptr;

                if(top->val == -1) //all empty
                    return nullptr;
                return top;
            }
            else if(list2 == nullptr){
                if(merged == top)
                    return list1;

                if(list1 != nullptr){
                    merged->val = list1->val;
                    merged->next = list1->next;
                }
                else
                    merged = nullptr;

                if(top->val == -1)
                    return nullptr;
                return top;
            }

            if(list1->val <= list2->val){
                merged->val = list1->val;
                list1 = list1->next;
            }
            else{
                merged->val = list2->val;
                list2 = list2->next;
            }
            merged->next = new ListNode();
            merged = merged->next;
        }
    }
};