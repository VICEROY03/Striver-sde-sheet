class Solution {
public:
    int absMax(int x, int y){
        return (abs(x)>abs(y)) ? x : y;
    }
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int currMax[n];
        currMax[0]=nums[0];
        for(int i=1; i<n; i++){
            if(nums[i]==0)
                currMax[i]=0;
            else
                currMax[i]=absMax(nums[i], currMax[i-1]*nums[i]);
        }
        bool neg=1;
        int low;
        int ans=currMax[0];
        if(ans<0){
            low = ans;
            neg = 0;
        }
        for(int i=1; i<n; i++){
            if(currMax[i]==0)
                neg=1;
            else if(currMax[i]<0){
                if(neg)
                    low = currMax[i];
                else
                    ans = max(ans, currMax[i]/low);
                if(low<currMax[i])
                    low = currMax[i];
                neg=0;
            }
            ans = max(ans, currMax[i]);
        }
        return ans;
    }
};