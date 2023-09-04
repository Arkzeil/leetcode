class Solution {
public:
    int search(vector<int>& nums, int target) { 
        size_t const mid = nums.size() / 2;
        int mid_index = (int)mid;
        int ans = -1;

        if(nums[mid_index] == target)
            return mid_index;
        if(mid == 0)
            return -1;

        vector<int> L_half(nums.begin(), nums.begin() + mid);
        vector<int> R_half(nums.begin() + mid, nums.end());
        if(nums[mid_index] < target)
            ans = mid_index + search(R_half, target);
        else
            ans = search(L_half, target);

        if(ans < 0)
            return -1;

        if(ans < nums.size() && nums[ans] == target)
            return ans;
        return -1;
    }
};