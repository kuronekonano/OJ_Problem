#include<bits/stdc++.h>
#define LL long long
#define M(a,b) memset(a,b,sizeof a)
#define pb(x) push_back(x)
using namespace std;
const int maxn=1e5+7;
const int mod=1000000007;
LL a[80],b[maxn],c[80];
LL bin[69];
LL n;
LL qa(LL a,LL b)
{
    LL ans=0;
    while(b)
    {
        if(b&1)ans=(ans+a)%mod;
        a=(a+a)%mod;
        b>>=1;
    }
    return ans;
}
int main()
{
    bool flag=true;
    for(int i=0; i<60; i++)scanf("%lld",&a[i]),c[i]=1LL<<i;
    scanf("%lld",&n);
    for(int i=1; i<=n; i++) scanf("%lld",&b[i]);
    sort(b+1,b+1+n);
    for(int i=n; i>=1&&flag; i--)
    {
        LL tmp=b[i];
        for(int j=59; j>=0; j--)
        {
            if(tmp>=c[j])
            {
                LL num=tmp/c[j];
                tmp=tmp%c[j];
                if(a[j]>=num)a[j]-=num,num=0;
                else
                {
                    num-=a[j];
                    a[j]=0;
                }
                tmp+=num*c[j];
            }
            if(j==0&&tmp) flag=false;
        }
    }
    LL ans=0;
    if(!flag)printf("-1\n");
    else
    {
        for(int i=0; i<60; i++)if(a[i])ans=(ans+qa(a[i],c[i]))%mod;
        printf("%lld\n",ans);
    }

}
