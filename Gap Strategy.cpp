#include <iostream>

using namespace std;

signed main(){
	int n = 5;
	string s;
	cin >> s;

	int dp[5][5] = {
		{1,3,4,5, 6},
		{1,3,4,5, 6},
		{1,3,4,5, 6},
		{1,3,4,5, 6},
		{1,3,4,5, 6}
	};

	for(int gap = 0; gap < n; ++gap)
	{
		for(int i = 0, j = gap; j < n; ++i, ++j)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}


	return 0;
}