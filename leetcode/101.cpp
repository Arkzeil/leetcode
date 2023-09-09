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
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)
            return true;
        
        return comp(root->left, root->right);
    }

    bool comp(TreeNode *l, TreeNode *r){
        if(l == r)
            return true;
        if(l == nullptr || r == nullptr || l->val != r->val)
            return false;
        
        return comp(l->left, r->right) && comp(l->right, r->left);
    }
};
