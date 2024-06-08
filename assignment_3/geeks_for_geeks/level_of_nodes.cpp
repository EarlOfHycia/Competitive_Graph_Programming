class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X){
	    if(X>=V) return -1;
	    
	    queue<int> q;
	    int dist[V];
	    for(int i=0;i<V;i++){
	        dist[i]=V;
	    }
	    int depth=1;
	    dist[0]=0;
	    q.push(0);
	    while(!q.empty()){
	        int l = q.size();
	        for(int i=0;i<l;i++){
	            int temp = q.front();
	            q.pop();
	            int len = adj[temp].size();
	            for(int j=0;j<len;j++){
	                if(dist[adj[temp][j]]>dist[temp]+1){
	                    dist[adj[temp][j]]=dist[temp]+1;
	                    q.push(adj[temp][j]);
	                }
	            }
	        }
	        depth++;
	    }
	    
	    return dist[X]==V?-1:dist[X];
	}
};