class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string lcp = strs[0];

        //if(strs.size() == 1)
          //  return lcp;

        for(int i = 1; i < strs.size(); i++){
            for(int index = 0; index < strs[i].size(); index++){
                if(index >= lcp.size() || strs[i][index] != lcp[index]){
                    lcp = lcp.substr(0, index);
                    break;
                }
            }

            if(strs[i].size() < lcp.size())
                lcp = lcp.substr(0, strs[i].size());

            if(lcp == "")
                return lcp;
        }

        return lcp;
    }
};