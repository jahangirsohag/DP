#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e9 + 7;

long long recur(int n)
{
	if(n == 1) return 1;

	if(n == 2) return 2;

	long long vertical = recur(n - 1);
	long long horizontal = recur(n - 2);

	return vertical + horizontal;
}

long long memo(int n, vector<long long> dp)
{
	if(n == 1) return 1;

	if(n == 2) return 2;

	if(dp[n] != -1) return dp[n];

	long long vertical = memo(n - 1, dp);
	long long horizontal = memo(n - 2, dp);

	dp[n] = vertical + horizontal;

	return dp[n];
}

long long tab(int n, vector<long long> dp)
{
	for(int i = 1; i <= n; ++i)
	{
		if(i == 1)
		{
			dp[i] = 1;
			continue;
		}
		if(i == 2)
		{
			dp[i] = 2;
			continue;
		}

		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}
signed main() {
	int n;
	cin >> n;

	vector<long long> dp(n + 1, -1);

	// int ans = recur(n);

	// int ans = memo(n, dp);

	long long ans = tab(n, dp);

	cout << ans << endl;

	return 0;
}