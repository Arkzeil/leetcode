// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1;
        //int r = n;
        int len = n;
        while(len > 0){
            len/=2;
            if(isBadVersion(l + len)){
                if(len == 0)
                    return l;

                //r = l + len - 1;
            }
            else
                l = l + len + 1;
        }
        return l;
    }
};