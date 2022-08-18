
class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        int p[n], ans=0;
        unordered_map<int, int> m;
        p[0] = A[0];
        m[p[0]]=0;
        for(int i=1; i<n; i++){
            p[i] = p[i-1] + A[i];
            if(p[i]==0){
                ans = i+1;
                continue;
            }
            if(m.find(p[i])!=m.end())
                ans = max(abs((m.find(p[i]))->second-i), ans);
            else
                m[p[i]] = i;
        }
        return ans;
    }
};
