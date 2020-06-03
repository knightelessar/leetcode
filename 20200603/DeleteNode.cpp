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
    void deleteNode(ListNode* node) {
        // prevNode -> node, we cannot change prevNode
        
        // get pointer to nextNode
        ListNode* nextNode = node->next;
        
        // make node the same as nextNode
        node->val = nextNode->val;
        node->next = nextNode->next;
        
        // release resources for nextNode
        delete nextNode;
    }
};
