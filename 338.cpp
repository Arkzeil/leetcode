#include <bits/stdc++.h>

using namespace std;

int dec2bin(string input, int &cur_ans);

vector<int> countBits(int n) {
    vector<int> dp(n + 1), ans(n + 1);
    int cur_ans = 0;

    ans[0] = dp[0] = 0;
    
    if(n > 0)
        ans[1] = dp[1] = 1;

    for(int i = 2; i <= n; i++){
        cur_ans = 0;
        dp[i] = dp[i-1] + 1;
        cout << dp[i] << ' ';
        dp[i] = dec2bin(to_string(dp[i]), cur_ans);
        cout << dp[i] << endl;
        ans[i] = cur_ans;
    }

    return ans;
}

int dec2bin(string input, int &cur_ans){
    int carry = 0;

    for(int i = input.size() - 1; i >= 0; i--){
        input[i] =(char)( (int)input[i] + carry);
        if(input[i] > '1'){
            input[i] = '0';
            carry = 1;
        }
        else{
            carry = 0;
        }

        if(input[i] > '0')
            cur_ans++;
    }
    
    if(carry){
        input = '1' + input;
        cur_ans++;
    }

    return stoi(input);
}

int main(){

    countBits(5);

    return EXIT_SUCCESS;
}