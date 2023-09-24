// This is a bad solution since I should not choose map as data structure
// its sequence is not performed as conventional stack or queue
// it seemed to be scrambled in sequence

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> rec; //its sequence can't be determined?
        int max_len = 0, cur_len = 0;

        for(int i = 0; i < s.size(); i++){
            if(!rec.count(s[i])){
                rec[s[i]] = i;
                if(++cur_len > max_len)
                    max_len = cur_len;
            }
            else{
                auto dup = rec.find(s[i]);
                vector<char> del;

                for(auto it = rec.begin(); it != rec.end(); it++){
                    if(it->second <= dup->second){
                        cur_len--;
                        del.push_back(it->first);
                    }
                }

                for(char i : del)
                    rec.erase(i);
                //for(auto it = dup; it != rec.end(); it++)
                //    cur_len--;
                //cur_len -= distance(rec.begin(), dup);
                //rec.erase(dup, rec.end());

                rec[s[i]] = i;
                cur_len++;
            }
        }

        return max_len;
    }
};
