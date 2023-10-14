class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount + 1]; //store the min coin amount when amount = 1,2,3, ...
        dp[0] = 0;

        if(!amount)
            return 0;

        for(int count = 1; count <= amount; count++)
            dp[count] = -1;
        
        sort(coins.begin(), coins.end()); // not sure if it's needed

        for(int count = 0; count < coins.size() ; count++){
            if(coins[count] >= amount){
                if(coins[count] == amount)
                    return 1;
                continue;
            }
            
            for(int i = 1; i <= amount; i++){ // using this coin to try to minimize the amounts of previous. Since previous are made up of smaller ones
                if((i - coins[count]) >= 0){
                    if(dp[i - coins[count]] == -1){
                        if(!(i % coins[count]) ) //check if i value can be achieved using current coins
                            dp[i] = i / coins[count];
                    }
                    else{
                        if(dp[i] >= 0) // to prevent -1
                            dp[i] = min(dp[i], dp[i - coins[count]] + 1);
                        else
                            dp[i] = dp[i - coins[count]] + 1;
                    }
                }
            }
        }

        return dp[amount];
    }
};
