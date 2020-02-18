#include <cstdio>
#include <vector>
#include <queue>
using namespace std;              //本方法采用BFS

const int N=100001;
struct Node{
    int amount;
    vector<int> child;
}Tree[N];

int n;
double origin_price,r;
int main()
{
    scanf("%d%lf%lf",&n,&origin_price,&r);
    for(int i=0;i<n;i++)
    {
        int k,child;
        scanf("%d",&k);
        if(k==0)
            scanf("%d",&Tree[i].amount);
        else
        {
            for(int j=0;j<k;j++)
            {
                scanf("%d",&child);
                Tree[i].child.push_back(child);
            }
        }
    }
    queue<int> q;
    q.push(0);
    int depth=0;
    double ans=0.0;
    double curr_price;
    while(!q.empty())
    {
        depth++;
        if(depth==1)
            curr_price=origin_price;
        else
        {
            double m=curr_price*r/100.0;
            curr_price+=m;
        }
        //printf("%f\n",curr_price);
        int count=0;
        int size=q.size();
        while(count<size)
        {
            int a=q.front();
            q.pop();
            count++;
            if(Tree[a].child.size()==0)   //遇到叶子节点
            {
                //printf("%d %f\n",Tree[a].amount,curr_price);
				double temp=curr_price*Tree[a].amount;
				//printf("%f\n",temp);
                ans+=temp;
            }
            else
            {
                for(int i=0;i<Tree[a].child.size();i++)
                {
                    q.push(Tree[a].child[i]);
                }
            }
        }
    }
    printf("%.1f",ans);
    return 0;
}



//下面为DFS求解,代码来源：https://www.liuchuo.net/archives/2212
//以后能用DFS就用DFS，代码简洁，写起来快
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
struct node {
    double data;
    vector<int> child;
};
vector<node> v;
double ans = 0.0, p, r;

void dfs(int index, int depth) {
    if(v[index].child.size() == 0) {
        ans += v[index].data * pow(1 + r, depth);
        return ;
    }
    for(int i = 0; i < v[index].child.size(); i++)
        dfs(v[index].child[i], depth + 1);
}
int main() {
    int n, k, c;
    scanf("%d %lf %lf", &n, &p, &r);
    r = r / 100;
    v.resize(n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &k);
        if(k == 0) {
            scanf("%lf", &v[i].data);
        } else {
            for(int j = 0; j < k; j++) {
                scanf("%d", &c);
                v[i].child.push_back(c);
            }
        }
    }
    dfs(0, 0);
    printf("%.1f", ans * p);
    return 0;
}


