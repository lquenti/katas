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
    int maxProduct(TreeNode *root) {
        fill_map(root);
        
        long long root_val = sum_of_subtree[root];
        long long current_best{0};
        std::stack<TreeNode *> s;
        if (root->left) s.push(root->left);
        if (root->right) s.push(root->right);
        while (!s.empty()) {
            auto curr{s.top()};
            s.pop();
            
            auto this_and_below{sum_of_subtree[curr]};
            auto above{root_val-this_and_below};
            current_best = std::max(current_best, this_and_below*above);
            
            if (curr->left) s.push(curr->left);
            if (curr->right) s.push(curr->right);
        }
        return current_best % static_cast<int>(1e9 + 7);
    }
private:
    void fill_map(TreeNode *root) {
        long long left_val = 0;
        long long right_val = 0;
        if (root->left) {
            fill_map(root->left);
            left_val = sum_of_subtree[root->left];
        }
        if (root->right) {
            fill_map(root->right);
            right_val = sum_of_subtree[root->right];
        }

        sum_of_subtree[root] = left_val + right_val + root->val;
    }
    std::map<TreeNode *, long long> sum_of_subtree{};
    
};