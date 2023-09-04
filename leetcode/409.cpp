#include <bits/stdc++.h>

using namespace std;

int longestPalindrome(string s) {
        map<char,int> letter_map;
        int ans = 0;
        bool flag = false;
        
        for(int index = 0; index < s.size(); index++)
            letter_map[s[index]] = (letter_map.count(s[index]) ) ? ++letter_map[s[index]] : 0;
        
        cout << "here" << endl;

        for(auto &i : letter_map){
            //cout << i.first << ' ' << i.second << endl;
            ans += ((i.second / 2) * 2);
            //cout << ans << endl;
            if(i.second % 2)
                flag = true;
        }

        if(flag)
            ans++;

        return ans;
}

int main(){

    string s = "a";
    
    cout << "here" << endl;
    cout << longestPalindrome(s) << endl;
    return 0;
}