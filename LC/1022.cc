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

void cheat_recursion(std::vector<int> &digits, int &res, TreeNode *n) {
    if (!n) {
        return;
    }
    digits.push_back(n->val);
    if (!n->left && !n->right) {
        // leaf
        int cnt{0};
        for (const int &x: digits) {
            cnt <<= 1;
            cnt+=x;
        }
        res+=cnt;
    }
    cheat_recursion(digits, res, n->left);
    cheat_recursion(digits, res, n->right);
    digits.pop_back();
}

class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        int res{0};
        std::vector<int> digits{};
        cheat_recursion(digits, res, root);
        return res;
    }
};
