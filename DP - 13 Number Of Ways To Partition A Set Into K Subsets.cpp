#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e9 + 7;

int recur(int n)
{
	if(n == 2) return 2;

	if(n == 3) return 4;

	return recur(n - 1) + (n - 1) * recur(n - 2);
}

int memo(int n, vector<int> &dp)
{
	if(n == 1) return 1;

	if(n == 2) return 2;

	if(dp[n] != -1) return dp[n];

	return dp[n] = memo(n - 1, dp) + (n - 1)*memo(n - 2, dp);
}

int tab(int n, vector<int> &dp)
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
		int ansNm1 = dp[i - 1];
		int ansNm2 = dp[i - 2];

		dp[i] = ansNm1 + (i - 1)*ansNm2;
	}
	return dp[n];
}

signed main() {
	int n;
	cin >> n;

	vector<int> dp(n + 1, -1);

	int ans = tab(n, dp);

	cout << ans << endl;

	return 0;
}