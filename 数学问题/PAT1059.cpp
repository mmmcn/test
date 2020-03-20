//通过此题掌握利用欧拉筛法求素数表的方法即可

#include <bits/stdc++.h>
using namespace std;
const int N=1000000;
int flag[N+1],prime[N+1],pnum;
int num[N+1]={0};
int main()
{
    long int n;
    pnum=0;
    for(int i=0;i<=N;i++)
        flag[i]=1;
    for(int i=2;i<=N;i++)
    {
        if(flag[i]==1)
            prime[pnum++]=i;
        for(int j=0;j<pnum&&prime[j]*i<=N;j++)
        {
            flag[prime[j]*i]=0;
            if(i%prime[j]==0)
                break;
        }
    }
    scanf("%ld",&n);
    printf("%ld=",n);
    int k=0;
    if(n==1)
        printf("1\n");
    else
    {
        while(n>1)
        {
            for(int i=0;i<pnum;i++)
            {
                if(n%prime[i]==0)
                {
                    if(num[i]==0)
                        k++;
                    num[i]++;
                    n/=prime[i];
                    break;
                }
            }
        }
        for(int i=0;i<=N;i++)
        {
            if(num[i]==0)
                continue;
            else if(num[i]==1){
                printf("%ld",prime[i]);
                k--;
            }
            else{
                printf("%ld^%d",prime[i],num[i]);
                k--;
            }
            k==0?printf("\n"):printf("*");
        }
    }
    return 0;
}
