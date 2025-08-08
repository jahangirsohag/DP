#include <iostream>

using namespace std;

const int N = 1e9 + 7;

int rec(int n)
{
	if(n == 2) return 2;
	if(n == 1) return 1;

	int s1 = rec(n - 2);
	int s2 = rec(n - 1);

	return s1 + s2;

}

int memo(int n, int dp[])
{
	if(n == 2) return 2;
	if(n == 1) return 1;

	if(dp[n] != 0) return dp[n];

	int s2 = memo(n - 2, dp);
	int s1 = memo(n - 1, dp);

	dp[n] = s1 + s2;

	return dp[n];
}

int tab(int n, int dp[])
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
		dp[i] = dp[i - 2] + dp[i - 1];
	}
	return dp[n];
}

int spaceOpti(int n)
{
	if(n <= 1) return 1;
	int nm1 = 1;
	int nm2 = 1;

	int current = 0;
	for(int i = 2; i <= n; ++i)
	{
		current = nm1 + nm2;

		if(n == i) return current;

		nm2 = nm1;
		nm1 = current;
	}
	return 0;
}

signed main() {

	int n = 9;

	int dp[n + 1] = {};

	// int  ans = memo(n, dp);

	// int ans = tab(n, dp);

	int ans = spaceOpti(n);

	cout << ans << endl;


	
	return 0;
}