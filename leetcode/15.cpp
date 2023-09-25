// ref:https://leetcode.com/problems/3sum/solutions/3186495/best-c-3-solution-two-pointers-sorting-hash-table-brute-force-optimize/
// origin method would lead to TLE

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> set;
        int index = 0, len = nums.size();
        int l, r;
        //vecror<vector<int>> temp(nums.size());
        sort(nums.begin(), nums.end());

        for(int i = 0; i < len - 2; i++){ //2 negative, 1 positive
            l = i + 1;
            r = len - 1;
            while(l < r){
                if(nums[i] + nums[l] + nums[r] < 0)
                    l++;
                else if(nums[i] + nums[l] + nums[r] > 0)
                    r--;
                else{
                    set.insert(vector<int>{nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                }
            }
            /*for(int ll = l + 1; ll < len - 1; ll++){
                vector<int>::iterator it = find(nums.begin() + ll + 1, nums.end(), 0 - nums[l] - nums[ll]);
                if(it != nums.end() && it != nums.begin() + l && it != nums.begin() + ll){
                    set.insert(vector<int>{nums[l], nums[ll], *it});
                }
            }*/
        }

        for(auto i : set)
            ans.push_back(i);

        return ans;
    }

    /*struct triplet{
        int a;
        int b;
        int c;
    }tri;*/
};
