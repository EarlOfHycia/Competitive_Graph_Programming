// this code is showing memory limit exceded on leetcode but running just fine on local compiler
 // also when solving this question and other questions on leetcode of this assignment...
 //leetcode was running sluggishly overall like slow response time and even tle on model solutions...
 //may be due server load...
 //cause my internet was not slow (100mbps)...

class Solution {
public:
 vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
     int m = image.size();
     int n = image[0].size();
     queue<pair<int,int>> q;
     q.push(make_pair(sr,sc));
     int oc = image[sr][sc];
     image[sr][sc]=color;
     while(!q.empty()){
         int l = q.size();
         for(int i=0;i<l;i++){
             pair<int,int> temp = q.front();
             q.pop();
             int x = temp.first;
             int y = temp.second;
             if(x-1>=0 && image[x-1][y]==oc){
                 q.push(make_pair(x-1,y));
                 image[x-1][y]=color;
             }
             if(x+1<m && image[x+1][y]==oc){
                 q.push(make_pair(x+1,y));
                 image[x+1][y]=color;
             }
             if(y-1>=0 && image[x][y-1]==oc){
                 q.push(make_pair(x,y-1));
                 image[x][y-1]=color;
             }
             if(y+1<n && image[x][y+1]==oc){
                 q.push(make_pair(x,y+1));
                 image[x][y+1]=color;
             }
         }
     }
     return image;
 }
};
