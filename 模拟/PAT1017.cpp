/*题目大意为在工作时间内求客户等待时间的平均值。
可以按照用户到达时间从小到大排好序，按顺序处理即可。关键在于找到一个最早空闲的窗口，若用户到达时间大于窗口处理结束时间
则该用户不需等待，该窗口下一次结束服务时间为用户到达时间+服务时间；反之，该用户需要等待，该窗口下一次结束服务时间为该用户
所需服务时间*/

#include <bits/stdc++.h>
using namespace std;
const int maxn=10005;
struct Customer{
    int arriveTime;
    int serveTime;
}cus[maxn];
bool cmp(Customer a,Customer b){
    return a.arriveTime<b.arriveTime;
}
int change(int hh,int mm,int ss){
    return hh*3600+mm*60+ss;
}
int main()
{
    int N,K;
    int number=0;
    int h,m,s,serveTime;
    scanf("%d%d",&N,&K);
    int *windows=new int[K];
    for(int i=0;i<N;i++)
    {
        scanf("%d:%d:%d%d",&h,&m,&s,&serveTime);
        int arriveTime=change(h,m,s);
        if(arriveTime>change(17,0,0))  //到达时间不规范
            continue;
        else{
            cus[number].arriveTime=arriveTime;
            cus[number].serveTime=serveTime<=60?serveTime*60:3600;
            number++;
        }
    }
    sort(cus,cus+number,cmp);
    int now=change(8,0,0);
    fill(windows,windows+K,now);
    double waitTime=0.0;
    for(int i=0;i<number;i++)
    {
        int index=-1,Min=10000000;
        for(int j=0;j<K;j++){
            if(windows[j]<Min){
                Min=windows[j];
                index=j;
            }
        }
        if(windows[index]<=cus[i].arriveTime)
            windows[index]=cus[i].arriveTime+cus[i].serveTime;
        else{
            waitTime+=(windows[index]-cus[i].arriveTime);
            windows[index]+=cus[i].serveTime;
        }
    }
    number==0?printf("0.0"):printf("%.1f\n",waitTime/(60*number));
    return 0;
}
