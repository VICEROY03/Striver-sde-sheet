
public:
    void subsetSum(vector<int> &arr, int l, int r, vector<int> &ans, int sum = 0)
    {
        // Print current subset
        if (l > r) {
            ans.push_back(sum);
            return;
        }
     
        // Subset including arr[l]
        subsetSum(arr, l + 1, r, ans, sum + arr[l]);
     
        // Subset excluding arr[l]
        subsetSum(arr, l + 1, r, ans, sum);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        subsetSum(arr, 0, N-1, ans);
        return ans;
    }