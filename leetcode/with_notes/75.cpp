// A better solution will be using a mid paramter and then swapping the elements accordingly, if the element is 0 then swap it with the first element, if the element is 2 then swap it with the last element, if the element is 1 then just move to the next element.
// And the time complexity of this algorithm is O(n) and the space complexity is O(1)
// Another sol?: the Dutch National Flag Algorithm

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r = 0;
        int w = 0;
        int b = 0;
        for(int i = 0; i < nums.size(); i++){
            switch(nums[i]){
                case 0:
                    r++;
                    break;
                case 1:
                    w++;
                    break;
                case 2:
                    b++;
                    break;
            }
        }
        for(int i = 0; i < r; i++){
            nums[i] = 0;
        }
        for(int i = r; i < r + w; i++){
            nums[i] = 1;
        }
        for(int i = r + w; i < nums.size(); i++){
            nums[i] = 2;
        }
    }
};