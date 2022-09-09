
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        vector<vector<int>> dp(n+1, vector<int>(k+1, INT_MAX-1));
        for(int i=0; i<=n; i++)
            dp[i][0]=0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=k; j++){
                for(int f=1; f<=j; f++){
                    dp[i][j] = min(dp[i][j], 1+max(dp[i-1][f-1], dp[i][j-f]));
                }
            }
        }
        return dp[n][k];
    }