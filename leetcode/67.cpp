class Solution {
public:
    string addBinary(string a, string b) {
        //bitset<a.size()> op1(a);
        //bitset<b.size()> op2(b);
        int max_len = max(a.size(), b.size());
        if(a.size() < b.size())
            a = string(max_len - a.size(), '0') + a;
        else if(a.size() > b.size())
            b = string(max_len - b.size(), '0') + b;

        int op1, op2, carry= 0;
        int temp;
        string ans;    
        
        for(int i = max_len - 1; i >= 0; i--){
            temp = carry + a[i] - '0' + b[i] -'0';
            if(temp > 1){
                carry = 1;
                ans = to_string(temp - 2) + ans;
            }
            else{
                carry = 0;
                ans = to_string(temp) + ans;
            }
        }
        if(carry)
            ans = '1' + ans;

        return ans;
    }
};