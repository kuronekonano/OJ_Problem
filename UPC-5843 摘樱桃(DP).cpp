#include<stdio.h>///��������������еĵ��ƣ����ÿ��Ƿ������⣬���϶���������Ž⼴��
#include<math.h>
#include<algorithm>
#include<string.h>
using namespace std;
int n,t,a[1005],dp[1005],sum[1005];
int main()
{
    while(scanf("%d%d",&n,&t)!=EOF)
    {
        memset(dp,0x3f,sizeof(dp));///��Ϊ����Сֵ����˳�ʼ��Ϊ���ֵ
        for(int i=1; i<=n; i++) scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i];///ǰ׺�ͼ���
        dp[1]=(a[1]-t)*(a[1]-t);///ֻ��һ��ӣ��ʱֻ��һ�ֽ�
        dp[0]=0;
        for(int i=2; i<=n; i++)///��i��ӣ��ʱ�����Ž�
            for(int j=i-1; j>=0; j--)///��i��ӣ����j��ӣ�Һ�Ϊһ�飬�ټ���ʣ��ӣ�ҵ����Ž⣬���ϱ����ϲ�ȡ��Сֵ
                dp[i]=min(dp[i],(sum[i]-sum[j]-t)*(sum[i]-sum[j]-t)+dp[j]);///��ǰdp��i���Ľ⣬���������䷽���Ľ⣬ȡ���Ž�
        printf("%d\n",dp[n]);
    }
}
