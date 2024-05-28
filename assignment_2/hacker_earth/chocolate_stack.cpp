#include <iostream>
#include <vector>

using namespace std;


int main(){
    
    int n;
    cin>>n;
    
    vector<int> v;
    int temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        if(temp){
            v.push_back(temp);
        }
        else{
            int l = v.back();
            cout<<l<<" ";
            v.pop_back();
        }
    }
    
}