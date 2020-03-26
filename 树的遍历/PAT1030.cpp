#include <bits/stdc++.h>
using namespace std;
const int maxn=25;
struct node{
    char data[15];
    int left,right;
}Tree[maxn];
void inorder(int root,int depth)  //根节点和叶子节点不加括号
{
    if(root==-1) return;

    if(depth!=1&&(Tree[root].left!=-1||Tree[root].right!=-1))
        printf("(");
    inorder(Tree[root].left,depth+1);
    printf("%s",Tree[root].data);
    inorder(Tree[root].right,depth+1);
    if(depth!=1&&(Tree[root].left!=-1||Tree[root].right!=-1))
        printf(")");
}
int main()
{
    int n,root;
    scanf("%d",&n);
    int flag[n+1]={0};
    for(int i=1;i<=n;i++)
    {
        scanf("%s%d%d",Tree[i].data,&Tree[i].left,&Tree[i].right);
        if(Tree[i].left!=0) flag[Tree[i].left]=1;
        if(Tree[i].right!=0) flag[Tree[i].right]=1;
    }
    for(int i=1;i<=n;i++){
        if(flag[i]==0)
        {
            root=i;
            break;
        }
    }
    inorder(root,1);
    return 0;
}
