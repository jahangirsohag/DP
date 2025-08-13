#include <iostream>
#include <vector>

using namespace std;

const int N = 1e9 + 7;

bool recur(vector<int> &vec, int i, int sum)
{
	if(sum == 0) return true;

	if(sum < 0) return false;

	if(i == vec.size()) return false;

	bool include = recur(vec, i + 1, sum - vec[i]);
	bool exclude = recur(vec, i + 1, sum);

	return include || exclude;
}

bool memo(vector<int> &vec, int i, int sum, vector<vector<int>> &dp)
{
	if(sum == 0) return true;

	if(sum < 0) return false;

	if(i == vec.size()) return false;

	if(dp[i][sum] != 0) return dp[i][sum] = 1;

	bool include = memo(vec, i + 1, sum - vec[i], dp);
	bool exclude = memo(vec, i + 1, sum, dp);

	dp[i][sum] = include || exclude ? 1 : -1;

	return dp[i][sum];
}

int tab(vector<int> &vec, int sum, vector<vector<bool>> &dp)
{
	int n = vec.size();

	for(int i = 0; i <= n; ++i)
	{
		dp[i][0] = true;
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= sum; ++j)
		{
			//If do not come/include
			bool dont = dp[i - 1][j];

			//If want to come/include, then remain sum
			int me = vec[i - 1];

			bool coming = j - me >= 0 ? dp[i - 1][j - me] : false;

			dp[i][j] = coming || dont;
		}
	}
	return dp[n][sum];
}

signed main() {
	int n;
	cin >> n;
	vector<int> vec(n, 0);
	for(int i = 0; i < n; ++i)
	{
		cin >> vec[i];
	}
	int sum;
	cin >> sum;

	// vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

	vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, 0));

	// bool ans = recur(vec, 0 , sum);

	// bool ans = memo(vec, 0, sum, dp);

	// if(ans) cout << "True" << endl;
	// else cout << "False" << endl;

	bool ans = tab(vec, sum, dp);

	if(ans) cout << "True" << endl;
	else cout << "NO" << endl;

	return 0;
}