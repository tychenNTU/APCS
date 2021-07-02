#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, nums[200010];
	long long int ans = 0;
	vector<pair<int, int>> st;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> nums[i];
	}
	st.push_back({INT_MAX, 0});
	for(int i=1;i<=n;i++){
		while(!st.empty() && st.back().first <= nums[i])
			st.pop_back();
		ans += i - st.back().second;
		st.push_back({nums[i], i});
	}
	cout << ans << "\n";
    return 0;
}
