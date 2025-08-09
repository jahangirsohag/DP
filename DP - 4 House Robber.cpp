#include <iostream>
#include <vector>

using namespace std;

const int N = 1e9 + 7;

int recur(vector<int> &arr, int i)
{
	if(i >= arr.size()) return 0;

	int include = recur(arr, i + 2) + arr[i];
	int exclude = recur(arr, i + 1);

	return max(include, exclude);
}

int memo(vector<int> &arr, int i, vector<int> &dp)
{
	if(i >= arr.size()) return 0;

	if(dp[i] != -1) return dp[i];

	int include = memo(arr, i + 2, dp) + arr[i];
	int exclude = memo(arr, i + 1, dp);

	dp[i] = max(include, exclude);

	return dp[i];
}

int tab(vector<int> &arr, vector<int> &dp)
{
	for(int i = dp.size() - 1; i >= 0; --i)
	{
		if(i >= arr.size())
		{
			dp[i] = 0;
			continue;
		}

		int include = dp[i + 2] + arr[i];
		int exclude = dp[i + 1];

		dp[i] = max(include, exclude);
	}
	return dp[0];
}
signed main() {

	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	vector<int> dp(n + 2, -1);

	// int ans = max(memo(arr, 0, dp), memo(arr, 1, dp));a

	int ans = tab(arr, dp);



	cout << ans << endl;




	return 0;
}