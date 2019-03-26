#include<stdio.h>///区间DP
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    int a[105],n,i,j,k,len,sum[108],dpmax[108][108],dpmin[106][106];
    while(scanf("%d",&n)!=EOF)
    {
        memset(sum,0,sizeof(sum));///求和数组，求出某个区间内石子数量和
        memset(dpmax,0,sizeof(dpmax));///最大求和dp
        memset(dpmin,0x3f,sizeof(dpmin));///最小求和dp
        sum[0]=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            sum[i]=sum[i-1]+a[i];///在输入的同时累加求和
            dpmax[i][i]=0;///二维dp数组中下标ij表示区间从i到j的石子数量和
            dpmin[i][i]=0;
        }
        for(len=2;len<=n;len++)///dp区间长度，从长度为2的区间相加到长度为n的区间，一直筛选最优值
        {
            for(i=1;i<=n-len+1;i++)///在某个len的长度下，从区间i到i+长度=j这段距离
            {
                j=i+len-1;
                for(k=i;k<j;k++)///在i到j这段长len的距离下，取某个中点k作分成两份，从而筛选两堆求和的最优值
                {
                    dpmax[i][j]=max(dpmax[i][j],(dpmax[i][k]+dpmax[k+1][j]+sum[j]-sum[i-1]));///也就是区间i到k，和区间k+1到j之和。加上求和后的区间总值
                    dpmin[i][j]=min(dpmin[i][j],(dpmin[i][k]+dpmin[k+1][j]+sum[j]-sum[i-1]));
                }
            }

        }
//        for(i=1;i<=n;i++)
//            for(j=1;j<=n;j++)
//            printf("%d%c",dpmax[i][j],j==n?'\n':' ');
        printf("%d %d\n",dpmin[1][n],dpmax[1][n]);
    }
}
