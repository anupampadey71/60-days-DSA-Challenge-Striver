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
private:
    TreeNode* solve(vector<int> &arr, int e, int s){
    if(s>e)
        return NULL;
    
    int mid = (s+e)/2;
    TreeNode* root = new TreeNode(arr[mid]);
    root->left = solve(arr, mid-1, s);
    root->right = solve(arr, e, mid+1);
    return root;
}
public:
    TreeNode* sortedArrayToBST(vector<int>& arr) {
        int n=arr.size();
        return solve(arr,n-1,0);
    }
};