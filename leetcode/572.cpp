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
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!flag){
            ini_subRoot = subRoot; //store original subroot for the comparision between subroot and subtree of root 
            flag = true;
        }
        
        if(root == nullptr && subRoot == nullptr) // both are nullptr
            return true;
        else if(root == nullptr || subRoot == nullptr) // one is nullptr, the other isn't
            return false;

        if(root->val != subRoot->val)// move last line of code to here, otherwise TLE in skewwed tree
            return isSubtree(root->left, ini_subRoot) || isSubtree(root->right, ini_subRoot);

        if(root->val == subRoot->val){
            if(isSubtree(root->left, subRoot->left) && isSubtree(root->right, subRoot->right)) //return only if true
                return true;
        }
        // this line won't be executed(is being moved up) but the function must return something
        return isSubtree(root->left, ini_subRoot) || isSubtree(root->right, subRoot); 
    }

private:
    TreeNode *ini_subRoot;
    bool flag = false;
};
