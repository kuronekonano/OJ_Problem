#include<stdio.h>
#include<string.h>
int main()
{
    long long dp[600];
    int i,n,j;
    while(scanf("%d",&n)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        int sum=n*(n+1)/2;///�Ȳ�����ǰn����͹�ʽ
        int half=sum/2;
        if(sum%2!=0)///��ΪҪ��sum�ܺͷֳ����������͵ļ��ϣ����sum�ܺͱ����ܱ�2��������һ������Ҳû��
        {
            printf("0\n");
            continue;
        }
        dp[0]=1;///������0ʱ�϶�ֻ��һ�ַַ�
        for(i=1;i<=n;i++)///dp��i������
        {
            for(j=half;j>=i;j--)
            {
                dp[j]=dp[j]+dp[j-i];///�ﵽÿһ���ܺ͵ķ��������Ǽ�ȥ��������̳е���һ�����ķ�������
            }
//            for(int k=half;k>=0;k--)
//            {
//                printf("%d\n",dp[k]);
//            }
//            printf("====\n");
        }
        printf("%lld\n",dp[half]/2);///�˴����ϵ����������Ͻ���λ�ã����ظ��ģ�Ҫ��2
    }
    return 0;
}
