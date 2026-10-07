class Solution {
public:
    void dfs(int i,int j,int oldColor,int color,vector<vector<int>>& image){
        int m = image.size();
        int n = image[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n)return;
        if(image[i][j] != oldColor)return;
        image[i][j] = color;
        dfs(i, j + 1, oldColor, color, image);
        dfs(i + 1, j, oldColor, color, image);
        dfs(i - 1, j, oldColor, color, image);
        dfs(i, j - 1, oldColor, color, image);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int oldColor = image[sr][sc];
        if(oldColor == color)return image;
        dfs(sr,sc,oldColor, color,image);

        return image;
    }
};