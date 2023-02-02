#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *random;
    TreeNode() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right, TreeNode *random) : val(x), left(left), right(right), random(random) {}
};

void populateRandomPointer(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<TreeNode *> Q;
    Q.push(root);
    TreeNode* prev;
    while (!Q.empty())
    {
        int size = Q.size();
        for (int i = 0; i < size; i++)
        {
            root = Q.front();
            Q.pop();

            if (i == 0)
            {
                prev = root;
            } 
            else 
            {
                prev->random = root;
                prev = root;
            }

            if (root->left != NULL)
            {
                Q.push(root->left);
            }

            if (root->right != NULL)
            {
                Q.push(root->right);
            }
        }
        
    }
}
