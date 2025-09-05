class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int osp = 0, oep = 0;
        int len = 0;

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for(int gap = 0; gap < n; ++gap)
        {
            for(int sp = 0, ep = gap; ep < n; ++sp, ++ep)
            {
                if(sp == ep) dp[sp][ep] = true;
                else if(sp + 1 == ep) dp[sp][ep] = s[sp] == s[ep] ? true : false;
                else
                {
                    if(s[sp] == s[ep] && dp[sp + 1][ep - 1] == true) dp[sp][ep] = true;
                }
                if(dp[sp][ep] == true && ep - sp + 1 > len)
                {
                    len = ep - sp + 1;
                    osp = sp;
                    oep = ep;
                }
            }
        }
        return s.substr(osp, len);
    }
};