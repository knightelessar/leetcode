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
class Solution
    // Looking at solution 19 min
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        if (!root)
            return vector<int>{};
        vector<int> res;
        queue<TreeNode *> q;
        TreeNode *curr{nullptr};
        size_t levelSize{0};
        q.push(root);
        while (!q.empty())
        {
            levelSize = q.size();
            for (size_t i{0}; i < levelSize; ++i)
            {
                curr = q.front();
                q.pop();
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
                if (i == levelSize - 1)
                {
                    res.push_back(curr->val);
                }
            }
        }
        return res;
    }
};
