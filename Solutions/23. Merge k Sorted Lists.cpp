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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;           // return null pointer if list is empty
        ListNode* dummy = new ListNode();                // create dummy node to keep track of head of list
        ListNode* curr = findMinNode(lists);             // set curr to node with min value in list
        ListNode* curr2 = dummy;                         // set curr2 to head of list we want to return
        while (curr) {                                   // while min node in lists exists, we merge it into our list
            curr2->next = curr;
            curr2 = curr2->next;
            curr = findMinNode(lists);                   // find the next min node in lists
        }
        return dummy->next;                              // dummy->next is the head of the merged list
    }

private:
    ListNode* findMinNode(vector<ListNode*>& lists) {
        ListNode* minNode = nullptr;                     // initialize min node as null pointer
        int min = INT_MAX;                               // initialize min value as maximum int value
        int index;                                       // used to update lists after we have merged nodes
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) {                              // if the ith node in lists is non null
                if (lists[i]->val < min) {               // check if the value is less than min value
                    minNode = lists[i];                  // update min node
                    min = minNode->val;                  // update min value
                    index = i;                           // set index to index of min node
                }
            }
        }
        if (minNode) {                                   // if a min node was found we want to remove it from lists
            lists[index] = minNode->next;
        }
        return minNode;
    }
};
