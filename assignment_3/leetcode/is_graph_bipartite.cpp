pair<bool,int> check(vector<int> dist){
    int n = dist.size();
    for(int i=0;i<n;i++){
        if(dist[i]==n){
            return make_pair(true,i);
        }
    }
    return make_pair(false,-1);
}




class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph){
        int n = graph.size();
        queue<int> q;
        vector<int>dist(n,n);
        dist[0]=0;

        q.push(0);

        
        while(true){
        while(!q.empty()){
            int l = q.size();
            for(int i=0;i<l;i++){
                int temp = q.front();
                q.pop();
                int len = graph[temp].size();
                for(int j=0;j<len;j++){
                    if(dist[graph[temp][j]]>dist[temp]+1){
                        dist[graph[temp][j]]=dist[temp]+1;
                        q.push(graph[temp][j]);
                    }
                }
            }
        }
        pair<bool,int> temp = check(dist);
        if(!temp.first) break;
        else{
            dist[temp.second]=0;
            q.push(temp.second);
        }
    }

        for(int i=0;i<n;i++){
            int len = graph[i].size();
            for(int j=0;j<len;j++){
                if(dist[i]==dist[graph[i][j]]) return false;
            }
        }
        return true;
    }
};
