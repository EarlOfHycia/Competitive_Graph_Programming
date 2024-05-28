class Solution {
public:
    TreeNode* search(TreeNode* root, int val) {
        if (root==nullptr) return nullptr;
        if(root->val == val) return root;
        TreeNode* l = search(root->left,val);
        TreeNode* r = search(root->right,val);
        if(l) return l;
        if(r) return r;
        else return nullptr;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        TreeNode *lp,*lq,*rp,*rq;
        
        lp = search(root->left,p->val);

        if(lp!=nullptr){
            lq = search(root->left,q->val);
        }
        if(lp && lq){
            return lowestCommonAncestor(root->left,p,q);
        }
        
        rp = search(root->right,p->val);

        if(rp!=nullptr){
            rq = search(root->right,q->val);
        } 
        if(rp && rq){
            return lowestCommonAncestor(root->right,p,q);
        } 
        return root;
    }
};
