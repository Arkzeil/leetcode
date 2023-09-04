class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);

        if(n < 2)
            return 1;

        dp[0] = dp[1] = 1;
        
        for(int count = 2; count <= n; count++){
            dp[count] = dp[count-2] + dp[count-1];
        }

        return dp[n];
    }
};