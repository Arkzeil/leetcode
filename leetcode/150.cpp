class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for(int count = 0; count < tokens.size(); count++){
            if((tokens[count][0] == '-' && tokens[count].size() > 1) || tokens[count][0] >= '0' && tokens[count][0] <= '9') // there might a negative sign
                stk.push(stoi(tokens[count]));
            else{
                int r = stk.top();
                stk.pop();
                int l = stk.top();
                stk.pop();

                switch(tokens[count][0]){
                    case '+':
                        stk.push(l + r);
                        break;
                    case '-':
                        stk.push(l - r);
                        break;
                    case '*':
                        stk.push(l * r);
                        break;
                    case '/':
                        stk.push(int(l / r));
                        break;
                }    
            }
        }

        return stk.top();
    }
};
