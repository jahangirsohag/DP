class Solution {
  public:
    // int recur(string &s1, string &s2, int i, int j, int asf, vector<vector<vector<int>>> &dp)
    // {
    //     if(i == s1.size() || j == s2.size()) return asf;
        
    //     int inc = 0;
        
    //     if(dp[i][j][asf] != -1) return dp[i][j][asf];
        
    //     if(s1[i] == s2[j])
    //     {
    //         inc = recur(s1, s2, i + 1, j + 1, asf + 1, dp);
    //     }
        
    //     int excs2 = recur(s1, s2, i, j + 1, 0, dp);
    //     int excs1 = recur(s1, s2, i + 1, j, 0, dp);
        
    //     return dp[i][j][asf] = max(max(inc, asf), max(excs2, excs1));
    // }
    int longestCommonSubstr(string& s1, string& s2) {
        // int n = s1.size();
        // int m = s2.size();
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(min(n,m), -1)));
        // return recur(s1, s2, 0, 0, 0, dp);
        int n = s1.size();
        int m = s2.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        for(int i = n - 1; i >= 0; --i)
        {
            for(int j = m - 1; j >= 0; --j)
            {
                if(s1[i] == s2[j])
                {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
            }
        }
        int asf = 0;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                asf = max(asf, dp[i][j]);
            }
        }
        return asf;
    }
};










