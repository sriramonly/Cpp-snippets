int isHeightBalancedRec(TreeNode* root, bool &isbal) {
        if(root==NULL) return true;
        int l = isHeightBalancedRec(root->left, isbal);
        int r = isHeightBalancedRec(root->right, isbal);
        if(abs(l-r) > 1) isbal = false;
        return 1+ max(l, r);
}
