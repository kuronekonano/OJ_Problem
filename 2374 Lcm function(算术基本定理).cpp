#include<stdio.h>///算术基本定理
#include<string.h>
#define LL long long
const int maxn=10000100;
int num=0;
LL prime[maxn/10],cnt;
bool vis[maxn];
int mi[2000],pi[1900];
void init()
{
    memset(vis,true,sizeof(vis));
    for(int i=2;i<maxn;i++)
    {
        if(vis[i])prime[num++]=i;
        for(int j=0;j<num&&i*prime[j]<maxn;j++)
        {
            vis[i*prime[j]]=false;
            if(i%prime[j]==0) break;
        }
    }
}
void breakperime(LL x)///分解质因数
{
    memset(mi,0,sizeof(mi));
    memset(pi,0,sizeof(pi));
    cnt=0;
    for(LL i=0;prime[i]*prime[i]<=x;i++)
    {
        if(x%prime[i]==0)
        {
            pi[cnt]=prime[i];///记录质因数
            while(x%prime[i]==0)
            {
                mi[cnt]++;///记录该质因数的幂次
                x/=prime[i];
            }
            cnt++;
        }
    }
    if(x!=1)pi[cnt]=x,mi[cnt++]=1;
}
int main()
{
    int t,cas=0;
    LL n;
    init();
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        breakperime(n);
        LL sum=1;
        for(LL i=0;i<cnt;i++) sum=sum*(mi[i]*2+1);
        sum=(sum+1)/2;
        printf("%lld\n",sum);
    }
}
