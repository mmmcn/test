/*包含dfs()和bfs两种方法*/
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
vector<int>V[105];
int n,m;
int ans[105]={0};
int maxnum=-1,level;
void dfs(int index,int depth)
{
    ans[depth]++;
    for(int i=0;i<V[index].size();i++)
        dfs(V[index][i],depth+1);
}
void bfs(int root)
{
    queue<int> q;
    q.push(root);
    int depth=0;
    while(!q.empty())
    {
        int size=q.size();
        depth++;
        if(size>maxnum){
            maxnum=size;
            level=depth;
        }
        int count=0;
        while(count<size)
        {
            int u=q.front();
            q.pop();
            for(int i=0;i<V[u].size();i++)
                q.push(V[u][i]);
            count++;
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int id,k;
        scanf("%d%d",&id,&k);
        for(int j=0;j<k;j++)
        {
            int child;
            scanf("%d",&child);
            V[id].push_back(child);
        }
    }
    //dfs(1,1);
    bfs(1);
    for(int i=1;i<=n;i++)
    {
        if(ans[i]>maxnum){
            maxnum=ans[i];
            level=i;
        }
    }
    printf("%d %d",maxnum,level);
    return 0;
}
