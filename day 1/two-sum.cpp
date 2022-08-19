class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        for(int i=0; i<n; i++)
            nums[i]+=nums[i]-target;
        unordered_map<int, int> m;
        for(int i=0; i<n; i++){
            if(m.find(-nums[i])!=m.end())
               return {m.find(-nums[i])->second, i};
            else
                m[nums[i]] = i;
        }
        return {};
    }
};