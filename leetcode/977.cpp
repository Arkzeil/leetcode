class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        int l, r;
        int index = 0;

        for(int i = 0; i < nums.size(); i++){
            r = i;
            l = r - 1;
            
            if(nums[i] >= 0)
                break;
            
        }

        for(int i = 0; i < nums.size(); i++)
            nums[i] *= nums[i];

        while(1){
            
            if(l < 0){
                for(int i = r; i < nums.size(); i++, index++)
                    ans[index] = nums[i];
                break;
            }
            else if(r >= nums.size()){
                for(int i = l; i >= 0; i--, index++)
                    ans[index] = nums[i];
                
                break;
            }

            if(nums[l] < nums[r]){
                ans[index] = nums[l];
                l--;
            }
            else{
                ans[index] = nums[r];
                r++;
            }

            index++;
        }

        return ans;
    }
};
