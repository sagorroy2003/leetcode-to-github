/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    int dfs(TreeNode* node, int& max_diameter) {

        if (node == NULL) {
            return 0;
        }

        int left_h = dfs(node->left, max_diameter);
        int right_h = dfs(node->right, max_diameter);

        max_diameter = max(max_diameter, left_h + right_h);

        // returing the height of parent 
        return max(left_h, right_h) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int max_diameter = 0;

        dfs(root, max_diameter);

        return max_diameter;
    }
};