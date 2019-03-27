#include<stdio.h>///类似最长递增子序列的递推，不用考虑分组问题，不断对其递推最优解即可
#include<math.h>
#include<algorithm>
#include<string.h>
using namespace std;
int n,t,a[1005],dp[1005],sum[1005];
int main()
{
    while(scanf("%d%d",&n,&t)!=EOF)
    {
        memset(dp,0x3f,sizeof(dp));///因为求最小值，因此初始化为最大值
        for(int i=1; i<=n; i++) scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i];///前缀和计算
        dp[1]=(a[1]-t)*(a[1]-t);///只有一个樱桃时只有一种解
        dp[0]=0;
        for(int i=2; i<=n; i++)///有i个樱桃时的最优解
            for(int j=i-1; j>=0; j--)///第i个樱桃与j个樱桃合为一组，再加上剩余樱桃的最优解，不断遍历合并取最小值
                dp[i]=min(dp[i],(sum[i]-sum[j]-t)*(sum[i]-sum[j]-t)+dp[j]);///当前dp【i】的解，和其他分配方案的解，取最优解
        printf("%d\n",dp[n]);
    }
}
