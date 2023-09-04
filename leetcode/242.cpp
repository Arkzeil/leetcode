class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        for(int count = 0; count < t.size(); count++){
            if(s[count] != t[count])
                return false;
        }

        return true;
    }
};