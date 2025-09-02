class Solution {
  public:
    int maxSumIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 0);
        
        dp[0] = arr[0];
        
        for(int i = 0; i < n; ++i)
        {
            int bestOfPrev = 0;
            for(int j = i - 1; j >= 0; --j)
            {
                if(arr[j] < arr[i])
                {
                    bestOfPrev = max(bestOfPrev, dp[j]);
                }
            }
            dp[i] = bestOfPrev + arr[i];
        }
        int maxi = 0;
        for(int i = 0; i < n; ++i)
        {
            if(dp[i] > maxi)
            {
                maxi = dp[i];
            }
        }
        return maxi;
    }
};