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

typedef long long ll;

class Solution {
public:
    vector <ll> v;
    
    void dfs(TreeNode *cur, int dp = 0){
        if(!cur) return;
        if(v[dp] == INT_MIN) v[dp] = 0;
        v[dp] += cur->val; 
        if(cur->left) dfs(cur->left, dp+1);
        if(cur->right) dfs(cur->right, dp+1);
    }

    int maxLevelSum(TreeNode* root) {
        v.clear();
        v.resize(10001, INT_MIN);
        dfs(root);
        int mx = INT_MIN;
        int id = -1;
        for(int i = 0; i < v.size(); ++i){
            if(v[i] > mx){
                mx = v[i];
                id = i+1;
            }
        }
        return id;
    }
};