#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;///dp数组中，纵坐标表示遍历到第i个音符，横坐标表示筛选出来的第j个坐标的音符，数组内存储权值之和
int main()
{
    int i,j,t,n,m,a[108][106],dp[106][103],b[108];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&m,&n);
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        for(i=1;i<=m;i++)
        {
            scanf("%d",&b[i]);
        }
        for(i=2;i<=m;i++)
        {
            int tmp;
            if(b[i]!=-1)
            {
                tmp=b[i];
                if(b[i-1]!=-1)
                {
                    dp[i][tmp]=dp[i-1][b[i-1]]+a[b[i-1]][tmp];///要注意到点：因为下一个已知，所以已知的点不需要每个都计算，只需要计算已知的那个坐标的值
                }
                else
                {
                    for(j=1;j<=n;j++)
                    {
                        dp[i][tmp]=max(dp[i][tmp],dp[i-1][j]+a[j][tmp]);///因此dp的坐标是[i]当前遍历位置[tmp]已知坐标，而当当前未知时，才会用j去遍历求每一个的权值
                    }
                }
            }
            else
            {
                if(b[i-1]!=-1)
                {
                    for(j=1;j<=n;j++)
                    {
                        dp[i][j]=dp[i-1][b[i-1]]+a[b[i-1]][j];///要注意的点：当上一个已知时，要计算出所有的下一个，此时不需要max筛选，因为上一个用已知的，下一个因为是为止，所以算出每一个就好
                    }
                }
                else
                {
                    for(j=1;j<=n;j++)
                    {
                        for(int k=1;k<=n;k++)
                        {
                            dp[i][j]=max(dp[i][j],dp[i-1][k]+a[k][j]);///而当上一个未知时，要用max从上一个中选择一个最大值来配下一个，无论下一个已知还是为止，max筛选的是未知的上一个
                        }
                    }
                }
            }
        }
//        for(i=1;i<=m;i++)
//            for(j=1;j<=n;j++)
//            printf("%4d%c",dp[i][j],j==n?'\n':' ');
        int ans=0;
        for(i=1;i<=n;i++)///最后用遍历的方法找出最大值
        {
            ans=dp[m][i]>ans?dp[m][i]:ans;
        }
        printf("%d\n",ans);
    }
}
