class Solution {
  public:
    class Box{
        int h;
        int w;
        int l;
        
        Box(int h, int w, int l)
        {
            this->h = h;
            this->w = w;
            this->l = l;
        }
    };
    
    int maxHeight(vector<int> &height, vector<int> &width, vector<int> &length) {
        vector<Box> vec;
        
        for(int i = 0; i < n; ++i)
        {
            int h = height[i];
            int w = width[i];
            int l = length[i];
            
            vec.push_back(Box(h, min(w, l), max(w, l)));
            vec.push_back(Box(w, min(h, l), max(h, l)));
            vec.push_back(Box(l, min(h, w), max(h, w)));
        }
        
        sort(vec.begin(), vec.end(), [](Box &a, Box &b){
            return (a.l * a.w) < (b.l * b.w);
        });
        
        int N = vec.size();
        vector<int> dp(N, 0);
        
        dp[0] = vec[0].h;
        
        
        for(int i = 0; i < N; ++i)
        {
            int bestOfPrev = 0;
            for(int j = i - 1; j >= 0; --j)
            {
                if(vec[i].w > vec[j].w && vec[i].l > vec[j].l)
                {
                    bestOfPrev = max(bestOfPrev, dp[j]);
                }
            }
            dp[i] = bestOfPrev + vec[i].h;
        }
        return *max_element(vec.begin(), vec.end());
    }
};

















