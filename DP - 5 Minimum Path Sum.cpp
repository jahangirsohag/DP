#include <iostream>
#include <vector>

using namespace std;

const int N = 1e9 + 7;

int recur(vector<vector<int>> &grid, int i, int j)
{
	int n = grid.size();
	int m = grid[0].size();

	if(i >= n  || j >= m) return 1e9;

	if(i == n - 1 && j == m - 1) return grid[i][j];

	int right = recur(grid, i, j + 1);
	int down = recur(grid, i + 1, j);

	return min(right, down) + grid[i][j];
}

int memo(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp)
{
	int n = grid.size();
	int m = grid[0].size();

	if(i >= n || j >= m) return 1e9;

	if(i == n - 1 && j == m - 1) return grid[i][j];

	if(dp[i][j] != -1) return dp[i][j];

	int right = memo(grid, i, j + 1, dp);
	int down = memo(grid, i + 1, j, dp);

	dp[i][j] = min(right, down) + grid[i][j];

	return dp[i][j];
}

int tab(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp)
{
	int n = grid.size();
	int m = grid[0].size();

	for(int i = n - 1; i >= 0; --i)
	{
		for(int j = m - 1; j >= 0; --j)
		{
			if(i == n - 1 && j == m - 1)
			{
				dp[i][j] = grid[i][j];
				continue;
			}

			int right = j + 1 < m ? dp[i][j + 1] : 1e9;
			int down = i + 1 < n ? dp[i + 1][j] : 1e9;

			dp[i][j] = min(right, down) + grid[i][j];
		}
	}
	return dp[0][0];
}

signed main() {

	int n, m;
	cin >> n >> m;

	vector<vector<int>> grid(n, vector<int>(m, -1));

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			cin >> grid[i][j];
		}
	}

	vector<vector<int>> dp(n, vector<int>(m, -1));

	// int ans = recur(grid, 0, 0);

	// int ans = memoization(grid, 0, 0, dp);

	int ans = tab(grid, 0, 0, dp);

	cout << ans << endl;

	return 0;
}