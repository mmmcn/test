/*题意是根据两个非降序序列，找到这两个序列排列后得到的非降序序列的中位数
在遇到数组越界的问题时，我自己的思路是退出目前循环，然后分别用两个while()继续遍历，直到找到Median位置;
算法笔记上面是在数组上界位置赋了一个INF，这样可以避免越界问题，自己没有想到这种方法，还是要多练习*/

#include <bits/stdc++.h>
using namespace std;
const int maxn=200005;
long int s1[maxn];
long int s2[maxn];
int main()
{
	int n,m;
	#ifdef ONLINE_JUDGE
	#else
        freopen("C:\\Users\\86138\\Desktop\\in.txt","r",stdin);
	#endif // ONLINE_JUDGE
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
        scanf("%ld",&s1[i]);
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
        scanf("%ld",&s2[i]);
    int i=1,j=1;
    int k=0;
    int num=(n+m+1)/2;
    long int ans;
    while(i<=n&&j<=m)
    {
        if(s1[i]<=s2[j])
        {
            k++;
            ans=s1[i++];
            if(k==num) break;
        }
        else if(s1[i]>s2[j])
        {
            k++;
            ans=s2[j++];
            if(k==num) break;
        }
    }
    while(k<num&&i<=n){
        k++;
        ans=s1[i++];
        if(k==num) break;
    }
    while(k<num&&j<=m){
        k++;
        ans=s2[j++];
        if(k==num) break;
    }
    printf("%ld\n",ans);
	return 0;
}
