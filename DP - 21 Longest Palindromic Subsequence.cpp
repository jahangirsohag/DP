#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int recur(string s, int sp, int ep)
{
	if(sp == ep) return 1;
	if(sp + 1 == ep)
	{
		if(s[sp] == s[ep]) return 2;
		return 1;
	}
	if(s[sp] == s[ep]) return recur(s, sp + 1, ep - 1) + 2;

	return max(recur(s, sp + 1, ep), recur(s, sp, ep - 1));
}

int memo(string s, int sp, int ep, vector<vector<int>> &dp)
{
	if(sp == ep) return 1;
	if(sp + 1 == ep)
	{
		if(s[sp] == s[ep]) return 2;
		return 1;
	}
	if(s[sp] == s[ep]) return memo(s, sp + 1, ep - 1, dp) + 2;

	if(dp[sp][ep] != 0) return dp[sp][ep];

	if(s[sp] == s[ep]) return memo(s, sp + 1, ep - 1, dp) + 2;

	int excLast = memo(s, sp, ep - 1, dp);
	int excFirst = memo(s, sp + 1, ep, dp);

	return max(excLast, excFirst);
}

signed main() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	vector<vector<int>> dp(n, vector<int>(n, 0));

	for(int gap = 0; gap < n; ++gap)
	{
		for(int sp = 0, ep = gap; ep < n; ++sp, ++ep)
		{
			if(sp == ep)
			{
				dp[sp][ep] = 1;
			}
			else if(sp + 1 == ep)
			{
				dp[sp][ep] = s[sp] == s[ep] ? 2 : 1;
			}
			else
			{
				if(s[sp] == s[ep])
				{
					dp[sp][ep] = dp[sp + 1][ep - 1] + 2;
				}
				else
				{
					dp[sp][ep] = max(dp[sp][ep - 1], dp[sp + 1][ep]);
				}
			}
		}
	}
	cout << dp[0][n - 1] << endl;
	return 0;
}