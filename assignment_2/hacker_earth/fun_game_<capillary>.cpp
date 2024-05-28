#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

int main(){

    int n;
    cin>>n;
    int a[n];
    vi ans;
    int temp;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int l=0,r=n-1;
    
    while(l<n && r>=0){
        if(a[l]<a[r]){
            ans.push_back(2);
            l++;
        }
        else if(a[l]>a[r]){
            ans.push_back(1);
            r--;
        }
        else{
            l++;
            r--;
            ans.push_back(0);
        }
    }

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
