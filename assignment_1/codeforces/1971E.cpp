#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
 
using namespace std;
 
long long int m_bin_search(long long int a[], long long int n, long long int x){
    long long int l=0,r=n-1,mid;
    
    while(l<=r){
        mid = l + (r-l)/2;
        if(a[mid]==x){
            while(a[mid-1]==a[mid]){
                mid--;
            }
            return mid;
        }
        
        else if(a[mid]<x){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return r;
}
 
 
 
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin>>t;
    
    while(t--){
        long long int n,k,q;
        cin>>n>>k>>q;
        long long int a[k+1],b[k+1];
        a[0]=b[0]=0;
        for(long long int i=1;i<k+1;i++){
            cin>>a[i];
        }
        for(long long int i=1;i<k+1;i++){
            cin>>b[i];
        }
        long long int d,index;
        while(q--){
            cin>>d;
            index = m_bin_search(a, k+1, d);
            cout<< b[index] + (a[index+1]-a[index]?(b[index+1] - b[index]) * (d-a[index]) / ( a[index+1] - a[index]):0)<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
