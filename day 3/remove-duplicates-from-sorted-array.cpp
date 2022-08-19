class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size(), l=0;
        if(n==1) return 1;
        for(int i=1; i<n; i++){
            if(nums[i]!=nums[l]){
                swap(nums[l+1], nums[i]);
                l++;
            }
        }
        return l+1;
    }
};