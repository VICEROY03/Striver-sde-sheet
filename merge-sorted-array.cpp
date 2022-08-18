class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m==0){
            nums1=nums2;
            return;
        }
        int last=n+m-1, l1=m-1, l2=n-1;
        while(l1>=0 || l2>=0){
            if(l1<0){
                while (last>=0){
                    nums1[last]=nums2[l2];l2--;last--;
                }
                return;
            }
            if(l2<0) return;
            if(nums1[l1]<nums2[l2]){
                nums1[last] = nums2[l2];
                last--;
                l2--;
            }
            else{
                nums1[last] = nums1[l1];
                last--;
                l1--;
            }
        }
    }
};