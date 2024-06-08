class Solution {
public:

    bool visited[200000] = {false};
    vector<int> ed[200000];

    bool validPath(int n, vector<vector<int>>& edges, int source,int destination) {
        int l = edges.size();
        for(int i=0;i<l;i++){
            ed[edges[i][0]].push_back(edges[i][1]);
            ed[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int> q;
        q.push(source);
        visited[source] = true;
        while(!q.empty()){
            int len = q.size();
            for(int i=0;i<len;i++){
                int temp = q.front();
                q.pop();
                int l = ed[temp].size();
                for(int j=0;j<l;j++){
                    if(!visited[ed[temp][j]]){
                        visited[ed[temp][j]] = true;
                        q.push(ed[temp][j]);
                    }
                }
            }
        }
        return visited[destination];
    }
};