class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> v;
        if(root==nullptr) return v;
        q.push(root);
        TreeNode* tem;
        int par=0;
        while(!q.empty()){
            int l = q.size();
            vector<int> temp;
        for(int i=0;i<l;i++){
            tem = q.front();
            if(tem->left!=nullptr) q.push(tem->left);
            if(tem->right!=nullptr) q.push(tem->right);
            
            if(par%2) temp.insert(temp.begin(),tem->val);
            else temp.push_back(tem->val);
            q.pop();
        }
        v.push_back(temp);
        par++;
        }
         return v;
    }
};
