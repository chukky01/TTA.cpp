#include <iostream>   // console I/O (cout, cin)

using namespace std;   // pull standard-library names into scope

/* ========== BINARY-TREE NODE ========== */
struct Node {
    int data;        // payload stored in the node
    Node* left;      // pointer to left child (sub-tree)
    Node* right;     // pointer to right child (sub-tree)
};

/* ---------- Helper: allocate & initialise a new node ---------- */
Node* createNode(int data) {
    Node* newNode = new Node();   // heap allocation
    newNode->data = data;         // store payload
    newNode->left = newNode->right = nullptr;  // no children yet
    return newNode;
}

/* ---------- PRE-ORDER (Root-L-R) recursive traversal ---------- */
void printTree(Node* root) {
    if (root == nullptr) return;      // base case: empty sub-tree
    cout << root->data << endl;       // 1. visit current node (ROOT first)
    printTree(root->left);            // 2. traverse left branch
    printTree(root->right);           // 3. traverse right branch
}

/* ================== MAIN: BUILD A MANUAL BINARY TREE ================== */
int main() {
    /* ---- Level 1 (root) ---- */
    Node* root = createNode(1);   // root node with value 1

    /* ---- Level 2 (children of root) ---- */
    root->left  = createNode(2);  // left  child -> value 2
    root->right = createNode(3);  // right child -> value 3

    /* ---- Level 3 (grand-children) ---- */
    root->left->left  = createNode(4);   // left  child of node 2
    root->left->right = createNode(5);   // right child of node 2
    root->right->left  = createNode(6);  // left  child of node 3
    root->right->right = createNode(7);  // right child of node 3

    /* ---- Level 4 (great-grand-children) ---- */
    root->left->right->left  = createNode(9);   // left  child of node 5
    root->right->right->left = createNode(15);  // left  child of node 7

    /* ---- Pre-order traversal prints: 1 2 4 5 9 3 6 7 15 ---- */
    printTree(root);

    cin.get();  // pause console until Enter is pressed
    return 0;
}
/* Tree topology (manual 4-level binary tree):
                    1
                 /     \
               2         3
             /  \       / \
            4    5     6   7
                /         /
               9        15
Pre-order output: 1 2 4 5 9 3 6 7 15
*/
