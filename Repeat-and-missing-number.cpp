vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int n=A.size(), a;
    vector<int> B(n+1, 0); // 10e9 * 10e9 = long
    for(int i=0; i<n; i++){
        if(B[A[i]])
            a=A[i];
        else   
            B[A[i]]++;
    }
    for(int i=1; i<n+1; i++)
        if(!B[i]){
            return {a, i};
        }
}
