TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;

        if((root->val - p->val)*(root->val - q->val)<=0) return root;

        if((root->val > p->val)>0 && (root->val - q->val)>0) return lowestCommonAncestor(root->left,p,q);

        if((root->val - p->val)<0 && (root->val - q->val)<0) return lowestCommonAncestor(root->right,p,q);

    }