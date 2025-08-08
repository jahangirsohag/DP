#include <iostream>
#include <vector>

using namespace std;

const int N = 1e9 + 7;

int recur(vector<int> &arr, int i)
{
	if(i == arr.size()) return 0;
	if(i > arr.size()) return N;

	int ip1 = recur(arr, i + 1);
	int ip2 = recur(arr, i + 2);

	return min(ip1, ip2) + arr[i];
}

int memo(vector<int> &arr, int i, vector<int> &dp)
{
	if(i == arr.size()) return 0;
	if(i > arr.size()) return N;

	if(dp[i] != -1) return dp[i];

	int ip1 = memo(arr, i + 1, dp);
	int ip2 = memo(arr, i + 2, dp);

	dp[i] = min(ip1, ip2) + arr[i];

	return dp[i];
}

int tab(vector<int> &arr, vector<int> &dp)
{
	int n = arr.size();
	for(int i = 0; i < n; ++i)
	{
		if(i == 0)
		{
			dp[i] = arr[0];
			continue;
		}
		if(i == 1)
		{
			dp[i] = arr[1];
			continue;
		}

		dp[i] = min(dp[i - 2], dp[i - 1]) + arr[i];
	}
	return min(dp[n - 1], dp[n - 2]);
}
signed main() {

	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	vector<int> dp(n + 1, -1);

	// int ans = min(recur(arr, 0), recur(arr, 1));

	// int ans = min(memo(arr, 0, dp), memo(arr, 1, dp));

	int ans = tab(arr, dp);


	cout << ans << endl;



	return 0;
}