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
    vector<int> preorder;
    size_t preIdx;
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        this->preorder = preorder;
        preIdx = 0;
        return divideAndConstruct(numeric_limits<int>::min(), numeric_limits<int>::max());
    }
    
    TreeNode* divideAndConstruct(int lower, int upper)
    {
        if (preIdx == preorder.size())
        {
            return nullptr;
        }
        auto val = preorder[preIdx];
        if (val < lower || val > upper)
        {
            return nullptr;
        }
        preIdx++;
        auto root = new TreeNode(val);
        root->left = divideAndConstruct(lower, val);
        root->right = divideAndConstruct(val, upper);
        return root;
    }
};
