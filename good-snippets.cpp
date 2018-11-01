int isHeightBalancedRec(TreeNode* root, bool &isbal) {
        if(root==NULL) return true;
        int l = isHeightBalancedRec(root->left, isbal);
        int r = isHeightBalancedRec(root->right, isbal);
        if(abs(l-r) > 1) isbal = false;
        return 1+ max(l, r);
}

//Move all zeroes to end of list
void moveZeroes(vector<int>& nums) {
        int j=0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]!=0) {
                swap(nums[i], nums[j]);
                ++j;
            }
        }
}
