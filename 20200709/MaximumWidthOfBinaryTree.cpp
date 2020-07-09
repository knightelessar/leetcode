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
    // Event: new daily challenge 662. Maximum Width of Binary Tree brute force BFS algorithm
    // Time spent: 15m

    // Event: code brute force 662 Time Limit Exceeded
    // Time spent: 15m

    // Event: read 662 Same level node indexing solution
    // Time spent: 12m

    // Event: adapt my two queue solution, and debug unsigned long long int problem
    // Time spent: 30m

public:
    int widthOfBinaryTree(TreeNode *root)
    {
        queue<pair<TreeNode *, unsigned long long int>> prevQ;
        queue<pair<TreeNode *, unsigned long long int>> currQ;

        currQ.push(make_pair(root, 0));
        unsigned long long int maxWidth{0};
        while (!currQ.empty())
        {
            prevQ = currQ;
            while (!currQ.empty())
                currQ.pop();
            unsigned long long int width{0};
            int N = prevQ.size();
            int curr{0};
            int i{0}, j{0};
            while (!prevQ.empty())
            {
                auto n = prevQ.front();
                prevQ.pop();
                if (curr == 0)
                {
                    i = n.second;
                }
                if (curr == N - 1)
                {
                    j = n.second;
                }
                if (n.first->left)
                {
                    currQ.push(make_pair(n.first->left, 2 * n.second));
                }
                if (n.first->right)
                {
                    currQ.push(make_pair(n.first->right, 2 * n.second + 1));
                }
                ++curr;
            }
            width = j - i + 1;
            maxWidth = max(maxWidth, width);
        }
        return static_cast<int>(maxWidth);
    }
};
