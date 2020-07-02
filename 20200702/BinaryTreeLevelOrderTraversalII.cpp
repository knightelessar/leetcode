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
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        if (!root)
            return vector<vector<int>>{};
        vector<vector<int>> res;
        queue<TreeNode *> currQ;
        queue<TreeNode *> nextQ;
        nextQ.push(root);

        while (!nextQ.empty())
        {
            currQ = nextQ;
            queue<TreeNode *> emptyQ;
            nextQ = emptyQ;
            vector<int> list;
            while (!currQ.empty())
            {
                TreeNode *n = currQ.front();
                currQ.pop();
                list.push_back(n->val);
                if (n->left)
                    nextQ.push(n->left);
                if (n->right)
                    nextQ.push(n->right);
            }
            res.push_back(list);
        }

        reverse(begin(res), end(res));
        return res;
    }
};
