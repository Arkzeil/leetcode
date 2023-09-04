class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> num_mapping;

        for(int i = 0; i < nums.size(); i++){
            if(num_mapping.count(nums[i]))
                return true;
            num_mapping[nums[i]]++;
        }

        return false;
    }
};