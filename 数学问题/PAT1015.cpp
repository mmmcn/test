/*题目理解起来很简单，但是不要忘记对0和1特判，main()主要是十进制转化为K进制，K进制转化为十进制，转化还是很简单的*/
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

bool judge(int a)
{
    if(a<=1)
        return false;
    int k=sqrt(a);
    for(int i=2;i<=k;i++)
    {
        if(a%i==0)
            return false;
    }
    return true;
}
int main()
{
    int N,D;
    vector<int> v;
    while(1)
    {
        scanf("%d",&N);
        if(N<0)
            break;
        scanf("%d",&D);
        int temp=N;
        while(N>0)
        {
            v.push_back(N%D);
            N/=D;
        }
        int ans=0;
        for(int i=0;i<v.size();i++)
        {
            ans=ans*D+v[i];
        }
        if(judge(ans)&&judge(temp))
            printf("Yes\n");
        else
            printf("No\n");
        v.clear();
    }
    return 0;
}
