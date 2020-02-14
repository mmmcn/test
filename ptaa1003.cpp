#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 1000000000

const int MAXV=510;
struct Node{
    int v;    //边的目标顶点
    int dis;
};
int G[MAXV][MAXV];           /*邻接矩阵实现*/
//vector<Node> G[MAXV];
int n;  //顶点数
int d[MAXV];    //起点到达各点的最短路径长度
int num[MAXV];       //标记从起点到其余节点的路径条数
int weight[MAXV];
int w[MAXV];
bool vis[MAXV]={false};

void Dijkstra(int s)
{
    fill(d,d+MAXV,INF);
    fill(num,num+MAXV,0);
    fill(w,w+MAXV,0);
    d[s]=0;
    w[s]=weight[s];
    num[s]=1;
    for(int i=0;i<n;i++)       //n次循环
    {
        int u=-1;
        int MIN=INF;
        for(int j=0;j<n;j++)  //找到未访问顶点中距离最小的
        {
            if(vis[j]==false&&d[j]<MIN)
            {
                u=j;
                MIN=d[j];
            }
        }
        if(u==-1)
            return ;
        vis[u]=true; //标记下一个顶点已经访问
        //邻接表实现
        /*for(int j=0;j<G[u].size();j++)
        {
            int v=G[u][j].v;
            if(vis[v]==false)
            {
                if(d[u]+G[u][j].dis<d[v])
                {
                    d[v]=d[u]+G[u][j].dis;
                    w[v]=w[u]+weight[v];
                    num[v]=num[u];
                }
                else if(d[u]+G[u][j].dis==d[v])
                {
                    if(w[u]+weight[v]>w[v])
                        w[v]=w[u]+weight[v];
                    num[v]+=num[u];
                }
            }
        }*/
        //邻接矩阵实现
        for(int v=0;v<n;v++)
        {
            if(vis[v]==false&&G[u][v]!=INF)
            {
                if(d[u]+G[u][v]<d[v])
                {
                    d[v]=d[u]+G[u][v];
                    w[v]=w[u]+weight[v];
                    num[v]=num[u];
                }
                else if(d[u]+G[u][v]==d[v])
                {
                    if(w[u]+weight[v]>w[v])
                        w[v]=w[u]+weight[v];
                    num[v]+=num[u];
                }
            }
        }
    }
}
int main()
{
    int m,start,end;
    scanf("%d%d%d%d",&n,&m,&start,&end);
    for(int i=0;i<n;i++)
        scanf("%d",&weight[i]);
    fill(G[0],G[0]+MAXV*MAXV,INF);
    int u,v;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&u,&v);
        scanf("%d",&G[u][v]);
        G[v][u]=G[u][v];
    }
    /*for(int i=0;i<m;i++)
    {
        int a,b,dist;
        struct Node temp1;
        struct Node temp2;
        scanf("%d%d%d",&a,&b,&dist);              //本题属于无向图，第一次看作有向图了，用邻接矩阵赋值方便
        temp1.v=b;
        temp1.dis=dist;
        temp2.v=a;
        temp2.dis=dist;
        G[a].push_back(temp1);
        G[b].push_back(temp2);
    }*/
    Dijkstra(start);
    printf("%d %d\n",num[end],w[end]);
    return 0;
}

