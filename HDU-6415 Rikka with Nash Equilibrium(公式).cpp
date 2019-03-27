#include<bits/stdc++.h>
#define LL long long
#define M(a,b) memset(a,b,sizeof a)
using namespace std;
const int maxn=1e6+7;
const int mod=1e9+7;
LL n,m,p,fac[6408];
LL qp(LL a,LL b)
{
    LL ans=1;
    while(b)
    {
        if(b&1)ans=ans*a,ans=ans>p?ans%p:ans;
        a=a*a,a=a>p?a%p:a;
        b>>=1;
    }
    return ans;
}
void fact(LL num)
{
    fac[1]=1;
    for(int i=2;i<=num;i++) fac[i]=(fac[i-1]*i),fac[i]=fac[i]>p?fac[i]%p:fac[i];
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld%lld",&n,&m,&p);
        fact(max(n,m));
        LL ans=(fac[n]*fac[m])%p;
        for(LL i=n*m;i>n+m-1;i--) ans=ans*i,ans=ans>p?ans%p:ans;
        printf("%lld\n",ans);
    }
}
///n!*m!*(n*m)!/(n+m-1)!
