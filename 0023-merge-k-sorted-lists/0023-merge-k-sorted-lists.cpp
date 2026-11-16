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
    // Custom comparator for the priority queue to create a Min-Heap
    struct CompareNode {
        bool operator()(ListNode* const& a, ListNode* const& b) {
            return a->val > b->val; 
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Priority queue to store the active heads of the lists
        priority_queue<ListNode*, vector<ListNode*>, CompareNode> minHeap;
        
        // Step 1: Push the head of each non-empty linked list into the Min-Heap
        for (ListNode* head : lists) {
            if (head != nullptr) {
                minHeap.push(head);
            }
        }
        
        // Dummy node to easily build the resulting linked list
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        // Step 2: Extract the minimum node and push its next node back into the heap
        while (!minHeap.empty()) {
            // Get the node with the smallest value
            ListNode* smallest = minHeap.top();
            minHeap.pop();
            
            // Append it to our merged list
            tail->next = smallest;
            tail = tail->next;
            
            // If the extracted node has a next node, push it into the heap
            if (smallest->next != nullptr) {
                minHeap.push(smallest->next);
            }
        }
        
        return dummy.next;
    }
};