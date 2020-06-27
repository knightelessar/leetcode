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
    // start 10:30 - 11:46
    // start 13:22 - 14:24
public:
    int sumNumbers(TreeNode* root)
    {
        vector<int> lvl(1, 0);
        return dfs(root, lvl);
    }

    int dfs(TreeNode* root, vector<int> &lvl)
    {
        if (!root)
        {
            lvl[0] = 0;
            return 0;
        }
        if (root && !root->left && !root->right)
        {
            // Is leaf node
            lvl[0] = root->val;
            lvl.push_back(1);
            return root->val;
        }

        vector<int> lvlLeft(1,0), lvlRight(1,0);
        int leftSum{0}, rightSum{0}, addCurr{0};
        leftSum = dfs(root->left, lvlLeft);
        rightSum = dfs(root->right, lvlRight);
        assert(lvl.size() == 1);
        lvl.push_back(0);
        for (size_t i{1}, j{1}, k{1}; i < max(lvlLeft.size(), lvlRight.size()); ++i)
        {
            int x{0};
            if (j < lvlLeft.size())
            {
                x = x + lvlLeft[j];
                j++;
            }
            if (k < lvlRight.size())
            {
                x = x + lvlRight[k];
                k++;
            }
            lvl.push_back(x);
            addCurr = addCurr + pow(10, i) * x * root->val;
        }
        lvl[0] = leftSum + rightSum + addCurr;
        return lvl[0];
    }
};
