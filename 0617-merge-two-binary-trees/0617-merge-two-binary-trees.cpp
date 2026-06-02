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
class Solution { // IN-PLACE solution O(1) memory ,, O(N+M) TC
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        // 1. If t1 is missing this branch, just plug in t2's branch!
        // (If both are null, this safely returns null)
        if (t1 == nullptr) {
            return t2;
        }

        // 2. If t2 is missing a branch, we don't need to do anything.
        // Just keep t1's existing branch exactly as it is.
        if (t2 == nullptr) {
            return t1;
        }

        // 3. Both nodes exist. Mutate t1 by adding t2's value to it.
        t1->val += t2->val;

        // 4. Recursively traverse and merge the left and right children
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);

        // Return the mutated original tree
        return t1;
    }
};