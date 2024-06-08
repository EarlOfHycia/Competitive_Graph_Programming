int Solution::solve(int a, vector<vector<int> > &b) {
    bool visited[a+1];
    for(int i=1;i<=a;i++){
        visited[i] = false;
    }
    visited[1]=true;
    bool flag=true;
    int m = b.size();
    while(flag){
        flag=false;
        for(int i=0;i<m;i++){
            if(visited[b[i][0]]==true && visited[b[i][1]]==false){
                visited[b[i][1]]=true;
                flag=true;
            }
            if(visited[a]) return 1;
        }
    }
    return 0;
}
