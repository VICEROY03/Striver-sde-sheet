class Solution {
public:
    void sortColors(vector<int>& nums) {
        int c[3]={0}, n=nums.size(), indx=0;
        for(int i=0; i<n; i++)
            c[nums[i]]++;
        for(int i=0; i<3; i++){
            while(c[i]--){
                nums[indx]=i;
                indx++;
            }
        }
    }
};