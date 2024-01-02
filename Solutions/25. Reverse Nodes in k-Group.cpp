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
        queue<ListNode*> q;                           // initialize queue
        ListNode* curr = head;                        // set current pointer to head of linked list
        for (int i = 0; i < k; i++) {                 // push k nodes onto the queue for reversal
            if (!curr) {                              // if current does not exist, list is length one
                return head;                          // simply return head
            }
            q.push(curr);                             // push every node onto queue
            curr = curr->next;                        // move current pointer to next node in linked list
        }
        ListNode* after = reverseKGroup(curr, k);     // create a temporary pointer to the node returned by recursive call
        while (!q.empty()) {                          
            ListNode* front = q.front();
            front->next = after;                      // point the node at the front of queue to node that comes after it
            after = front;                            // set the "after" pointer to point to the current node
            q.pop();                                  // don't forget to pop from the queue
        }
        return after;                                 // "after" is now the head of the linked list, we simply return it
    }
};
