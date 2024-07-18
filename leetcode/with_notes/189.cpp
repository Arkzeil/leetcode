// 1. exhaustive move: move whole array forward for k indices step by step
// 2. reassign another vector, and fill the k number of elements in front of the vector
// 3. add index with k, then mod vector.size() -> speed:O(n)
// how to make it O(1) space? exhastive move should be O(1), but it's slow.
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp = nums;
        for(int i = 0; i < nums.size(); i++){
            nums[(i + k) % nums.size()] = temp[i];
        }
    }
};

// Best solution is use reverse, first reverse whole vector, then reverse k elements, then reverse remaining elements
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size(); // to avoid k is larger then size
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};