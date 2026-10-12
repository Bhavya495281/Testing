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
void display(Node* root){
if(root==NULL) return;
cout<<root->val<<" ";
display(root->left);
display(root->right);
}
int sum(Node* root)
{if(root==NULL) return 0;
int ans=root->val+sum(root->left)+sum(root->right);
return ans;
}
int product(Node* root)
{if(root==NULL) return 1;
int ans=root->val*product(root->left)*product(root->right);
return ans;
}
int minIn(Node* root)
{if(root==NULL) return INT_MAX;
int lmax=minIn(root->left);
int rmax=minIn(root->right);
return min(root->val,min(lmax,rmax));
}
int maxIn(Node* root)
{if(root==NULL) return INT_MIN;
int lmax=maxIn(root->left);
int rmax=maxIn(root->right);
return max(root->val,max(lmax,rmax));
}
int size(Node* root)
{if(root==NULL) return 0;
int count=1+size(root->left)+size(root->right);
return count;}
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
    display(a);
    cout<<endl;
    cout<<size(a);
    cout<<endl;
    cout<<sum(a);
    cout<<endl;
    cout<<product(a);
    cout<<endl;
    cout<<minIn(a);
    cout<<endl;
    cout<<maxIn(a);
    cout<<endl;
    cout<<size(a);
}