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
    ll dfs(TreeNode *a){
        if(!a) return 0;
        ll sm = a->val;
        if(a->left) sm += dfs(a->left);
        if(a->right) sm += dfs(a->right);
        return sm;
    }

    ll ans = 0;
    
    ll dfs2(TreeNode *a, ll n){
        if(!a) return 0;
        ll sm = a->val;
        if(a->left){
            ll q = dfs2(a->left, n);
            ans = max(ans, (n-q) * q);
            sm += q;
        }
        if(a->right){
            ll q = dfs2(a->right, n);
            ans = max(ans, (n-q) * q);
            sm += q;
        }
        return sm;
    }

    int maxProduct(TreeNode* root) {
        ans = 0;
        ll n = dfs(root);
        dfs2(root, n);
        const ll mod = 1e9 + 7;
        return ans % mod;
    }
};