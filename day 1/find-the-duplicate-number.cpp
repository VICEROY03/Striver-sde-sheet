class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        vector<int> m(n,0);
        for(int i=0; i<n; i++){
            if(m[nums[i]])
                return nums[i];
            else
                m[nums[i]]++;
        }
        return -1;
    }
};