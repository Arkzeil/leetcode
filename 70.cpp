#include <bits/stdc++.h>

using namespace std;

int climbStairs(int n) {
        int twos = 0;
        vector<int> vec;
        int ans = 0;

        while(n > 1){
            n -= 2;
            vec.push_back(2);
            twos++;
        }

        if(n)
            vec.push_back(1);
        cout << twos << endl;
        
        cout << endl;

        while(twos >= 0){
            ans++;

            for(auto &i : vec)
                cout << i << ' ';
            cout << endl;
            while(next_permutation(vec.begin(), vec.end())){//Rearranges the elements in the range [first,last) into the next lexicographically greater permutation
                cout << 'p' << endl; //so must put 1s in front 2s
                ans++;
            }
            
            vec.push_back(1);
            vec.push_back(1);
            vec.erase(vec.begin());
            twos--;
        }

        return ans;
}

int main(){
    cout << climbStairs(3) << endl;
    /*vector<int> vec = {1,2};
    while(next_permutation(vec.begin(), vec.end())){//Rearranges the elements in the range [first,last) into the next lexicographically greater permutation
        for(int count = 0; count < vec.size(); count++)
            cout << vec[count] << ' ';
        cout << 'p' << endl;
        //ans++;
    }*/

    return EXIT_SUCCESS;
}