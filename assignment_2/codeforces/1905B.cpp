#include <iostream>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int leaf[n+1];
        for(int i=0;i<=n;i++){
            leaf[i]=0;
        }
        int a,b;
        for(int i=0;i<n-1;i++){
            cin>>a>>b;
            if(leaf[a]<2) leaf[a]++;
            if(leaf[b]<2) leaf[b]++;
        }
        int leaves=0;
        for(int i=0;i<=n;i++){
            if(leaf[i]==1){
                leaves++;
            }
        }
        cout<<(leaves+1)/2<<"\n";
    }
    return 0;
}