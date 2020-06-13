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
    size_t preIdx;
    vector<int> preorder;
    unordered_map<int, size_t> map; // val: inorder idx
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        this->preorder = preorder;
        vector<int> inorder = preorder;
        sort(begin(inorder), end(inorder));
        for (size_t i{0}; i < inorder.size(); ++i)
        {
            map[inorder[i]] = i;
        }
        preIdx = 0;
        return divideAndConstruct(0, inorder.size());
    }
    
    // [inLeft, inRight)
    TreeNode* divideAndConstruct(size_t inLeft, size_t inRight)
    {
        if (inLeft == inRight) return nullptr;
        
        auto val = preorder[preIdx++];
        auto root = new TreeNode(val);
        
        root->left = divideAndConstruct(inLeft, map[val]);
        root->right= divideAndConstruct(map[val] + 1, inRight);
        return root;
    }
};
