#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inorder(TreeNode * root, vector<int> &result) {
    if (root == NULL)
        return;

    inorder(root -> left, result);
    result.push_back(root -> val);
    inorder(root -> right, result);
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    inorder(root, result);
    return result;
}

vector<int> preOrder(TreeNode * root) {
    vector<int> result;
    if(root == NULL) return;

    stack<TreeNode*> st;
    st.push(root);

    while(!st.empty()) {
        TreeNode* node = st.top();
        st.pop();

        result.push_back(node->val);

        if(node -> right != NULL) st.push(node -> right);
        if(node -> left != NULL) st.push(node -> left);

    }
}

vector<int> levelOrder(TreeNode * root) {
    vector<int> result;
    if(root == NULL) return result;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        int size = q.size();

        for(int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();

            if(node -> left != NULL) q.push(node -> left);
            if(node -> right != NULL) q.push(node -> right);

            result.push_back(node -> val);
        }
    }
}

int main() {

}