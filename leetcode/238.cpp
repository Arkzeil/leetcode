class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> left(len + 1), right(len + 1), ans(len);
        left[0] = 1;
        right[0] = 1;

        for(int count = 1; count <= len; count++){ //store the leftmost and rightmost 'count' numbers' product
            left[count] = nums[count - 1] * left[count - 1];
            right[count] = nums[len - count] * right[count - 1];
        }
        
        for(int count = 0; count < len; count++)
            ans[count] = left[count] * right[len - count - 1];

        return ans;
    }
};
