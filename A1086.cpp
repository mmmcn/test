/*此题本质就是利用二叉树的中序和先序序列得到后序遍历序列
节点的入栈顺序其实就是二叉树的先序序列*/
#include <bits/stdc++.h>
using namespace std;
vector<int> pre,in,post,value;

void postorder(int root,int start,int end)
{
    if(start>end)
        return ;

    int i=start;
    while(i<end&&in[i]!=pre[root])
        i++;
    postorder(root+1,start,i-1);
    postorder(root+1+i-start,i+1,end);
    post.push_back(pre[root]);
}
int main()
{
    int n;
    scanf("%d",&n);
    char str[5];
    stack<int> s;
    int key=0;
    int N=2*n;
    while(N--)
    {
        scanf("%s",str);
        if(strlen(str)==4)
        {
            int num;
            scanf("%d",&num);
            value.push_back(num);
            pre.push_back(key);
            s.push(key++);
        }
        else
        {
            in.push_back(s.top());
            s.pop();
        }
    }
    postorder(0,0,n-1);
    printf("%d",value[post[0]]);
    for(int i=1;i<n;i++)
        printf(" %d",value[post[i]]);
    return 0;
}
