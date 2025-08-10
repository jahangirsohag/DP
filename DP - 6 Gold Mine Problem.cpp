#include <iostream>
#include <vector>

using namespace std;

const int N = 1e9 + 7;

int recur(vector<vector<int>> &mat, int i, int j)
{
	int n = mat.size();
	int m = mat[0].size();

	if(i >= n || i < 0 || j >= m) return 0;
        
    if(j == m - 1) return mat[i][j];
    
    int right = recur(mat, i, j + 1);
    int diagonallyUp = recur(mat, i - 1, j + 1);
    int diagonallyDown = recur(mat, i + 1, j + 1);

    return max(max(diagonallyUp, diagonallyDown), right) + mat[i][j];
}

int memo(vector<vector<int>> &mat, int i, int j, vector<vector<int>> &dp)
{
	int n = mat.size();
	int m = mat[0].size();

	if(i >= n || i < 0 || j >= m) return 0;
        
    if(j == m - 1) return mat[i][j];
    
    if(dp[i][j] != -1) return dp[i][j];
    
    int right = memo(mat, i, j + 1, dp);
    int diagonallyUp = memo(mat, i - 1, j + 1, dp);
    int diagonallyDown = memo(mat, i + 1, j + 1, dp);
    
    dp[i][j] = max(max(diagonallyUp, diagonallyDown), right) + mat[i][j];
    
    return dp[i][j];
}

int tab(vector<vector<int>> &mat, vector<vector<int>> &dp)
{
	int n = mat.size();
	int m = mat[0].size();

	for(int i = n - 1; i >= 0; --i)
	{
		for(int j = m - 1; j >= 0; --j)
		{
		    if(j == m - 1) dp[i][j] = mat[i][j];
		    
		    int right = (j + 1 < m) ? dp[i][j + 1] : 0;
		    int diagonallyUp = (i > 0 && j + 1 < m) ? dp[i - 1][j + 1] : 0;
		    int diagonallyDown = (i < n - 1 && j + 1 < m) ? dp[i + 1][j + 1] : 0;
		    
		    dp[i][j] = max(max(diagonallyUp, diagonallyDown), right) + mat[i][j];
		}
	}
	int max = 0;
	for(int i = 0; i < n; ++i)
	{
		if(dp[i][0] > max)
		{
			max = dp[i][0];
		}
	}
}

signed main() {

	int n, m;
	cin >> n >> m;

	vector<vector<int>> mat(n, vector<int>(m, -1));

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			cin >> mat[i][j];
		}
	}

	vector<vector<int>> dp(n, vector<int>(m, -1));

	int max = 0;

	for(int i = 0; i < n; ++i)
	{
		int a = tab(mat, dp);

		if(a > max)
		{
			max = a;
		}
	}

	cout << max << endl;

	return 0;
}
