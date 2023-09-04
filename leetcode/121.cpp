#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min, max, profit = 0;
        int min_index, max_index;//store the index of max&min price
        int index_cur_min, index_cur_max; //store the current location of min and max in index 
        /*
        while(lower < lower){
            if(prices[lower] > max)
                max = prices[lower];
            if(prices[upper] > min)
                min = prices[upper];

            if(max - min > profit)
                profir = max - min;
            lower++;
            upper--;
        }*/
        vector<int> index(prices.size()); //store the sorted vector's index. index[0] stores the index of min price
        iota(index.begin(), index.end(), 0);

        sort(index.begin(), index.end(),[&prices](int x, int y){return prices[x] < prices[y];});

        for(int count = 0 ; count < index.size(); count++)
            cout << index[count] << ' ';
        cout << endl;
        
        index_cur_max = index.size() - 1;
        index_cur_min = 0;
        max_index = index[index_cur_max];
        min_index = index[index_cur_min]; 
        max = prices[max_index];
        min = prices[min_index];
        profit = max - min;
        
        cout << max_index << ' ' << min_index << endl;
        cout << index_cur_max << ' ' << index_cur_min << endl;

        while(max_index < min_index){

            for(int count = index_cur_max - 1; count >= 0; index_cur_max--){
                cout << count << ' ';
                if(min_index < index[count]){
                    max = prices[index[count]];
                    return max - min;
                }
            }
                
            index_cur_min++;
            min_index = index[index_cur_min];
            min = prices[min_index];
        }

        return profit;
    }
};

int main(){
    vector<int> test = {7, 1, 5, 3, 6, 4};

    Solution temp;

    cout << temp.maxProfit(test) << endl;

    return EXIT_SUCCESS;
}
