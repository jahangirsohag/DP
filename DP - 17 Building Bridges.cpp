#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

signed main() {
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	int b[n];
	for(int i = 0; i < n; ++i)
	{
		cin >> b[i];
	}
	vector<pair<int, int>> vec;

	for(int i = 0; i < n; ++i)
	{
		vec.push_back({a[i], b[i]});
	}

	sort(vec.begin(), vec.end());

	vector<int> dp(n, 0);

	for(int i = 0; i < n; ++i)
	{
		int bestOfPrev = 0;
		for(int j = i - 1; j >= 0; --j)
		{
			if(vec[i].second > vec[j].second)
			{
				bestOfPrev = max(bestOfPrev, dp[j]);
			}
		}
		dp[i] = bestOfPrev + 1;
	}

	int ans = 0;
	for(int i = 0; i < n; ++i)
	{
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
	
	return 0;
}