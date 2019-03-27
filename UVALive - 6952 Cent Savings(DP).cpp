#include<stdio.h>///分割板DP
#include<string.h>
#include<algorithm>
using namespace std;
int dp[2008][25],a[2008];
int main()
{
    int n,d;
    while(scanf("%d%d",&n,&d)!=EOF)
    {
        memset(dp,0x3f,sizeof(dp));
        memset(a,0,sizeof(a));
        for(int i=1; i<=n; i++) scanf("%d",&a[i]),a[i]+=a[i-1]; ///价格总和
        int ans=0x7fffffff;
        for(int i=1; i<=n; i++) ///从1到n个物品价格总和
        {
            dp[i][0]=(a[i]+5)/10*10;///四舍五入,[i][0]指，在i个物品时，不加入隔板的花费
            for(int j=1; j<i; j++) ///在1到i个物品的价格总和中加入隔板
                for(int k=1; k<=d; k++) ///加入1到d个隔板,从使用0个隔板更新到k个隔板
                    dp[i][k]=min(dp[i][k],dp[j][k-1]+(a[i]-a[j]+5)/10*10);///i个物品使用k个隔板的花费，将dp[j][k-1]个隔板分成一堆，j+1到i分成一堆，中间用一个隔板隔开，也就是总共用了k个隔板
        }///a[i]-a[j]不是单价，是一段区间和，也就是说，第i个物品，应该和i-j个物品合为一堆，i到j的距离逐渐变小
//        for(int i=1; i<=n; i++)
//            for(int j=0; j<=d; j++)
//                printf("%d%c",dp[i][j],j==d?'\n':' ');
        for(int i=0; i<=d; i++)ans=min(ans,dp[n][i]); ///[i][k]表示，i个物品时，k个隔板的最小花费
        printf("%d\n",ans);///最后得到n个物品使用0到d个隔板的不同花费，取最小值，每个隔板的花费是在不同位置中的最小花费
    }
}
