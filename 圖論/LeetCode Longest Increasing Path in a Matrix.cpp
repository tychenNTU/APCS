class Solution {
public:
    vector<vector<int>> dis;
    int row, col;
    int dx[4] = {1, 0, -1, 0},
        dy[4] = {0, 1, 0, -1};
    int DFS(int x, int y, vector<vector<int>> &mat){
        if(dis[y][x] != -1) return dis[y][x];
        int nx, ny, ans = 1;
        for(int i=0;i<4;i++){
            nx = x + dx[i];
            ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= col || ny >= row) 
                continue;
            if(mat[ny][nx] > mat[y][x]){
                ans = max(ans, DFS(nx, ny, mat) + 1);
            }
        }
        return dis[y][x] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 0;
        row = matrix.size();
        if(row == 0) return 0;
        col = matrix[0].size();
        dis.resize(row, vector<int>(col, -1));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                ans = max(ans, DFS(j, i, matrix));
            }
        }
        return ans;
    }
};