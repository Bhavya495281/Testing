#include<iostream>
using namespace std;
class Node{
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val=val;
        this->left=NULL;
        this->right==NULL;
    }
};

void preorder(Node* root)
{if(root==NULL) return;
cout<<root->val<<" ";
preorder(root->left);
preorder(root->right);}
void inorder(Node* root)
{if(root==NULL) return;
inorder(root->left);
cout<<root->val<<" ";
inorder(root->right);}
void postorder(Node* root)
{if(root==NULL) return;
postorder(root->left);
postorder(root->right);
cout<<root->val<<" ";}
int main()
{Node* a=new Node(1);
Node* b=new Node(1);
Node* c=new Node(1);
Node* d=new Node(1);
Node* e=new Node(1);
Node* f=new Node(1);
a->left=b;
a->right=c;
b->left=b;
b->right=c;
c->left=b;
c->right=c;
preorder(a);
cout<<endl;
inorder(a);
cout<<endl;
postorder(a);
return 0;
}