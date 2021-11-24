#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
using namespace std;

struct node
{
    int val;
    node *left;
    node *right;
    int height;

    node(int v)
    {
        val = v;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

class avl
{
private:
    int max(int x, int y) { return (x > y) ? x : y; }
    int getHeight(node *n)
    {
        if (n == nullptr)
            return 0;
        return n->height;
    }
    int getBalance(node *n)
    {
        if (n == nullptr)
            return 0;
        return getHeight(n->left) - getHeight(n->right);
    }

public:
    node *rotateRight(node *y)
    {
        node *x = y->left;
        node *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    node *rotateLeft(node *x)
    {
        node *y = x->right;
        node *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    node *insert(node *n, int val)
    {

        // ======== Normal BST insertion ==========
        if (n == nullptr)
            return new node(val);

        if (val < n->val)
            n->left = insert(n->left, val);
        if (val > n->val)
            n->right = insert(n->right, val);
        else
            return n;
        // =========================================

        // Update the height of the ancestor node
        n->height = 1 + max(getHeight(n->left), getHeight(n->right));
        // get the balance of the current node to see if it's unbalanced
        int balance = getBalance(n);

        // Left Left case
        if (balance > 1 && val < n->left->val)
            return rotateRight(n);

        // Right Right case
        if (balance < -1 && val > n->right->val)
            return rotateLeft(n);

        // Left Right case
        if (balance > 1 && val > n->left->val)
        {
            n->left = rotateLeft(n->left);
            return rotateRight(n);
        }

        // Right Left case
        if (balance < -1 && val < n->right->val)
        {
            n->right = rotateRight(n->right);
            return rotateLeft(n);
        }

        return n;
    }

    void bfs(ofstream &file, node *root)
    {

        if (root == nullptr)
            return;

        queue<node *> q;
        q.push(root);

        while (!q.empty())
        {
            node *curr = q.front();
            file << curr->val << " ";
            q.pop();

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
};
