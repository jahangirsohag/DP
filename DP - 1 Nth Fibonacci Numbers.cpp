#include <iostream>

using namespace std;

const int N = 1e9 + 7;

int r(int n)
{
	if(n == 0) return 0;
	if(n == 1) return 1;

	int f2 = r(n - 2);
	int f1 = r(n - 1);

	return f2 + f1;
}

int memo(int n, int dp[])
{
	if(n == 0) return 0;
	if(n == 1) return 1;

	if(dp[n] != 0) return dp[n];

	int f2 = memo(n - 2, dp);
	int f1 = memo(n - 1, dp);

	dp[n] = f1 + f2;

	return f1 + f2;
}

int tab(int n, int dp[])
{
	for(int i = 0; i <= n; ++i)
	{
		if(i == 0)
		{
			dp[i] = 0;
			continue;
		}
		if(i == 1)
		{
			dp[i] = 1;
			continue;
		}

		int f2 = dp[i - 2];
		int f1 = dp[i - 1];

		dp[i] = f1 + f2;
	}
	return dp[n];
}

int opti(int n)
{
	if(n == 0) return 0;
	if(n == 1) return 1;

	int f2 = 0;
	int f1 = 1;

	int current = 0;
	for(int i = 2; i <= n; ++i)
	{
		current = f2 + f1;
		if(i == n) return current;

		f2 = f1;
		f1 = current;
	}
	return current;
}

signed main() {

	int n = 10;
	int dp[n + 1] = {};

	// int recursive = r(n);

	// int memoization = memo(9, dp);

	// int tabulation = tab(9, dp);

	int spaceopti = opti(11);

	cout << spaceopti << endl;
	
	return 0;
}