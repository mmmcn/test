/*本题限定了最大传播层数L，因此采用了BFS进行图的遍历
在遍历过程中需要记录已经遍历的层数，有两种方法
1>利用结构体存储节点的层数,遍历时只需要在达到下一节点时next.Layer=topNode.Layer+1
2>本题采用的方法二
*/
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int N=1010;
vector<int> G[N];
bool visited[N];
int result;
int L;
void BFS(int u)
{
    queue<int> q;
    q.push(u);
    visited[u]=true;
    //int last=u;        记录上一层中最后一个节点
    int depth=0;
    while(!q.empty())   //队列非空
    {
        depth++;
        if(depth-1==L)
            return ;
        int count=0;
        int size=q.size();

        while(count<size)   //弹出当前层所有节点
        {
            int u=q.front();
            q.pop();
            count++;
            for(int i=0;i<G[u].size();i++) //下一层邻接节点入队
            {
                int v=G[u][i];
                if(visited[v]==false)
                {
                    q.push(v);
                    visited[v]=true;
                    result++;
                }
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d%d",&n,&L);
    for(int i=1;i<=n;i++)         //对有向图的初始化
    {
        int num;
        scanf("%d",&num);
        int follow;
        for(int j=0;j<num;j++)
        {
            scanf("%d",&follow);
            G[follow].push_back(i);
        }
    }
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;i++)
    {
        int id;
        scanf("%d",&id);
        result=0;
        memset(visited,false,sizeof(visited));
        if(visited[id]==false)
            BFS(id);
        printf("%d\n",result);
    }
    return 0;
}

