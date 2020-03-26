//先建立BST，然后中序遍历，依次赋值即可
#include <bits/stdc++.h>
using namespace std;
const int maxn=25;
struct Node{
    int data,height;
    Node *left,*right;
};
Node* newNode(int v)      //生成新节点
{
    Node* node=new Node;
    node->data=v;
    node->height=1;
    node->left=node->right=NULL;
    return node;
}
int getHeight(Node* root)
{
    if(root==NULL) return 0;
    return root->height;
}
int getBalanceFactor(Node* root)
{
    return getHeight(root->left)-getHeight(root->right);
}
void updateHeight(Node* root)
{
    root->height=max(getHeight(root->left),getHeight(root->right))+1;
}
void L(Node* &root)//左旋
{
    Node* temp=root->right;
    root->right=temp->left;
    temp->left=root;
    updateHeight(root);
    updateHeight(temp);
    root=temp;
}
void R(Node* &root)  //右旋
{
    Node* temp=root->left;
    root->left=temp->right;
    temp->right=root;
    updateHeight(root);
    updateHeight(temp);
    root=temp;
}
void Insert(Node* &root,int data)
{
    if(root==NULL){
        root=newNode(data);
        return;
    }
    if(data<root->data)
    {
        Insert(root->left,data);
        updateHeight(root);
        if(getBalanceFactor(root)==2){
            if(getBalanceFactor(root->left)==1)
                R(root);
            else if(getBalanceFactor(root->left)==-1)
            {
                L(root->left);
                R(root);
            }
        }
    }
    else
    {
        Insert(root->right,data);
        updateHeight(root);
        if(getBalanceFactor(root)==-2){
            if(getBalanceFactor(root->right)==1)
            {
                R(root->right);
                L(root);
            }
            else if(getBalanceFactor(root->right)==-1)
                L(root);
        }
    }
}
int main()
{
    int n,data;
    scanf("%d",&n);
    Node* root=NULL;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&data);
        Insert(root,data);
    }
    printf("%d\n",root->data);
    return 0;
}
