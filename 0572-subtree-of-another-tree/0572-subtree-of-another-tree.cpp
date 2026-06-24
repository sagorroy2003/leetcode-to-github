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
public:
    bool isSameTree(TreeNode* root1, TreeNode* root2) {
        // both matched...
        if (root1 == NULL && root2 == NULL)
            return true;

        // if one is NULL
        if (root1 == NULL || root2 == NULL)
            return false;

        if (root1->val != root2->val)
            return false;

        return (isSameTree(root1->left, root2->left) &&
                isSameTree(root1->right, root2->right));
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // if the main tree is null then there will no subtree
        if (root == nullptr)
            return false;

        // if matching root... then run Validator function ...
        // and return true... if it satisfy
        if (root->val == subRoot->val && isSameTree(root, subRoot)) {
            return true;
        }

        // contunue scanning left and right subtree
        return (isSubtree(root->left, subRoot) ||
                isSubtree(root->right, subRoot));
    }
};