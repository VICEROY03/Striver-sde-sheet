class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int average = target/4;
        if(average > nums[nums.size()-1]){
            return res;
        }
        for(int i=0; i<nums.size(); i++){
            if(average < nums[i]){
                break;
            }
            if(i==0 || nums[i]!=nums[i-1]){
                for(int j=i+1; j<nums.size(); j++){
                    if(j == i+1 || nums[j]!=nums[j-1]){
                        int low = j+1, high = nums.size()-1;
                        while(low<high){
                            long long x = (long)nums[i]+(long)nums[j]+(long)nums[low]+(long)nums[high];
                            if( x == target){
                                vector<int> v = {nums[i], nums[j], nums[low], nums[high]};
                                res.push_back(v);
                                while(low<high && nums[low]==nums[low+1])low++;
                                while(low<high && nums[high]==nums[high-1])high--;
                                low++, high--;
                            }
                            else if(x < target)
                                low++;
                            else
                                high--;
                        }
                    }
                }
            }
        }
        
        return res;
    }
};