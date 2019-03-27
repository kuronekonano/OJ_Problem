#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=1e5+10;
const int p=1e9+7;
char str[maxn];
LL mod[maxn];
LL poww(LL a,LL b,LL pp)///快速幂
{
    LL ans=1;
    while(b)
    {
        if(b&1)ans=(ans*a)%pp;
        a=(a*a)%pp;
        b>>=1;
    }
    return ans;
}
LL phi(LL n)///欧拉函数
{
    LL ans=n,tmp=n;
    for(int i=2; i*i<=tmp; i++)
    {
        if(tmp%i==0)
        {
            ans=ans/i*(i-1);
            while(tmp%i==0)tmp/=i;
        }
    }
    if(tmp>1)ans=ans/tmp*(tmp-1);
    return ans;
}
void init()///预处理1e9+7欧拉函数的欧拉函数...
{
    mod[0]=p;
    for(int i=1;i<maxn;i++)mod[i]=phi(mod[i-1]);
}
int t;
int main()
{
    init();
    scanf("%d",&t);
    while(t--)
    {
        LL ans=0;
        int to=0;
        scanf("%s",str);
        int len=strlen(str);
        for(int i=0;i<len;i++) if(str[i]=='2')to++;
        for(int i=0;i<len;i++)
        {
            if(str[i]=='1')ans=((ans<<1)+2)%mod[to];
            if(str[i]=='0')ans++,ans%=mod[to];
            if(str[i]=='2')
            {
                to--;
                ans=3LL*(poww(2LL,(ans+1)%mod[to],mod[to])-1+mod[to])%mod[to];
            }
        }
        printf("%lld\n",ans);
    }
}
