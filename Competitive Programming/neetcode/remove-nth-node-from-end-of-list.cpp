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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow = nullptr;
        ListNode *fast = head;
        while(n--){
            fast = fast->next;
        }
        if(!fast){
            ListNode *ptr = head;
            head = head->next;
            delete ptr;
            return head;
        }
        slow = head;
        fast = fast->next;
        while(fast){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode *ptr = slow->next;
        slow->next = slow->next->next;
        delete ptr;
        return head;

    }
};