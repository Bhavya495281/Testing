#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>
using namespace std;
class Node { // this is a tree node
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
void display(Node* root) {
    if(root == NULL) return;
    cout << root->val << " ";
    display(root->left);
    display(root->right);
}
int level(Node* root) {
    if(root == NULL) return 0;
    return 1 + max(level(root->left), level(root->right));
}
void nthlevel(Node* root, int curr, int targetLevel) {
    if(root == NULL) return;
    if(curr == targetLevel) {
        cout << root->val << " ";
        return;
    }
    nthlevel(root->left, curr + 1, targetLevel);
    nthlevel(root->right, curr + 1, targetLevel);
}
void lorder(Node* root) { // Level order using nthlevel
    int h = level(root);
    for(int i = 1; i <= h; i++) {
        nthlevel(root, 1, i);
        cout << endl;
    }
}
void levelOrderQueue(Node* root) { // Level order using queue
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);
    while(q.size()>0) {
        Node* temp = q.front();
        q.pop();
        cout << temp->val << " ";
        if(temp->left != NULL) q.push(temp->left);
        if(temp->right != NULL) q.push(temp->right);
    }
}
int main() {
    Node* a = new Node(1); // a is the root node
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);
    Node* g = new Node(7);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    display(a);
    cout << endl;
    cout << "Height of tree: " << level(a) << endl;
    cout << "Level order traversal (recursive nthlevel):" << endl;
    lorder(a);
    cout << "\nLevel order traversal (using queue):" << endl;
    levelOrderQueue(a);
}
