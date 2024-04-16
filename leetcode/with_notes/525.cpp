// https://leetcode.com/problems/contiguous-array/solutions/4881359/easy-explanation-hashmap-beats-93-29-c-java-python3-kotlin
// for each prefix sum encountered, we check if we have seen this sum before. If so, it means that the subarray between the current index and the index where this sum was last encountered has an equal number of 0s and 1s. We calculate the length of this subarray and update the maximum length accordingly.
// 前面大於0的sum之後再重新出現的話代表現在的subarray實際上扣除之前的那個subarray便會sum=0
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int len = 0;
        int sum = 0;

        unordered_map<int, int> umap;

        for(int count = 0; count < nums.size(); count++){
            if(nums[count])
                sum++;
            else
                sum--;

            if(sum == 0)
                len = count + 1;
            else if(umap.find(sum) != umap.end())
                len = max(len, count - umap[sum]);
            else
                umap[sum] = count; 
        }

        return len;
    }
};