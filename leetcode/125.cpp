#include <bits/stdc++.h>

using namespace std;

int main(){
    string test = "A0";
    string temp = "";
    for(int count = 0; count < test.size(); count++)
        temp += tolower(test[count]);

    cout << temp << endl;
}