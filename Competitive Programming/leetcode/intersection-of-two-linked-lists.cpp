/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *intersection_point=nullptr;
        ListNode *ptr1 = headA;
        ListNode *ptr2 = headB;
        stack<ListNode*> stack_1;
        stack<ListNode*> stack_2;

        while(ptr1){
            stack_1.push(ptr1);
            ptr1 = ptr1->next;
        }
        while(ptr2){
            stack_2.push(ptr2);
            ptr2 = ptr2->next;
        }

        while(!stack_1.empty() && !stack_2.empty() && stack_1.top() == stack_2.top()){
            intersection_point = stack_1.top();
            stack_1.pop();
            stack_2.pop();
        }

        return intersection_point;
    }
};