class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0, ans=0;
        for(int x: nums){
            if(x)
                cnt++;
            else{
                ans = max(cnt, ans);
                cnt = 0;
            }
        }
        return max(ans, cnt);
    }
};