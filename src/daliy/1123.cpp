class Solution {
    public:
        TreeNode* lcaDeepestLeaves(TreeNode* root) {
            return dfs(root).second;
        }
    
    private:
        pair<int, TreeNode*> dfs(TreeNode* node) {
            if (!node) return {0, nullptr};
            auto left = dfs(node->left);   // 左子树深度及候选LCA
            auto right = dfs(node->right); // 右子树深度及候选LCA
            
            // 当前子树最大深度
            int max_depth = max(left.first, right.first) + 1;
            
            // 若左右子树深度相同，当前节点为LCA
            if (left.first == right.first) {
                return {max_depth, node};
            } 
            // 否则继承较深子树的LCA
            else if (left.first > right.first) {
                return {max_depth, left.second};
            } else {
                return {max_depth, right.second};
            }
        }
    };