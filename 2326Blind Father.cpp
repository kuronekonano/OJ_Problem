#include<stdio.h>
int main()
{
    int n,m,a[10005],i,j;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)///n块木板
        {
            scanf("%d",&a[i]);
        }
        int maxn=0;///初始化面积最大值
        for(i=0;i<n;i++)///从头遍历木板
        {
            int sum=1;///取正在遍历木板本身为1
            for(j=i+1;j<n;j++)///向着木板右边扩展
            {
                if(a[j]>=a[i])///唯有大于等于木板本身的才计数
                {
                    sum++;
                }
                else///一旦发现短于自己的木板，说明最长长度在次截止，直接算面积
                    break;
            }
            for(j=i-1;j>=0;j--)///向木板左边扩展
            {
                if(a[j]>=a[i])
                {
                    sum++;
                }
                else
                    break;
            }
            maxn=sum*a[i]>maxn?sum*a[i]:maxn;///计算面积取最值
        }
        printf("%d\n",maxn);///输出最值
    }
    return 0;
}
