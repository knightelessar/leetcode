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
    // BFS queue with sentinel
    // 50 min looking at solution
public:
    vector<int> rightSideView(TreeNode *root)
    {
        queue<TreeNode *> q;
        vector<int> res;
        TreeNode *curr{root};
        TreeNode *prev{root};
        if (root)
        {
            q.push(root);
            q.push(nullptr);
        }

        while (!q.empty())
        {
            prev = curr;
            curr = q.front();
            q.pop();

            while (curr)
            {
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
                prev = curr;
                curr = q.front();
                q.pop();
            }

            // Now curr is a sentinel
            res.push_back(prev->val);

            if (!q.empty())
            {
                q.push(nullptr);
            }
        }
        return res;
    }
};
