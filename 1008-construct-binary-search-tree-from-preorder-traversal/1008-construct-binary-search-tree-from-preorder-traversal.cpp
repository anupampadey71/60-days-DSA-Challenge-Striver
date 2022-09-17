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
    TreeNode* solve(vector<int> &arr, int &i, int bound){
    if(i == arr.size() || arr[i]>bound) return NULL;
    
    TreeNode* root = new TreeNode(arr[i++]);
    
    root->left = solve(arr, i, root->val);
    root->right = solve(arr, i, bound);
    
    return root;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        int bound = 100000;
        return solve(preorder, i, bound);
    }
};