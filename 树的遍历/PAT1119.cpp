/*数的问题主要通过递归来解决，还是要多练习，多理解递归在树这里的应用*/

#include <bits/stdc++.h>
using namespace std;
vector<int>in,pre,post;
bool flag=true;
void getInorder(int preLeft,int preRight,int postLeft,int postRight)
{
    if(preLeft==preRight){
        in.push_back(pre[preLeft]);
        return ;
    }
    if(pre[preLeft]==post[postRight]){
        int i=preLeft+1;
        while(i<=preRight&&pre[i]!=post[postRight-1]) i++;
        if(i-preLeft>1)   //能够确定左右子树
            getInorder(preLeft+1,i-1,postLeft,postLeft+(i-1-preLeft-1));
        else
            flag=false;
        in.push_back(post[postRight]);
        getInorder(i,preRight,postLeft+(i-1-preLeft),postRight-1);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    pre.resize(n);
    post.resize(n);
    for(int i=0;i<n;i++)
        scanf("%d",&pre[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&post[i]);
    getInorder(0,n-1,0,n-1);
    flag==true?printf("Yes\n%d",in[0]):printf("No\n%d",in[0]);
    for(int i=1;i<in.size();i++)
        printf(" %d",in[i]);
    printf("\n");
    return 0;
}
