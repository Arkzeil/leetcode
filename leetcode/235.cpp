/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *ans;

        if(p->val <= root->val && q->val <= root->val){ //both on the left(including root)
            if(p->val == root->val || q-> val == root->val) //one is root
                return (new TreeNode(root->val) );
            else 
                ans = lowestCommonAncestor(root->left, p, q);
        }
        else if(p->val > root->val && q->val > root->val){ //both on right
            ans = lowestCommonAncestor(root->right, p, q);
        }
        else{ //one left, one right
            return (new TreeNode(root->val) );
        }

        return ans;
    }
};