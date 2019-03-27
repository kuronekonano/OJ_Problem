#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=1005;
const int mod=1000000007;
LL qp(LL a,LL b)
{
    LL res=1;
    while(b)
    {
        if(b&1)res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
LL n,m,p[maxn],fac[maxn],zep[maxn],dp[maxn][maxn];
void init(int n,int m)
{
    fac[1]=fac[0]=1;
    for(int i=2;i<=n;i++) fac[i]=qp(i,m);
}
LL inv=qp(100,mod-2);
int main()
{
    while(scanf("%lld%lld",&n,&m)!=EOF)
    {
        init(n,m);
        LL ans=0;
        zep[n+1]=p[n+1]=zep[0]=p[0]=1;
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&p[i]);
            zep[i]=(100-p[i])*inv%mod;
            p[i]=p[i]*inv%mod;
            dp[i][0]=1;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;i+j<=n+1;j++)
            {
                dp[i][j]=dp[i][j-1]*p[i+j-1]%mod;
                LL tmp=dp[i][j]*zep[i-1]%mod*zep[i+j]%mod;
                ans=(ans+(tmp*fac[j])%mod)%mod;
            }
        }
        printf("%lld\n",ans%mod);
    }
}
