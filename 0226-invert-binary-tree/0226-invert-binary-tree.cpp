/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // 1. Base Case: Guard against empty nodes
        if (root == nullptr) {
            return nullptr;
        }

        // 2. The Swap: Using the standard library
        std::swap(root->left, root->right);

        // 3. The Recursion: Dive into the children
        invertTree(root->left);
        invertTree(root->right);

        // 4. Return the newly inverted root
        return root;
    }
};