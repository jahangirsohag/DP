#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool recur(string s, int i, int j)
{
	if(i == j) return true;
	if(i > j) return true;
	if(s[i] != s[j]) return false;

	return recur(s, i + 1, j - 1);
}

//dp[sp][ep] == 1; true;
//dp[sp][ep] == 0; not calculated;
//dp[sp][ep] == -1 false;
bool memo(string s, int sp, int ep, vector<vector<int>> &dp)
{
	if(sp == ep) return true;
	if(sp > ep) return true;

	if(dp[sp][ep] != 0) return dp[sp][ep];

	if(s[sp] != s[ep]) return false;

	dp[sp][ep] = memo(s, sp + 1, ep - 1, dp);

	return dp[sp][ep];
}



signed main() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	//code for memoization
	// vector<vector<int>> dp(n, vector<int>(n, 0));

	// int cnt = 0;

	// for(int i = 0; i < n; ++i)
	// {
	// 	for(int j = i; j < n; ++j)
	// 	{
	// 		bool isPalindrome = memo(str, i, j, dp);
	// 		if(isPalindrome)
	// 		{
	// 			cnt++;
	// 		}
	// 	}
	// }
	// cout << cnt << endl;

	vector<vector<bool>> dp(n, vector<bool>(n, false));

	for(int gap = 0; gap < n; ++gap)
	{
		for(int sp = 0, ep = gap; ep < n; ++sp, ++ep)
		{
			if(gap == 0)
			{
				dp[sp][ep] = true;
			}
			else if(gap == 1)
			{
				if(s[sp] == s[ep])
				{
					dp[sp][ep] = true;
				}
				else dp[sp][ep] = false;
			}
			else
			{
				if(s[sp] == s[ep])
				{
					if(dp[sp + 1][ep - 1])
					{
						dp[sp][ep] = true;
					}
					else
					{
						dp[sp][ep] = false;
					}
				}
				else
				{
					dp[sp][ep] = false;
				}
				// if(s[sp] == s[ep])
				// {
				// 	dp[sp][ep] = dp[sp + 1][ep - 1];
				// }
			}
		}
	}

	int count = 0;

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			if(i <= j)
			{
				if(dp[i][j]) count++;
			}
		}
	}

	cout << count << endl;

	
	return 0;
}