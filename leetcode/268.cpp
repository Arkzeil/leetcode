class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int temp[n + 1];
        fill_n(temp, n+1, 0);
        
        for(int i = 0; i < n; i++)
            temp[nums[i]] = 1;
        for(int i = 0; i <= n; i++){
            if(!temp[i])
                return i;
        }

        return -1;
    }
};
