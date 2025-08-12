#include <iostream>
#include <vector>

using namespace std;

const int N = 1e9 + 7;

int recur(vector<vector<int>> &grid, int i, int j)
{
	int m = grid.size();
	int n = grid[0].size();

	if(i >= m || j >= n) return 0;

	if(grid[i][j] == 1) return 0;

	if(i == m - 1 && j == n - 1) return 1;

	int right = recur(grid, i, j + 1);
	int down = recur(grid, i + 1, j);

	return right + down;
}

int memo(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp)
{
    int n = grid.size();
    int m = grid[0].size();

    if(i == n || j == m) return 0;

    if(grid[i][j] == 1) return 0;

    if(i == n - 1 && j == m - 1) return 1;

    if(dp[i][j] != -1) return dp[i][j];

    int right = memo(grid, i, j + 1, dp);
    int left = memo(grid, i + 1, j, dp);

    dp[i][j] = right + left;

    return dp[i][j];
}

 int tab(vector<vector<int>> &grid, vector<vector<long long>> &dp)
{
    int n = grid.size();
    int m = grid[0].size();

    for(int i = n - 1; i >= 0; --i)
    {
        for(int j = m - 1; j >= 0; --j)
        {
        	if(grid[i][j] == 1)
            {
            	dp[i][j] = 0;
                continue;
            }
            if(i == n - 1 && j == m - 1)
            {
                dp[i][j] = 1;
                continue;
            }
           
            long long right = j + 1 < m ? dp[i][j + 1] : 0;
            long long left = i + 1 < n ? dp[i + 1][j] : 0;

            dp[i][j] = right + left;
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

	vector<vector<long long>> dp(n, vector<long long>(m, -1));

	// int ans = recur(grid, 0, 0);

	// int ans = memo(grid, 0, 0, dp);

	int ans = tab(grid, dp);

	cout << ans << endl;

	return 0;
}