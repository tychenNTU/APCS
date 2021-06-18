#include <bits/stdc++.h>

using namespace std;

int main(){
	int t, r, c, fire_time[101][101], start_y, start_x;
	int dir_x[4] = {1, 0, -1, 0}, dir_y[4] = {0, 1, 0, -1};
	bool wall[101][101];
	string x;
	cin >> t;
	for(int qq = 0;qq < t;qq ++){
		queue<pair<pair<int, int>, int>> q;
		cin >> r >> c;
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				fire_time[i][j] = -1;
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
	}
    return 0;
}
