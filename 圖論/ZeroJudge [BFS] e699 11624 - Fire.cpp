#include <bits/stdc++.h>
#define NMAX 101
using namespace std;

int main(){
	int t, r, c, fire_time[NMAX][NMAX], start_y, start_x, ans;
	int dir_x[4] = {1, 0, -1, 0}, dir_y[4] = {0, 1, 0, -1};
	bool wall[NMAX][NMAX], vis[NMAX][NMAX];
	queue<pair<pair<int, int>, int>> q;
	string x;
	cin.tie();
	ios::sync_with_stdio(false);
	cin >> t;
	for(int qq = 0;qq < t;qq ++){
		ans = -1;
		cin >> r >> c;
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				fire_time[i][j] = -1;
				vis[i][j] = false;
			}
		}
		for(int i=0;i<r;i++){
			cin >> x;
			for(int j=0;j<c;j++){
				if(x[j] == '#') wall[i][j] = true;
				else wall[i][j] = false;
				if(x[j] == 'F'){
					q.push({{i, j}, 0});
					fire_time[i][j] = 0;
				}
				if(x[j] == 'J'){
					start_y = i;
					start_x = j;
				}
			}
		}
		while(!q.empty()){
			pair<pair<int, int>, int> now = q.front();
			q.pop();
			int now_y = now.first.first, now_x = now.first.second, now_step = now.second;
			for(int i=0;i<4;i++){
				int next_x = now_x + dir_x[i], next_y = now_y + dir_y[i];
				if(next_x < 0 || next_x >= c || next_y < 0 || next_y >= r) continue;
				if(wall[next_y][next_x] || fire_time[next_y][next_x] >= 0) continue;
				fire_time[next_y][next_x] = now_step + 1;
				q.push({{next_y, next_x}, now_step + 1});
			}
		}
		/*for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				cout << "\t" << fire_time[i][j];
			}
			cout << "\n";
		}*/
		q.push({{start_y, start_x}, 0});
		vis[start_y][start_x] = true;
		while(!q.empty()){
			pair<pair<int, int>, int> now = q.front();
			q.pop();
			if(ans != -1) continue;
			int now_y = now.first.first, now_x = now.first.second, now_step = now.second;
			for(int i=0;i<4;i++){
				int next_x = now_x + dir_x[i], next_y = now_y + dir_y[i];
				if(next_x < 0 || next_x >= c || next_y < 0 || next_y >= r){
					ans = now_step + 1;
					break;
				}
				if(wall[next_y][next_x] ||
					(fire_time[next_y][next_x] <= now_step + 1 && fire_time[next_y][next_x] != -1) ||
						vis[next_y][next_x]) continue;
				vis[next_y][next_x] = true;
				q.push({{next_y, next_x}, now_step + 1});
			}
		}
		if(ans == -1) cout << "IMPOSSIBLE\n";
		else cout << ans << "\n";
	}
    return 0;
}
