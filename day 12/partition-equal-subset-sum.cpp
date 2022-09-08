class Solution {
public:    
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int x: nums)
            sum+=x;
        if(sum&1)
            return 0;
        sum /=2;
        int n=nums.size();
        bool dp[20000+1]={0};
        dp[0]=1;
        for(int x:nums){
            for(int j=sum; j>=0; j--){
                if(j>=x)
                    dp[j] = dp[j] || dp[j-x];
            }
        }
        return dp[sum];
    }
};