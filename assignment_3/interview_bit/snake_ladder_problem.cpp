vector<int> find(vector<vector<int>>a, int first,int size){
    for(int i=0;i<size;i++){
        if(a[i][0]==first) return a[i];
    }
}


int Solution::snakeLadder(vector<vector<int> > &a, vector<vector<int> > &b){
    
    int board[101]={0};
    for(int i=2;i<101;i++){
        board[i]=100;
    }
    int ladders = a.size();
    for(int i=0;i<ladders;i++){
        board[a[i][0]]=101;
    }
    int snakes = b.size();
    for(int i=0;i<snakes;i++){
        board[b[i][0]]=-1;
    }
    
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        if(board[100]!=100) return board[100];
        int l = q.size();
        for(int i=0;i<l;i++){
            int temp = q.front();
            q.pop();
            for(int i=1;i<=6;i++){
                if(temp+i<=100){
                    if(board[temp+i]==-1){
                    int tindex=find(b,temp+i,snakes)[1];
                    if(board[tindex]>board[temp]+1){
                        board[tindex]=board[temp]+1;
                        q.push(tindex);
                    }
                }
                else if(board[temp+i]==101){
                    int tindex=find(a,temp+i,ladders)[1];
                    if(board[tindex]>board[temp]+1){
                        board[tindex]=board[temp]+1;
                        q.push(tindex);
                    }
                }
                else if(board[temp+i]>board[temp]+1){
                    board[temp+i]=board[temp]+1;
                    q.push(temp+i);
                }
            }
                }
                
        }
    }
    return board[100]==100?-1:board[100];
}
