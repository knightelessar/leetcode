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
    size_t preIdx;
    vector<int> preorder;
    unordered_map<int, int> inMap; // val -> inorder array index (ascending array)

    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        this->preorder = preorder;
        vector<int> inorder(preorder);
        sort(begin(inorder), end(inorder));
        size_t i{0};
        for (auto x: inorder)
        {
            inMap[x] = i++;
        }
        return constructNodes(0, inorder.size());
    }
    
    TreeNode* constructNodes(size_t inLeft, size_t inRight)
    {
        if (inLeft == inRight)
        {
            return nullptr;
        }
        
        auto val = preorder[preIdx++];
        auto root = new TreeNode(val);
        auto inIdx = inMap[val];
        root->left = constructNodes(inLeft, inIdx);
        root->right = constructNodes(inIdx + 1, inRight);
        return root;
    }
};
