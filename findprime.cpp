#include <cstdio>

#define N 10000

int flag[N+1],prime[N+1],pnum;
int main()
{
    pnum=0;
    for(int i=0;i<=N;i++)
        flag[i]=1;      //所有数看做素数
    for(int i=2;i<=N;i++)
    {
        if(flag[i]==1)
            prime[pnum++]=i;
        for(int j=0;j<pnum&&prime[j]*i<=N;j++)
        {
            flag[prime[j]*i]=0;
            if(i%prime[j]==0)   //找到i的最小素因数s
                break;
        }
    }
    for(int i=0;i<pnum;i++)
        (i+1)%10==0?printf("%d\n",prime[i]):printf("%d ",prime[i]);
	return 0;
}
