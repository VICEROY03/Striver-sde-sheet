class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size(), l=0;
        unordered_map<int, int> m;
        for(int i=0; i<n; i++){
            if(!m[nums[i]]){
                nums[l]=nums[i];
                l++;
                m[nums[i]]++;
            }
        }
        return l;
    }
};