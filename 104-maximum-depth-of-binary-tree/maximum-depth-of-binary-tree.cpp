class Solution {
public: 
    int maxDepth(TreeNode* root) {
        if (root == NULL){
            return 0;
        }
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        int ans = 1+max(lh,rh);
        return ans;
    }
};