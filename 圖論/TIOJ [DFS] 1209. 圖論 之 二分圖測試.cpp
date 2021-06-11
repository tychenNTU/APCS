#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
bool same;
vector <int>edge[40010];
int vis[40010];
void dfs(int n, int color){
    vis[n] = color;
    for(int i = 0; i < edge[n].size(); i++){
        if(!vis[edge[n][i]]){
            dfs(edge[n][i], 3 - color);
        }
        else if(vis[edge[n][i]] == color) {
            same = false;
        }
    }
}
int main(){
    int n, m;
    while(cin >> n >> m){
        if(n == 0)break;
        int from, to;
        memset(vis, 0, sizeof(vis));
        same = true;
        for(int i = 0; i < n + 1; i++){
            edge[i].clear();
        }
        for(int i = 0; i < m; i++){
            cin >>from >> to;
            edge[from].push_back(to);
            edge[to].push_back(from);
        }
        dfs(1, 2);
        cout << (same? "Yes" : "No") << endl;
    }
    return 0;
}