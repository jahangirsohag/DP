#include <iostream>
#include <vector>

using namespace std;

const int N = 1e9 + 7;

int recur(vector<int> &coins, int i, int amount)
{
	if(amount == 0) return 1;

	if(amount < 0) return 0;

	if(i == coins.size()) return 0;

	int stay = recur(coins, i, amount - coins[i]);
	int moveToNext = recur(coins, i + 1, amount);

	return stay + moveToNext;
}

int memo(vector<int> &coins, int i, int amount, vector<vector<int>> &dp)
{
	if(amount == 0) return 1;

	if(amount < 0) return 0;

	if(i == coins.size()) return 0;

	if(dp[i][amount] != -1) return dp[i][amount];

	int stay = memo(coins, i, amount - coins[i], dp);
	int moveToNext = memo(coins, i + 1, amount, dp);

	dp[i][amount] = stay + moveToNext;

	return dp[i][amount];
}

int tab(vector<int> &coins, int amount, vector<vector<int>> &dp)
{
	int n = coins.size();

	for(int i = n - 1; i >= 0; --i)
	{
		for(int amt = 0; amt <= amount; ++amt)
		{
			if(amt == 0)
			{
				dp[i][amt] = 1;
				continue;
			}

			int stay = amt - coins[i] >= 0 ? dp[i][amt - coins[i]] : 0;
			int moveToNext = i + 1 < n ? dp[i + 1][amt] : 0;

			dp[i][amt] = stay + moveToNext;
		}
	}
	return dp[0][amount];
}
signed main() {
	int n;
	cin >> n;
	vector<int> coins(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> coins[i];
	}
	int sum;
	cin >> sum;

	vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

	// int ans = memo(coins, 0, sum, dp);

	int ans = tab(coins, sum, dp);

	cout << ans << endl;


	return 0;
}