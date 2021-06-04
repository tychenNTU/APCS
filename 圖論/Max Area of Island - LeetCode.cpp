class Solution {
public:
    vector<vector<bool>> vis;
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    int row, col;
    int DFS(int y, int x, vector<vector<int>> &grid){
        int ans = 1;
        for(int i=0;i<4;i++){
            int xx = x + dx[i], yy = y + dy[i];
            if(xx < 0 || xx >= col || yy < 0 || yy >= row)continue;
            if(vis[yy][xx] || grid[yy][xx] == 0)continue;
            vis[yy][xx] = true;
            ans += DFS(yy, xx, grid);
        }
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        row = grid.size();
        if(row == 0)return 0;
        col = grid[0].size();
        vis.resize(row, vector<bool>(col));
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                vis[i][j] = false;
        int ans = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(vis[i][j] || grid[i][j] == 0)continue;
                vis[i][j] = true;
                ans = max(ans, DFS(i, j, grid));
            }
        }
        return ans;
    }
};