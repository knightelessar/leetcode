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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        
        // Invert the left child
        TreeNode* left = invertTree(root->left);
        
        // Invert the right child
        TreeNode* right = invertTree(root->right);
        
        // Swap the children under self node
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        
        return root;
    }
};