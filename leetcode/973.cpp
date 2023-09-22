class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<int> index(points.size());
        int dist[points.size()];
        vector<vector<int>> ans(k);
        //int ans_size = k;

        iota(index.begin(), index.end(), 0);

        for(int i = 0; i < points.size(); i++)
            dist[i] = pow(points[i][0], 2) + pow(points[i][1], 2);
        
        sort(index.begin(), index.end(), [&dist](int x, int y){return dist[x] < dist[y];});

       /*
        for(int i = k; i < points.size(); i++, ans_size++){
            if(dist[i] != dist[k - 1])
                break;
        }

        vector<vector<int>> ans(ans_size);*/
        // it's ask for first k closest points, not k-th closest points 
        /*for(int i = 0; i < ans_size; i++)
            ans[i].insert(ans[i].begin(), points[index[k - 1 + i]].begin(), points[index[k - 1 + i]].end());*/
        for(int i = 0; i < k; i++)
            ans[i].insert(ans[i].begin(), points[index[i]].begin(), points[index[i]].end());

        return ans;
    }
};
