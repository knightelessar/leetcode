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
        ListNode temp;
        
        // swap temp node with the nextNode
        swap(*node, temp);
        swap(*node, *(temp.next));
        
        // release resources for nextNode
        // when temp goes out of scope
    }
};
