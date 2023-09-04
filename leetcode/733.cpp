class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        return dfs(image, sr, sc, color, image[sr][sc]);
    }

private:
    vector<vector<int>> dfs(vector<vector<int>>& image, int sr, int sc, int color, int src_color) {
        if(image[sr][sc] == color)
            return image;
        else if(image[sr][sc] == src_color)
            image[sr][sc] = color;
        else
            return image;

        if(sr > 0){
            if(image[sr - 1][sc] == src_color)
                dfs(image, sr - 1, sc, color, src_color);
        }
        if(sc > 0){
            if(image[sr][sc - 1] == src_color)
                dfs(image, sr, sc - 1, color, src_color);
        }
        if(sr < image.size() - 1){
            if(image[sr + 1][sc] == src_color)
                dfs(image, sr + 1, sc, color, src_color);
        }
        if(sc < image[sr].size() - 1){
            if(image[sr][sc + 1] == src_color)
                dfs(image, sr, sc + 1, color, src_color);
        }

        return image;
    }
};