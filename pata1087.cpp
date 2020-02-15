#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define INF 1000000000
const int MAXV=210;
string hashTtable[MAXV];

int countt=0;
map<string,int> hashTable;
vector<int> pre[MAXV];
int G[MAXV][MAXV];
int d[MAXV];
int num[MAXV];
bool vis[MAXV]={false};
int happ[MAXV];  //存放点权

int n,k,start;
void Dijkstra(int s)
{
    fill(d,d+MAXV,INF);
    fill(num,num+MAXV,0);
    d[s]=0;
    num[s]=1;
    for(int i=0;i<n;i++)
    {
        int u=-1;
        int MIN=INF;
        for(int j=0;j<n;j++)
        {
            if(vis[j]==false&&d[j]<MIN)
            {
                u=j;
                MIN=d[j];
            }
        }
        if(u==-1)
            return ;
        vis[u]=true;
        for(int v=0;v<n;v++)
        {
            if(vis[v]==false&&G[u][v]!=INF)
            {
                if(d[u]+G[u][v]<d[v])
                {
                    d[v]=d[u]+G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                    num[v]=num[u];
                }
                else if(d[u]+G[u][v]==d[v])
                {
                    pre[v].push_back(u);
                    num[v]+=num[u];
                }

            }
        }
    }
}

vector<int> path[MAXV],tempath;
int optValue=-INF;
void DFS(int v)
{
    if(v==start)//到达叶子节点
    {
        tempath.push_back(v);
        int value=0;
        for(int i=tempath.size()-2;i>=0;i--)
        {
            value+=happ[tempath[i]];
        }
        if(value>optValue)
        {
            optValue=value;
            path[countt++]=tempath;
        }
        tempath.pop_back();
        return ;
    }
    tempath.push_back(v);
    for(int i=0;i<pre[v].size();i++)
        DFS(pre[v][i]);
    tempath.pop_back();
}
int main()
{
    /*ROM对应11868*/
    fill(G[0],G[0]+MAXV*MAXV,INF);
    fill(happ,happ+MAXV,INF);
    string s;
    cin>>n>>k>>s;

    start=0;             //不管是是谁，都以0开始
    hashTable[s]=0;
    hashTtable[0]=s;
    for(int i=1;i<=n-1;i++)            /*输入ROM程序崩溃*/
    {
        string temp;
        cin>>temp;
        hashTable[temp]=i;
        hashTtable[i]=temp;
        cin>>happ[i];
    }
    string a,b;
    int s2ia,s2ib,cost;
    for(int i=0;i<k;i++)
    {
        cin>>a>>b>>cost;
        G[hashTable[a]][hashTable[b]]=cost;
        G[hashTable[b]][hashTable[a]]=cost;
    }
    Dijkstra(start);
    cout<<num[hashTable["ROM"]]<<" "<<d[hashTable["ROM"]]<<" ";
    DFS(hashTable["ROM"]);
    int value=0;
    int optavgvalue=-1;
    int flag;
    for(int i=0;i<countt;i++)          //找到最佳路径
    {
        for(int j=0;j<path[i].size()-1;j++)
        {
            value+=happ[path[i][j]];
        }
        int tempval=value/(path[i].size()-1);
        if(tempval>optavgvalue)
        {
            optavgvalue=(value/(path[i].size()-1));
            flag=i;
        }
    }

    cout<<optValue<<" "<<optavgvalue<<"\n";
    for(int i=path[flag].size()-1;i>=0;i--)
    {
        if(i>0)
            cout<<hashTtable[path[flag][i]]<<"->";
        else
            cout<<"ROM"<<"\n";
    }
    return 0;
}

