#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e9 + 7;

int recur(vector<int> &val, int i, int w, vector<int> &wt)
{
	if(w < 0) return -1e9;
    
    if(i == val.size()) return 0;
    
    if(w == 0) return 0;
    
    int pick = recur(val, i + 1, w - wt[i], wt) + val[i];
    int skip = recur(val, i + 1, w, wt);

    return max(pick, skip);
}

int memo(vector<int> &val, int i, int w, vector<int> &wt, vector<vector<int>> &dp)
{
	if(w < 0) return -1e9;

    if(i == val.size()) return 0;
    
    if(w == 0) return 0;
    
    if(dp[i][w] != -1) return dp[i][w];
    
    int pick = memo(val, i + 1, w - wt[i], wt, dp) + val[i];
    int skip = memo(val, i + 1, w, wt, dp);
    
    dp[i][w] = max(pick, skip);
    
    return dp[i][w];
}

int tab(vector<int> &val, int w, vector<int> &wt, vector<vector<int>> &dp)
{
	int n = val.size();

	for(int i = n - 1; i >= 0; --i)
	{
		for(int weight = 0; weight <= w; ++weight)
		{
			if(weight == 0)
			{
				dp[i][weight] = 0;
				continue;
			}

			int pick = val[i];

			if(weight - wt[i] < 0)
			{
				pick = -1e9;
			}
			else if(i + 1 == n || weight - wt[i] == 0)
			{
				pick += 0;
			}
			else
			{
				pick += dp[i + 1][weight - wt[i]];
			}

			int skip = i + 1 < n ? dp[i + 1][weight] : 0;

			dp[i][weight] = max(pick, skip);
		}
	}
	return dp[0][w];
}

signed main() {
	int n;
	cin >> n;
	vector<int> val(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> val[i];
	}
	vector<int> wt(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> wt[i];
	}
	int w = 0;
	cin >> w;

	vector<vector<int>> dp(n, vector<int>(w + 1, -1));

	// int ans = recur(val, 0, w, wt);

	// int ans = memo(val, 0, w, wt, dp);

	int ans = tab(val, w, wt, dp);


	cout << ans << endl;

	return 0;
}