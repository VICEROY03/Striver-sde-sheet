double findNthRootOfM(int n, int m) {
	// Write your code here.
    double error=0.0000001, temp;
    double l=0, r=m, mid=(r+l)/2;
        temp = mid;
    bool f;
    while (!f || abs(m-temp)>error){ 
        mid=(r+l)/2;
        temp = mid;
        f=1;
        for(int i=1; i<n; i++){
            temp = temp*mid;
//             cout << l <<"-" << r << '/'<<temp<<'/'<<mid<<'\n';
            if(temp>m){
                r=mid;
                f=0;
                break;
            }
        }
        if(f)
            l=mid;
    }
    
    return mid;
}