#include <iostream>
#include <vector>

using namespace std;

const int N = 1e9 + 7;

int recur(vector<int> &vec, int sum)
{
	if(sum == 0) return 0;
	if(sum < 0) return N;

	int ans = N;
	for(int coin : vec)
	{
		int remainSum = sum - coin;
		int minCount = recur(vec, remainSum);
		ans = min(ans, minCount);
	}
	return ans + 1;
}

int memo(vector<int> &vec, int sum, vector<int> &dp)
{
	if(sum == 0) return 0;
	if(sum < 0) return N;

	if(dp[sum] != -1) return dp[sum];

	int ans = N;
	for(int coin : vec)
	{
		int remainSum = sum - coin;
		int minCount = memo(vec, remainSum, dp);
		ans = min(ans, minCount);
	}

	dp[sum] = ans + 1;

	return dp[sum];
}

int tab(vector<int> &vec, int sum, vector<int> &dp)
{
	for(int i = 0; i <= sum; ++i)
	{
		if(i == 0)
		{
			dp[i] = 0;
			continue;
		}

		int ans = N;
		for(int coin : vec)
		{
			int remainSum = i - coin;
			int minCount = remainSum >= 0 ? dp[remainSum] : N; //memo(vec, remainSum, dp);
			ans = min(ans, minCount);
		}
		dp[i] = ans + 1;
	}
	return dp[sum];
}
signed main() {

	int n;
	cin >> n;
	vector<int> vec(n, 0);
	for(int i = 0; i < n; ++i)
	{
		cin >> vec[i];
	}
	int sum = 0;
	cin >> sum;

	// int ans = recur(vec, sum);

	vector<int> dp(sum + 1, N);

	int ans = tab(vec, sum, dp);

	if(ans >= 1e9) cout << -1 << endl;
	else cout << ans << endl;

	return 0;
}