// ref: https://leetcode.com/problems/combination-sum/solutions/16502/a-general-approach-to-backtracking-questions-in-java-subsets-permutations-combination-sum-palindrome-partitioning/
class Solution {
public:
    void backtrack(vector<vector<int>> &ans, vector<int> &temp, vector<int>&candidates, int start, int remain){ //remain: what's the remain of target after subtracting elements in temp
        if(remain < 0) // the inserted element is too large
            return;
        if(!remain) // remain==0: one match sequence
            ans.push_back(vector<int>(temp)); //deep copy
        else{
            for(int count = start; count < candidates.size(); count++){
                temp.push_back(candidates[count]); // first push
                backtrack(ans, temp, candidates, count, remain - candidates[count]); //ex:7:2 -> 2,2 -> 2,2,2 ->(pop) 2,2,3(match) ->(6,7 not fit, pop) 2,3 (6,7 not fit, pop) -> 2,6 ...
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int sum = 0;
        vector<vector<int>> ans; // store the answers
        vector<int> temp; // store all the possible combination of target n in temp[n]
        //temp.push_back(vector<int>()); // 0 has no combinations
        
        sort(candidates.begin(), candidates.end());

        backtrack(ans, temp, candidates, 0, target);

        return ans;
    }

};
