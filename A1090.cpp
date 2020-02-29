#include <bits/stdc++.h>
using namespace std;
const int N=100001;
vector<int> v[N];
int n;
double p,r;
int num;
int depth=0;
int maxdepth=0,maxnum=0;
/*void BFS(int root)    //自己用BFS可能代码量大一些
{
    queue<int> q;
    q.push(root);
    int prenum=0;
    while(!q.empty())
    {
        int size=q.size();
        int count=0;
        depth++;
        prenum=0;
        while(count<size)
        {
            int u=q.front();
            q.pop();
            if(v[u].size()==0)
                prenum++;
            else
            {
                for(int i=0;i<v[u].size();i++)
                    q.push(v[u][i]);
            }
            count++;
        }
        num=prenum;
    }
}*/
void DFS(int index,int depth)   //参考柳婼代码
{
    if(v[index].size()==0)
    {
        if(maxdepth==depth)
            maxnum++;
        if(maxdepth<depth){
            maxdepth=depth;
            maxnum=1;
        }
        return ;
    }
    for(int i=0;i<v[index].size();i++)
        DFS(v[index][i],depth+1);
}

int main()
{
    scanf("%d%lf%lf",&n,&p,&r);
    int temp;
    int root;
    double price;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&temp);
        if(temp==-1)
            root=i;
        else
            v[temp].push_back(i);
    }
    /*BFS(root);
    price=p*pow(1+r/100.0,depth-1);
    printf("%.2f %d\n",price,num);*/
    DFS(root,0);
    printf("%.2f %d",p*pow(1+r/100.0,maxdepth),maxnum);
    return 0;
}
