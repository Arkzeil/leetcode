class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp[nums.size()];
        int maximum = nums[0];
        dp[0] = nums[0];

        for(int i = 1; i < nums.size(); i++){
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
            if(dp[i] > maximum)
                maximum = dp[i];
        }

        return maximum; //maximum is not necessary, return dp[nums.size()-1] should enough?
    }
};
