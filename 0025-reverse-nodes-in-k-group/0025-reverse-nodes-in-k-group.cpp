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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) return head;
        
        // Dummy node to simplify edge cases at the head
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroupTail = &dummy;
        
        while (true) {
            // Find the k-th node from the current group start
            ListNode* kth = prevGroupTail;
            for (int i = 0; i < k && kth != nullptr; ++i) {
                kth = kth->next;
            }
            
            // If we have fewer than k nodes left, we are done
            if (kth == nullptr) {
                break;
            }
            
            // Nodes to track for the reversal
            ListNode* nextGroupHead = kth->next;
            ListNode* prev = nextGroupHead;
            ListNode* curr = prevGroupTail->next;
            
            // Reverse the current group of k nodes
            for (int i = 0; i < k; ++i) {
                ListNode* nextTemp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextTemp;
            }
            
            // Reconnect the reversed group to the rest of the list
            ListNode* tail = prevGroupTail->next; // The original head is now the tail
            prevGroupTail->next = kth;            // kth is the new head of this group
            prevGroupTail = tail;                 // Move prevGroupTail up for the next iteration
        }
        
        return dummy.next;
    }
};