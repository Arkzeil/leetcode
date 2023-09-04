class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>;
        int half = nums.size() / 2;
        int mark = 0;

        sort(nums.begin(), nums.end());

        for(int count = 0; count < nums.size(); count++){
            if(nums[count] != mark){
                mark = nums[count];
                if(nums[count + half] == mark)
                    return mark;
            }
        }

        return -1;
    }
};