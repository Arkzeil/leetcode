class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int start = newInterval[0];
        int end = newInterval[1];
        int l = 0, r = intervals.size() - 1;

        for(int i = 0; i < intervals.size(); i++){
            if(start >= intervals[i][0]){
                l = i;
                if(start > intervals[i][1])
                    l++;
            }
            if(end <= intervals[i][0]){
                if(end < intervals[i][0])
                    r = i - 1;
                else
                    r = i;
                break;
            }
        }

        ans.reserve(intervals.size() - (r - l) );

        if(l) //l > 0
            ans.insert(ans.begin(), intervals.begin(), intervals.begin() + l);
        
        ans.push_back(vector<int>());
        if(l <= r && start > intervals[l][0])//intervals may be empty
            ans[l].push_back(intervals[l][0]);
        else
            ans[l].push_back(start);
        if(l <= r && end < intervals[r][1])
            ans[l].push_back(intervals[r][1]);
        else
            ans[l].push_back(end);

        if(r + 1 < intervals.size())
            ans.insert(ans.end(), intervals.begin() + r + 1, intervals.end());

        return ans;
    }
};
