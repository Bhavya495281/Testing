#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* construct(int arr[], int n) {
    if (n == 0) return NULL;

    queue<Node*> q;
    Node* root = new Node(arr[0]);
    q.push(root);

    int i = 1;
    int j = 2;

    while (!q.empty() && i < n) {
        Node* temp = q.front();
        q.pop();

        Node* l = NULL;
        Node* r = NULL;

        if (i < n && arr[i] != INT_MIN) l = new Node(arr[i]);
        if (j < n && arr[j] != INT_MIN) r = new Node(arr[j]);

        temp->left = l;
        temp->right = r;

        if (l) q.push(l);
        if (r) q.push(r);

        i += 2;
        j += 2;
    }

    return root;
}

bool isLeaf(Node* root) {
    return (root->left == NULL && root->right == NULL);
}

void leftboundary(Node* root) {
    Node* curr = root->left;
    while (curr) {
        if (!isLeaf(curr)) cout << curr->val << " ";
        if (curr->left) curr = curr->left;
        else curr = curr->right;
    }
}

void bottomBoundary(Node* root) {
    if (root == NULL) return;
    if (isLeaf(root)) {
        cout << root->val << " ";
        return;
    }
    bottomBoundary(root->left);
    bottomBoundary(root->right);
}

void rightboundary(Node* root) {
    vector<int> temp;
    Node* curr = root->right;
    while (curr) {
        if (!isLeaf(curr)) temp.push_back(curr->val);
        if (curr->right) curr = curr->right;
        else curr = curr->left;
    }
    for (int i = temp.size() - 1; i >= 0; i--) {
        cout << temp[i] << " ";
    }
}

void boundaryTraversal(Node* root) {
    if (root == NULL) return;
    if (!isLeaf(root)) cout << root->val << " "; // print root if not leaf
    leftboundary(root);
    bottomBoundary(root);
    rightboundary(root);
}

int main() {
    int arr[] = {
        1, 2, 3, 4, 5, INT_MIN, 6, 7, INT_MIN, 8, 9, 10, 11, INT_MIN, 12, 
        INT_MIN, 13, INT_MIN, 14, 15, 16, INT_MIN, 17, INT_MIN, INT_MIN, 18, 
        INT_MIN, 19, INT_MIN, INT_MIN, INT_MIN, 20, 21, 22, 23, INT_MIN, 24, 
        25, 26, 27, INT_MIN, INT_MIN, INT_MIN, 28, INT_MIN, INT_MIN
    };
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* root = construct(arr, n);

    cout << "Boundary Traversal: ";
    boundaryTraversal(root);
    cout << endl;

    return 0;
}
