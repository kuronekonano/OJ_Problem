#include<stdio.h>
#include<string.h>
#include<algorithm>
#define LL long long
using namespace std;
LL a[100005],dp1[100005],dp2[100005];
int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        memset(dp1,0,sizeof(dp1));
        memset(dp2,0,sizeof(dp2));
        for(int i=1; i<=n; i++)scanf("%d",&a[i]);
        for(int i=k+1; i<=n; i++)///从k+1位开始推，这样方便对i和i-k位求和
        {
            dp1[i]=dp2[i-k]+a[i]+a[i-k];///dp1表示 取  i-2k及i-3k的和 以及i到i-k的和作为待选值
            dp2[i]=max(dp1[i-k],dp2[i-k]);///dp2表示，在i位时，选i-k及i-2k 的和  与   i-k的最大值  比较取较大值
        }
        LL ans=0;
        for(int i=n-k+1; i<=n; i++)ans+=max(dp1[i],dp2[i]);///最后取最后k位总和求和，也就是k串序列，k次抽取个总和
        printf("%lld\n",ans);
    }
}
