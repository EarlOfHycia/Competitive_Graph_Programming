#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    queue<pair<int,int>> q;
    pair<int,int> A,B;
    char a[n][m];
    int dist[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            if(a[i][j]=='A'){
                A=make_pair(i,j);
            }
            if(a[i][j]=='B'){
                q.push(B=make_pair(i,j));
                dist[i][j]=0;
                continue;
            }
            
            if(a[i][j]=='#'){
                dist[i][j]=-1;
            }
            else{
                dist[i][j]=m*n;
            }
        }
    }
    while(!q.empty()){
        int l1 = q.size();
        for(int i=0;i<l1;i++){
            pair<int,int> temp = q.front();
            int x = temp.first;
            int y = temp.second;
            
            if(x-1>=0 && a[x-1][y]!='#' && dist[x-1][y]>dist[x][y] + 1){
                dist[x-1][y]=dist[x][y] + 1;
                q.push(make_pair(x-1, y));
            }
            if(x+1<n && a[x+1][y]!='#' && dist[x+1][y]>dist[x][y] + 1){
                dist[x+1][y]=dist[x][y] + 1;
                q.push(make_pair(x+1, y));
            }
            if(y-1>=0 && a[x][y-1]!='#' && dist[x][y-1]>dist[x][y] + 1){
                dist[x][y-1]=dist[x][y] + 1;
                q.push(make_pair(x, y-1));
            }
            if(y+1<m && a[x][y+1]!='#' && dist[x][y+1]>dist[x][y] + 1){
                dist[x][y+1]=dist[x][y] + 1;
                q.push(make_pair(x, y+1));
            }
            q.pop();
        }
    }
//    for(int i=0;i<n;i++){
//        for(int j=0;j<m;j++){
//            cout<<dist[i][j]<<"\t";
//        }
//        cout<<"\n";
//    }
    int x,y;
    x = A.first;
    y = A.second;
    if(dist[x][y]==m*n){
        cout<<"NO\n";
    }
    else{
        int d = dist[x][y];
        cout<<"YES\n"<<d<<"\n";
        string str(d,'0');
        for(int i=0;i<d;i++){
            if(x-1>=0  && dist[x-1][y]==dist[x][y]-1){
                str[i]='U';
                x--;
            }
            else if(x+1<n && dist[x+1][y]==dist[x][y]-1){
                str[i]='D';
                x++;
            }
            else if(y-1>=0 && dist[x][y-1]==dist[x][y]-1){
                str[i]='L';
                y--;
            }
            else{
                if(y+1<m){
                    str[i]='R';
                    y++;
                }    
            }
        }
        cout<<str<<"\n";
    }
    return 0;
}
