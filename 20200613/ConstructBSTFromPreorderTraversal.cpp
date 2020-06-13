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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.size() == 0) return nullptr;
        stack<TreeNode*> myStack;
        auto root = new TreeNode(preorder[0]);
        myStack.push(root);
        
        for (size_t i{1}; i < preorder.size(); ++i)
        {
            auto root = myStack.top();
            auto child = new TreeNode(preorder[i]);
            
            if (child->val < root->val) {
                root->left = child;
                myStack.push(child);
                continue;
            }
            
            while (!myStack.empty() && child->val > myStack.top()->val)
            {
                root = myStack.top();
                myStack.pop();
            }
            
            if (child->val > root->val)
            {
                root->right = child;
                myStack.push(child);
            }
        }
        return root;
    }
};
