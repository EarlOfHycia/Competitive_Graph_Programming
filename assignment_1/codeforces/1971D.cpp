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
        string s;
        cin>>s;
        int l = s.length();
        int cut_count=0;
        int count_01=0;
        for(int i=1;i<l;i++){
            if(s[i]=='0' && s[i-1]=='1'){
                cut_count++;
            }
            if(s[i]=='1' && s[i-1]=='0'){
                count_01++;
            }
        }
        cout<<cut_count+1+(count_01-1 > 0?count_01 - 1:0)<<"\n";
    }
    return 0;
}
