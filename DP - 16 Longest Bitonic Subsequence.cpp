
class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &arr) {
        // code here
        vector<int> dp_l2r(n, 0);
        dp_l2r[0] = 1;
        for(int i = 1; i < n; ++i)
        {
            int bestOfPrev = 0;
            for(int j = i - 1; j >= 0; --j)
            {
                if(arr[i] > arr[j])
                {
                    bestOfPrev = max(bestOfPrev, dp_l2r[j]);
                }
            }
            dp_l2r[i] = bestOfPrev + 1;
        }
        vector<int> dp_r2l(n, 0);
        dp_r2l[n - 1] = 1;
        for(int i = n - 2; i >= 0; --i)
        {
            int bestOfPrev = 0;
            for(int j = i + 1; j < n; ++j)
            {
                if(arr[i] > arr[j])
                {
                    bestOfPrev = max(bestOfPrev, dp_r2l[j]);
                }
            }
            dp_r2l[i] = bestOfPrev + 1;
        }
        int ans = 0;
        for(int i = 0; i < n; ++i)
        {
            int left = dp_l2r[i];
            int right = dp_r2l[i];
            //If i act as a middle of the bitonic subsequence
            int lenIfImMid = 0;
            if(left > 1 && right > 1)
            {
                lenIfImMid = left + right - 1;
            }
            ans = max(lenIfImMid, ans);
        }
        return ans;
    }
};
