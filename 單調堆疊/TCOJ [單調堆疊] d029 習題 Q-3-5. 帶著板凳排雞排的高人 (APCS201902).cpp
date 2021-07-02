#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, height[200010], chair[200010];
	long long int ans = 0;
	vector<pair<int, int>> st;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> height[i];
	}
	for(int i=1;i<=n;i++){
		cin >> chair[i];
	}
	st.push_back({INT_MAX, 0});
	for(int i=1;i<=n;i++){
		while(!st.empty() && st.back().first <= height[i])
			st.pop_back();
		int pos;
		while // binary search
		ans += i - pos - 1;
		st.push_back({height[i], i});
	}
	cout << ans << "\n";
    return 0;
}
