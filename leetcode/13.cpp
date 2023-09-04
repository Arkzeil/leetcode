class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> rom2int = {{'I', 1}, 
                                            {'V', 5}, 
                                            {'X', 10}, 
                                            {'L', 50}, 
                                            {'C', 100}, 
                                            {'D', 500}, 
                                            {'M', 1000}};
        int ans = 0, sub = 0;

        for(int i = 0; i < s.size(); i++){
            ans += rom2int[s[i]];

            if(i < s.size() - 1){
                switch(s[i]){
                    case 'I':
                        if(s[i+1] == 'V' || s[i+1] == 'X')
                            ans -= 2;
                        break;
                    case 'X':
                        if(s[i+1] == 'L' || s[i+1] == 'C')
                            ans -= 20;
                        break;
                    case 'C':
                        if(s[i+1] == 'D' || s[i+1] == 'M')
                            ans -= 200;
                        break;
                }
            }
        }
        
        return ans;
    }
};