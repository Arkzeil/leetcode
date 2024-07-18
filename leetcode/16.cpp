class Solution {
public:
    // greedy?
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = nums[0] + nums[1] + nums[2];
        int dif = abs(target - ans);
        int arr[3] = {nums[0], nums[1], nums[2]};

        for(int i = 3; i < nums.size(); i++){
            int min = INT_MAX;
            int pos = -1;
            
            for(int j = 0; j < 3; j++){
                int temp = ans + nums[i] - arr[j];
                if(abs(target - temp) < min){
                    min = abs(target - temp);
                    pos = j;
                }
            }

            if(min < dif){
                ans = ans + nums[i] - arr[pos];
                dif = min;
                arr[pos] = nums[i];
            }
        }

        return ans;
    }
};