int NthRoot(int n, int m) {
    long long int l=1,r=m,mid;

    while(l<=r){

        mid = (l+r)/2;
        long long int est = 1;
        for(int i=0;i<n;i++){
            est *= mid;
            if(est>m) break;
        }
        if(est==m){
            return mid;
        }
 
            if(est<m){
                l=mid+1;
            }
            else {
                r=mid-1;
            }
        

    }

    return -1;
}
