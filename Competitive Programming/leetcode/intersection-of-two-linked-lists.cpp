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
        ListNode *intersection_point = headA;
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

        while(!stack_1.empty() && !stack_2.empty()){
            ptr1 = stack_1.top();
            ptr2 = stack_2.top();
            stack_1.pop();
            stack_2.pop();
            if(ptr1!=ptr2){
                return ptr1->next;
            }
        }

        if(!stack_1.empty()){
            intersection_point = stack_1.top()->next;
        }
        if(!stack_2.empty()){
            intersection_point = stack_2.top()->next;
        }
        
        return intersection_point;
    }
};