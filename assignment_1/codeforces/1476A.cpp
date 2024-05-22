#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
 
 
using namespace std;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin>>t;
    
    while(t--){
        long long int n,k;
        cin>>n>>k;
        
        if(n>=k){
            cout<<(n%k?2:1)<<"\n";
        }
        else{
            cout<< (k%n ? k/n +1 : k/n)<<"\n";
        }
    }
    return 0;
}
