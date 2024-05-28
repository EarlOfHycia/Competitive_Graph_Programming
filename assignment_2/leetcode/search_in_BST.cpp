class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root==nullptr) return nullptr;
        if(root->val == val) return root;
        TreeNode* l = searchBST(root->left,val);
        TreeNode* r = searchBST(root->right,val);
        if(l) return l;
        if(r) return r;
        else return nullptr;
    }
};
