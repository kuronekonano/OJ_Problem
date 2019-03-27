#include<bits/stdc++.h>
#define LL long long
#define M(a,b) memset(a,b,sizeof a)
using namespace std;
const int maxn=2e7+5;
LL euler[maxn]={0};
LL prime[maxn],cnt=0;
bool vis[maxn];
LL sum[maxn];
void Init()///线性欧拉筛
{
    sum[1]=euler[1]=1;
    memset(vis,false,sizeof vis);
    for(int i=2;i<maxn;i++)
    {
        if(!vis[i])prime[++cnt]=i,euler[i]=i-1;///素数情况
        for(int j=1;j<=cnt&&i*prime[j]<=maxn;j++)
        {
            vis[i*prime[j]]=1;
            if(i%prime[j])euler[i*prime[j]]=euler[i]*(prime[j]-1);
            else
            {
                euler[i*prime[j]]=euler[i]*prime[j];
                break;
            }
        }
//        printf("======φ(%d)=%lld\n",i,euler[i]);
        sum[i]=sum[i-1]+((i&1)?euler[i]/2:euler[i]);///ans即前缀和，奇数为φ(i)/2,偶数为φ(i)
    }
}
int main()
{
    int t,n;
    Init();
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%lld\n",sum[n]-sum[1]);
    }
}
