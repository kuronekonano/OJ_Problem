#include<stdio.h>///�ָ��DP
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
        for(int i=1; i<=n; i++) scanf("%d",&a[i]),a[i]+=a[i-1]; ///�۸��ܺ�
        int ans=0x7fffffff;
        for(int i=1; i<=n; i++) ///��1��n����Ʒ�۸��ܺ�
        {
            dp[i][0]=(a[i]+5)/10*10;///��������,[i][0]ָ����i����Ʒʱ�����������Ļ���
            for(int j=1; j<i; j++) ///��1��i����Ʒ�ļ۸��ܺ��м������
                for(int k=1; k<=d; k++) ///����1��d������,��ʹ��0��������µ�k������
                    dp[i][k]=min(dp[i][k],dp[j][k-1]+(a[i]-a[j]+5)/10*10);///i����Ʒʹ��k������Ļ��ѣ���dp[j][k-1]������ֳ�һ�ѣ�j+1��i�ֳ�һ�ѣ��м���һ�����������Ҳ�����ܹ�����k������
        }///a[i]-a[j]���ǵ��ۣ���һ������ͣ�Ҳ����˵����i����Ʒ��Ӧ�ú�i-j����Ʒ��Ϊһ�ѣ�i��j�ľ����𽥱�С
//        for(int i=1; i<=n; i++)
//            for(int j=0; j<=d; j++)
//                printf("%d%c",dp[i][j],j==d?'\n':' ');
        for(int i=0; i<=d; i++)ans=min(ans,dp[n][i]); ///[i][k]��ʾ��i����Ʒʱ��k���������С����
        printf("%d\n",ans);///���õ�n����Ʒʹ��0��d������Ĳ�ͬ���ѣ�ȡ��Сֵ��ÿ������Ļ������ڲ�ͬλ���е���С����
    }
}
