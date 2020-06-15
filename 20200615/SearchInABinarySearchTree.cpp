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
        // start 15:05 - 15:18
        if (!root)
        {
            return nullptr;
        }

        if (val == root->val)
        {
            return root;
        }
        else if (val < root->val)
        {
            return searchBST(root->left, val);
        }
        else // val > root->val
        {
            return searchBST(root->right, val);
        }
    }
};
