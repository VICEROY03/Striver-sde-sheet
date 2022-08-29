class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size(), temp;
        vector<int> ans(n,1);
        for(int i=n-2; i>=0; i--){
            temp = 1;
            for(int j=i+1; j<n; j++){
                if(nums[j]>nums[i])
                    temp = max(1+ans[j], temp);
            }
            ans[i] = temp;
        }
        return *max_element(ans.begin(), ans.end());
    }
};