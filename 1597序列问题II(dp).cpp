#include<stdio.h>
#include<string.h>///比最长递增子序列修改个判断条件即可
#include<algorithm>
using namespace std;
int main()
{
    int i,j,a[1080],dp[1080],n;
    int t;
    scanf("%d",&t);///t组数据
    while(t--)
    {
        scanf("%d",&n);///n个数
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        memset(dp,0,sizeof(dp));///清空dp数组
        int flag;
        dp[0]=1;///初始化边界
        for(i=1;i<n;i++)///开始dp，外层从第二个数开始
        {
            flag=dp[i];///flag记录目前最长序列长度
            for(j=0;j<i;j++)///内层循环从第一个数检查至第i个数
            {
                if(a[i]<=a[j]&&dp[j]>flag)///对比一旦小于或等于前面那个数，且长度大于flag记录的长度，就将其记为最大值
                {
                    flag=dp[j];///作为最长序列长度暂时记录到flag中
                }
            }
            dp[i]=flag+1;///多一个数就+1，最终遍历完后flag内存的是第i个数之前的最长长度，那么再加i本身(+1)便是此时的最长长度
        }
        sort(dp,dp+n);///找出最大长度
        printf("%d\n",dp[n-1]);
    }
    return 0;
}
