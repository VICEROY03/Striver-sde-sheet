class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        dp[0]=0;
        
        for(int i=1; i<=amount; i++){
            for(int c: coins){
                if(c<=i && dp[i-c]!=-1){
                    if(dp[i]==-1)
                        dp[i]=1+dp[i-c];
                    else
                        dp[i]=min(dp[i], 1+dp[i-c]);
                }
            }
        }
        
        return dp[amount];
    }
};