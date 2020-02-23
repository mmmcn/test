#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
struct Fraction
{
    long long up;
    long long down;
};
struct Fraction f1;
struct Fraction f2;
long long gcd(long long a,long long b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
Fraction reduction(Fraction result)
{
    if(result.down<0)
    {
        result.down=-result.down;
        result.up=-result.up;
    }
    if(result.up==0)
        result.down=1;
    else
    {
        int d=gcd(abs(result.up),abs(result.down));
        result.up/=d;
        result.down/=d;
    }
    return result;
}
Fraction Add(Fraction f1,Fraction f2)
{
    Fraction result;
    result.up=f1.up*f2.down+f2.up*f1.down;
    result.down=f1.down*f2.down;
    return reduction(result);
}
Fraction Sub(Fraction f1,Fraction f2)
{
    Fraction result;
    result.up=f1.up*f2.down-f2.up*f1.down;
    result.down=f1.down*f2.down;
    return reduction(result);
}
Fraction Mul(Fraction f1,Fraction f2)
{
    Fraction result;
    result.up=f1.up*f2.up;
    result.down=f1.down*f2.down;
    return reduction(result);
}
Fraction Div(Fraction f1,Fraction f2)
{
    Fraction result;
    result.up=f1.up*f2.down;
    result.down=f1.down*f2.up;
    return reduction(result);
}
void show(Fraction r)
{
    r=reduction(r);
    if(r.up<0)
    {
        printf("(");
        if(r.down==1)
            printf("%lld",r.up);
        else if(abs(r.up)>r.down)
            printf("%lld %lld/%lld",r.up/r.down,abs(r.up)%r.down,r.down);
        else
            printf("%lld/%lld",r.up,r.down);
        printf(")");
    }
    else
    {
        if(r.down==1)
            printf("%lld",r.up);
        else if(abs(r.up)>r.down)
            printf("%lld %lld/%lld",r.up/r.down,abs(r.up)%r.down,r.down);
        else
            printf("%lld/%lld",r.up,r.down);
    }
}
int main()
{
    #ifdef ONLINE_JUDGE
    #else
        freopen("E:\\in.txt","r",stdin);
    #endif // ONLINE_JUDGE
    scanf("%lld%*c%lld%*c%lld%*c%lld",&f1.up,&f1.down,&f2.up,&f2.down);  //输入时利用%*c跳过一个字符，别再忘记了

    show(f1);
    printf(" + ");
    show(f2);
    printf(" = ");
    show(Add(f1,f2));
    printf("\n");

    show(f1);
    printf(" - ");
    show(f2);
    printf(" = ");
    show(Sub(f1,f2));
    printf("\n");

    show(f1);
    printf(" * ");
    show(f2);
    printf(" = ");
    show(Mul(f1,f2));
    printf("\n");

    show(f1);
    printf(" / ");
    show(f2);
    printf(" = ");
    if(f2.up==0)
        printf("Inf\n");
    else
    {
        show(Div(f1,f2));
        printf("\n");
    }
    return 0;
}

