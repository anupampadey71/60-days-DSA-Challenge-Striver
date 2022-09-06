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
    int findPos(vector<int> inorder, int element, int n){
    for(int i = 0; i < n; i++){
        if(element == inorder[i])
            return i;
    }
    return -1;
}
TreeNode* solve(vector<int>& postOrder, vector<int>& inOrder, int &index, int inorderStart, int inorderEnd, int n){
    if( index < 0 || inorderStart > inorderEnd){
        return NULL;
    }
    
    int element = postOrder[index--];
    TreeNode* root = new TreeNode(element);
    int pos = findPos(inOrder, element, n);
    
    root->right = solve(postOrder, inOrder, index, pos+1, inorderEnd, n);
    root->left = solve(postOrder, inOrder, index, inorderStart, pos-1, n);
    
    return root;
    
} 

TreeNode* buildTree(vector<int>& inOrder, vector<int>&  postOrder) 
{   int n = postOrder.size();
    int postorderIndex = n-1;
	TreeNode* ans = solve(postOrder, inOrder, postorderIndex, 0, n-1, n);
    return ans;
}
    
    
};