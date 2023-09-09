class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int count = 0;

        //sort(nums.begin(), nums.end(), [](int x, int y){return y == 0;});
        for(int index = 0; index < nums.size(); index++){
            if(!nums[index]){
                nums.erase(nums.begin() + index);
                index--;
                count++;
            }
        }

        nums.insert(nums.end(), count, 0);
    }
    
};
