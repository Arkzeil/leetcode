class Solution {
public:
    bool backspaceCompare(string s, string t) {
        //int i1 = s.size() , i2 = t.size();
        int index = 0;

        while(s.begin() + index != s.end()){
            if(s[index] == '#'){
                if(index > 0){
                    s.erase(index - 1, 2);
                    index -= 2;
                }
                else if(index == 0){
                    s.erase(index, 1);
                    index --;
                }
            }
            index++; 
        }
        //cout << s << endl;
        index = 0;

        while(t.begin() + index != t.end()){
            if(t[index] == '#'){
                if(index > 0){
                    t.erase(index - 1, 2);
                    index -= 2;
                }
                else if(index == 0){
                    t.erase(index, 1);
                    index --;
                }
            }
            index++; 
        }

       // cout << t << endl;

        if(s.size() != t.size())
            return false;
        
        for(index = 0; index < s.size(); index++){
            if(s[index] != t[index])
                return false;
        }

        return true;
    }
};