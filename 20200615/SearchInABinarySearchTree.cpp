// Search in a Binary Search Tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        // Iteration start 15:23 - 15:26
        TreeNode *node = root;
        while (node)
        {
            if (val == node->val)
            {
                break;
            }
            else if (val < node->val)
            {
                node = node->left;
            }
            else
            {
                node = node->right;
            }
        }
        return node;
    }
};
