#include <bits/stdc++.h>

using namespace std;

int main(){
    queue<pair<int, int>> q;
    int n, p, l, r, s[1000010], ans = -1;
    bool vis[1000010];
    cin >> n >> p >> l >> r;
    for(int i=0;i<n;i++){
        cin >> s[i];
        vis[i] = false;
    }
    vis[0] = true;
    q.push({0, 0});
    while(!q.empty()){
        pair<int, int> temp = q.front();
        int now = temp.first, step = temp.second;
        if(now == p){
            ans = step;
            break;
        }
        q.pop();
        // ¬Û¾FªºÂI
        if(now - l >= 0){
            int left = s[now - l];
            if(left >= 0 && left < n && !vis[left]){
                vis[left] = true;
                q.push({left, step + 1});
            }
        }
        if(now + r < n){
            int right = s[now + r];
            if(right >= 0 && right < n && !vis[right]){
                vis[right] = true;
                q.push({right, step + 1});
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
