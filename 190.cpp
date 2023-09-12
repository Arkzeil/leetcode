class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint times = pow(2,31);
        uint ans = 0;
        while(n){
            ans += (n % 2) * times;
            times /= 2;
            n /= 2;
        }

        return ans;
    }
};
