/*通过此题掌握BST的建立和二叉树各种遍历方式*/

#include <bits/stdc++.h>
using namespace std;
const int maxn=1010;
struct Node{
    int data;
    Node* left;
    Node* right;
};
int maxDepth=-1;
int n1=0,n2=0;
void Insert(Node* &root,int data,int depth)
{
    if(depth>maxDepth)
        maxDepth=depth;
    if(root==NULL)
    {
        Node* temp=new Node();
        temp->left=NULL;
        temp->right=NULL;
        temp->data=data;
        root=temp;
        return ;
    }
    if(data<=root->data){
        Insert(root->left,data,depth+1);
    }
    else{
        Insert(root->right,data,depth+1);
    }
}
void getResult(Node* root,int depth)
{
    if(root==NULL) return ;
    getResult(root->left,depth+1);
    if(depth==maxDepth) n1++;
    if(depth==maxDepth-1) n2++;
    getResult(root->right,depth+1);


}
int main()
{
    int n,data;
    scanf("%d",&n);
    Node* root=NULL;
    for(int i=0;i<n;i++){   //建立BST,插入过程中记录最大深度
        scanf("%d",&data);
        Insert(root,data,1);
    }
    getResult(root,1);
    printf("%d + %d = %d\n",n1,n2,n1+n2);
    return 0;
}
