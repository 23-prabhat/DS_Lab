#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int x) {
    Node* n = new Node;
    n->data = x;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
}






// python
// class Node:
//     def __init__(self, x):
//         self.data = x
//         self.left = None
//         self.right = None

// def preorder(root):
//     if root:
//         print(root.data, end=" ")
//         preorder(root.left)
//         preorder(root.right)

// def inorder(root):
//     if root:
//         inorder(root.left)
//         print(root.data, end=" ")
//         inorder(root.right)

// def postorder(root):
//     if root:
//         postorder(root.left)
//         postorder(root.right)
//         print(root.data, end=" ")

// root = Node(1)
// root.left = Node(2)
// root.right = Node(3)
// root.left.left = Node(4)
// root.left.right = Node(5)

// preorder(root)
// print()
// inorder(root)
// print()
// postorder(root)
