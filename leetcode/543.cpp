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
    int diameterOfBinaryTree(TreeNode* root) {
        getheight(root);
        return getDia(root, 0);
    }

private:
    int getheight(TreeNode* root){ //change val to the height sum of Lleaf and Rleaf
        if(root == nullptr)
            return 0;

        int LH = getheight(root->left);
        int RH = getheight(root->right);

        root->val = LH + RH; 

        return 1 + max(LH, RH);
    }

    int getDia(TreeNode *root, int maximum){
        if(root == nullptr)
            return maximum;

        int temp = max(getDia(root->left, maximum), getDia(root->right, maximum));

        return max(temp, root->val);
    }
};