// exhaustive: O(n^2), for{for}. Get the highest value
// DP?
// Decreasing the width of the container can only lead to a larger area if the height of the new boundary is greater.
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int res = 0;

        while(l < r){
            if(((r - l) * min(height[l], height[r]) ) > res)
                res = (r - l) * min(height[l], height[r]);
            if(height[l] > height[r])
                r--;
            else
                l++;
        }

        return res;
    }
};