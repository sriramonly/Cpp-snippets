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

// check if leaf value sequence(from left to right) of two different trees is the same
    int dfs(stack<TreeNode*> &stk) {
        while(true){
            TreeNode* node = stk.top();
            stk.pop();           
            if(node->right) stk.push(node->right);
            if(node->left) stk.push(node->left);
            if(!node->left and !node->right) return node->val;
        }
    }
bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> stk1, stk2;
        stk1.push(root1);
        stk2.push(root2);
        while(!stk1.empty() and !stk2.empty()){
            if(dfs(stk1) != dfs(stk2)) return false;
        }
        return stk1.empty() and stk2.empty();
}


    // shuffle an array
    vector<int> shuffle() {
         int i,j;
         vector<int> arr;
         for (i = arr.size() - 1; i > 0; i--) {
            j = rand() % (i + 1);
            swap(arr[i], arr[j]);
         }
         return arr;    
    }


    // Max path sum in a binary tree: any node to any node
    // s -> INT_MIN to begin with
    int dfs(TreeNode* root, int &s) {
        if(!root) return 0;
        int ls = max(0,dfs(root->left, s));
        int rs = max(0, dfs(root->right, s));
        s = max(s, ls+rs+root->val);
        return max(ls, rs)+root->val;
    }
