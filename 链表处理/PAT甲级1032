/*这道题需要注意的是一种字符可能占用不同的地址,最开始没考虑到
导致有一个测试点没过*/
#include <bits/stdc++.h>
using namespace std;

const int maxn=100005;
struct Node{
    char data;
    int pre1;
    int pre2;
    int next;
}node[maxn];

vector<char> v1;
vector<char> v2;
int main()
{

    int start1,start2,N;
    cin>>start1>>start2>>N;
    int add,next;
    char data;
    for(int i=0;i<N;i++)
    {
        cin>>add>>data>>next;
        node[add].data=data;
        node[add].next=next;
    }
    int now1=start1,former1=-1;
    int now2=start2,former2=-1;
    int end1,end2;
    while(now1!=-1)
    {
        node[now1].pre1=former1;
        former1=now1;
        if(node[now1].next==-1)
            end1=now1;
        now1=node[now1].next;
    }
    while(now2!=-1)
    {
        node[now2].pre2=former2;
        former2=now2;
        if(node[now2].next==-1)
            end2=now2;
        now2=node[now2].next;
    }
    now1=end1;
    now2=end2;
    int common=-1;
    while(now1!=-1&&now2!=-1)
    {
        if(node[now1].data==node[now2].data&&now1==now2){    //now1==now2保证同样的字符地址也相同
            common=now1;
            now1=node[now1].pre1;
            now2=node[now2].pre2;
        }
        else
            break;
    }
    if(common==-1)
        printf("-1\n");
    else
        printf("%05d\n",common);
    return 0;
}
