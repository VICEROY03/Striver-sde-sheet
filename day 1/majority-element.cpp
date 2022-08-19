class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans=nums[0], n=nums.size(), cnt=1;
        for(int i=1; i<n; i++){
            if(nums[i]!=ans){
                cnt--;
                if(cnt==0){
                    ans = nums[i];
                    cnt++;
                }
            }
            else
                cnt++;
        }
        return ans;
    }
};