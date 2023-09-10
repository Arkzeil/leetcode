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
class Solution { //AVL tree, but can be achieved easily using the method here "https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/solutions/2406277/python-easily-understood-faster-than-86-less-than-83-recursion/"
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(!nums.size())
            return nullptr;

        int mid = nums.size() / 2;
        TreeNode *temp = new TreeNode(nums[mid]);

        vector<int> t = vector<int>(nums.begin(), nums.begin() + mid);
        temp->left = sortedArrayToBST(t);
        
        t = vector<int>(nums.begin() + mid + 1, nums.end());
        temp->right = sortedArrayToBST(t);

        return temp;
    }

};
