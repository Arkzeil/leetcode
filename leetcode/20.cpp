class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int count = 0; count < s.size(); count++){
            if(s[count] == '(' || s[count] == '{' | s[count] =='[')
                stk.push(s[count]);
            else{
                if(stk.empty())
                    return false;
                    
                char top = stk.top();
                switch(s[count]){
                    case ')':
                        if(top != '(')
                            return false;
                        break;
                    case '}':
                        if(top != '{')
                            return false;
                        break;
                    case ']':
                        if(top != '[')
                            return false;
                }
                stk.pop();
            }
            if(count == s.size() - 1){
                if(!stk.empty())
                    return false;
            }
        }
        return true;
    }
};