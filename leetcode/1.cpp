class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> index(nums.size()); //build an vector to get the index of answer without changing the indices of original vector while sorting
        iota(index.begin(), index.end(), 0); //fill the vector with 0,1,2,3...
        stable_sort(index.begin(), index.end(), [&nums](int x, int y){return nums[x] < nums[y];});//get original index of sorted vector
        stable_sort(nums.begin(), nums.end());
        
        for(int count = 0; count < nums.size(); count++){
            int sec_ans;
            int remaining = target - nums[count];
            vector<int>::iterator it = find(nums.begin(), nums.end(), remaining);
            if(it != nums.end()){
                sec_ans = distance(nums.begin(), it);
                if(count != sec_ans)
                    return vector<int>{index[count], index[sec_ans]};
            }
        }
        return vector<int>{};
    }
};