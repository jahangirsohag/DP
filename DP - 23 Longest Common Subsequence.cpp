class Solution {
public:
    int recur(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
    {
        if(i == s1.size() || j == s2.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]) return recur(s1, s2, i + 1, j + 1, dp) + 1;

        int exci = recur(s1, s2, i + 1, j, dp);
        int excj = recur(s1, s2, i, j + 1, dp);

        return dp[i][j] = max(exci, excj);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        for(int i = n - 1; i >= 0; --i)
        {
            for(int j = m - 1; j >= 0; --j)
            {
                if(text1[i] == text2[j])
                {
                    dp[i][j] = 1 + (i + 1 < n && j + 1 < m ? dp[i + 1][j + 1] : 0);
                    continue;
                }

                int excI = i + 1 < n ? dp[i + 1][j] : 0;
                int excJ = j + 1 < m ? dp[i][j + 1] : 0;

                dp[i][j] = max(excI, excJ);
            }
        }
        return dp[0][0];
    }
};