#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;///dp�����У��������ʾ��������i���������������ʾɸѡ�����ĵ�j������������������ڴ洢Ȩֵ֮��
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
                    dp[i][tmp]=dp[i-1][b[i-1]]+a[b[i-1]][tmp];///Ҫע�⵽�㣺��Ϊ��һ����֪��������֪�ĵ㲻��Ҫÿ�������㣬ֻ��Ҫ������֪���Ǹ������ֵ
                }
                else
                {
                    for(j=1;j<=n;j++)
                    {
                        dp[i][tmp]=max(dp[i][tmp],dp[i-1][j]+a[j][tmp]);///���dp��������[i]��ǰ����λ��[tmp]��֪���꣬������ǰδ֪ʱ���Ż���jȥ������ÿһ����Ȩֵ
                    }
                }
            }
            else
            {
                if(b[i-1]!=-1)
                {
                    for(j=1;j<=n;j++)
                    {
                        dp[i][j]=dp[i-1][b[i-1]]+a[b[i-1]][j];///Ҫע��ĵ㣺����һ����֪ʱ��Ҫ��������е���һ������ʱ����Ҫmaxɸѡ����Ϊ��һ������֪�ģ���һ����Ϊ��Ϊֹ���������ÿһ���ͺ�
                    }
                }
                else
                {
                    for(j=1;j<=n;j++)
                    {
                        for(int k=1;k<=n;k++)
                        {
                            dp[i][j]=max(dp[i][j],dp[i-1][k]+a[k][j]);///������һ��δ֪ʱ��Ҫ��max����һ����ѡ��һ�����ֵ������һ����������һ����֪����Ϊֹ��maxɸѡ����δ֪����һ��
                        }
                    }
                }
            }
        }
//        for(i=1;i<=m;i++)
//            for(j=1;j<=n;j++)
//            printf("%4d%c",dp[i][j],j==n?'\n':' ');
        int ans=0;
        for(i=1;i<=n;i++)///����ñ����ķ����ҳ����ֵ
        {
            ans=dp[m][i]>ans?dp[m][i]:ans;
        }
        printf("%d\n",ans);
    }
}
