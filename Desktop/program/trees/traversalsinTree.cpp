#include<iostream>
#include<climits>
using namespace std;
class Node{//this is a tree node
public:
int val;
Node* left;
Node* right;
Node(int val)
{this->val=val;
this->left=NULL;
this->right=NULL;
}
};
void Preorder(Node* root){
if(root==NULL) return;
cout<<root->val<<" ";
Preorder(root->left);
Preorder(root->right);
}
void Inorder(Node* root){
if(root==NULL) return;
Inorder(root->left);
cout<<root->val<<" ";
Inorder(root->right);
}
void Postorder(Node* root){
if(root==NULL) return;
Postorder(root->left);
Postorder(root->right);
cout<<root->val<<" ";
}
int main()
{   Node* a=new Node(1);//a is the root node
    Node* b=new Node(2);
    Node* c=new Node(3);
    Node* d=new Node(4);
    Node* e=new Node(5);
    Node* f=new Node(6);
    Node* g=new Node(7);
    a->left=b;
    a->right=c;
     b->left=d;
    b->right=e;
     c->left=f;
    c->right=g;
    Preorder(a);
cout<<endl;
Inorder(a);
cout<<endl;
Postorder(a);
}