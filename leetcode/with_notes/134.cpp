// the gas must be larger or equal than cost in same index
// the sum of gas from starting point must always be larger than or euqal to cost during the journey
// Fail at first try
// 重點應該是剩餘量，每點剩餘量須是正數，但到了index i就失敗，代表前面無論從哪點開始都會失敗（因為前面的點都須經過，不會有說從中間那一點開始卻剩餘量較多的情況）
// 更好的方法應該是整個list尋一遍即可，並找出index i + 1。最後若全部的sum為正則回傳index i + 1
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int cur = 0;
        for(int i = 0; i < gas.size(); i++){
            if(gas[i] >= cost[i]){
                cur = 0;
                for(int j = i; j < gas.size() + i; j++){
                    cur += (gas[j % gas.size()] - cost[j % gas.size()]);
                    if(cur < 0){
                        i = j;
                        break;
                    }
                    if(j == gas.size() + i - 1 && cur >= 0)
                        return i;    
                }
            }
        }
        return -1;         
    }
};