/*这个题有空格串输入的情况，因此需要用getline()来读入，否则会导致后序字符串读入错误
 读入n之后需要用getchar()吃掉回车符，否则也会出错，这种问题需要注意*/

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int n;
int main()
{
    #ifdef ONLINE_JUDGE
    #else
        freopen("E:\\in.txt","r",stdin);
    #endif // ONLINE_JUDGE
    cin>>n;
    getchar();
    string s;
    int zimu,shuzi,dot,space;
    for(int i=0;i<n;i++)
    {
        zimu=shuzi=dot=space=0;
        getline(cin,s);
        if(s.size()<6)
            cout<<"Your password is tai duan le.\n";
        else
        {
            for(int j=0;j<s.size();j++)
            {
                if(s[j]=='.')
                    dot++;
                else if((s[j]>='a'&&s[j]<='z')||(s[j]>='A'&&s[j]<='Z'))
                    zimu++;
                else if(s[j]>='0'&&s[j]<='9')
                    shuzi++;
                else
                    space++;
            }
            if(space)
                cout<<"Your password is tai luan le.\n";
            else if(zimu&&!shuzi)
                cout<<"Your password needs shu zi."<<"\n";
            else if(!zimu&&shuzi)
                cout<<"Your password needs zi mu."<<"\n";
            else
                cout<<"Your password is wan mei."<<"\n";

        }
    }
    return 0;
}

