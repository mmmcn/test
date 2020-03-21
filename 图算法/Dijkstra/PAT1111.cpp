/*本题由于要找到两种根据不同指标确定的路径，因此应用了两次Dijkstra算法，并根据DFS遍历寻找同一类路径有多条时的最佳路径
感觉这么写可能代码量有些大，不过直观来看还是非常容易理解的*/

#include <bits/stdc++.h>
using namespace std;
const int maxn=505;
const int INF=0x7fffffff;
int Distance[maxn][maxn],Time[maxn][maxn];
bool visit[maxn]={false};
int d[maxn],t[maxn];
int st,goal;
vector<int>pre[maxn];
int n,m;
void Dijkstra(int s,int a[],int b[maxn][maxn])  //根据传入的数组来判断
{
    a[s]=0;
    for(int i=0;i<n;i++)
    {
        int u=-1,Min=INF;
        for(int j=0;j<n;j++)
        {
            if(visit[j]==false&&a[j]<Min)
            {
                u=j;
                Min=a[j];
            }
        }
        if(u==-1) return ;
        visit[u]=true;
        for(int v=0;v<n;v++)
        {
            if(visit[v]==false&&b[u][v]!=INF){
                if(a[u]+b[u][v]<a[v])
                {
                    a[v]=a[u]+b[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if(a[u]+b[u][v]==a[v])
                    pre[v].push_back(u);
            }
        }
    }
}
vector<int> tempath,pathBydis,pathBytime;
int minTime=INF,minNode=INF;
void DFSbyTime(int v)
{
    if(v==st){  //到达起始点
        tempath.push_back(st);
        int value=0;
        for(int i=tempath.size()-1;i>0;i--)
        {
            int id=tempath[i],next=tempath[i-1];
            value+=Time[id][next];
        }
        if(value<minTime){
            minTime=value;
            pathBydis=tempath;
        }
        tempath.pop_back();
        return ;
    }
    tempath.push_back(v);
    for(int i=0;i<pre[v].size();i++)
        DFSbyTime(pre[v][i]);
    tempath.pop_back();
}
void DFSbyNum(int v)
{
    if(v==st){  //到达起始点
        tempath.push_back(st);
        int value=tempath.size();
        if(value<minNode){
            minNode=value;
            pathBytime=tempath;
        }
        tempath.pop_back();
        return ;
    }
    tempath.push_back(v);
    for(int i=0;i<pre[v].size();i++)
        DFSbyNum(pre[v][i]);
    tempath.pop_back();
}
int main()
{

    scanf("%d%d",&n,&m);
    int v1,v2,dis,time;
    fill(Distance[0],Distance[0]+maxn*maxn,INF);
    fill(Time[0],Time[0]+maxn*maxn,INF);
    fill(d,d+maxn,INF);
    fill(t,t+maxn,INF);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%*d%d%d",&v1,&v2,&dis,&time);
        Distance[v1][v2]=dis;
        Distance[v2][v1]=dis;
        Time[v1][v2]=time;
        Time[v2][v1]=time;
    }
    scanf("%d%d",&st,&goal);
    Dijkstra(st,d,Distance);
    DFSbyTime(goal);
    fill(visit,visit+maxn,false);
    Dijkstra(st,t,Time);
    DFSbyNum(goal);
    if(pathBydis==pathBytime){
        printf("Distance = %d; Time = %d: %d",d[goal],t[goal],pathBydis[pathBydis.size()-1]);
        for(int i=pathBydis.size()-2;i>=0;i--)
            printf(" -> %d",pathBydis[i]);
    }
    else{
        printf("Distance = %d: %d",d[goal],pathBydis[pathBydis.size()-1]);
        for(int i=pathBydis.size()-2;i>=0;i--)
            printf(" -> %d",pathBydis[i]);
            printf("\n");
        printf("Time = %d: %d",t[goal],pathBytime[pathBytime.size()-1]);
        for(int i=pathBytime.size()-2;i>=0;i--)
            printf(" -> %d",pathBytime[i]);
    }
    printf("\n");
    return 0;
}
