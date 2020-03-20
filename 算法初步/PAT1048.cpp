/*思路很简单，首先将金额非降序排序，然后从头部和尾部分别遍历判断即可，这样也可保证得到的结果V1是最小的*/
#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
int coins[maxn];

int main()
{
	int n,m;
	#ifdef ONLINE_JUDGE
	#else
        freopen("C:\\Users\\86138\\Desktop\\in.txt","r",stdin);
	#endif // ONLINE_JUDGE
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",&coins[i]);
	sort(coins,coins+n);
	int i=0,j=n-1;
	int number=0;
	while(i<j)
	{
		if(coins[i]+coins[j]<m)
			i++;
		else if(coins[i]+coins[j]>m)
			j--;
		else
            break;
	}
	i<j?printf("%d %d\n",coins[i],coins[j]):printf("No Solution\n");
	return 0;
}
