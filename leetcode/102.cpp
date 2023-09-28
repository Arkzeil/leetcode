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
    vector<vector<int>> levelOrder(TreeNode* root) {
        traversal(root, 0);
        ans.resize(max_h);
        return ans;
    }

    void traversal(TreeNode *root, int h){
        if(root == nullptr){
            if(max_h < h) //Since it's starting from 0, and the resize is asking for amount(starting from 1), so it's not h-1
                max_h = h;
            return;
        }
        else{
            ans[h].push_back(root->val);
            traversal(root->left, h + 1);
            traversal(root->right, h + 1);
        }
    }

private:
    vector<vector<int>> ans = vector<vector<int>>(2000);
    int max_h = 0;
};
