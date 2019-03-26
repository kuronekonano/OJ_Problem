#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL gcd(LL a,LL b)
{
    while(b)
    {
        LL tmp=b;
        b=a%b;
        a=tmp;
    }
    return a;
}
int main()
{
    LL n,x;
    while(scanf("%lld%lld",&n,&x)!=EOF)
    {
        LL tmp=gcd(n,x);
        printf("%lld\n",(3*(n/tmp-1))*tmp);
    }
}
