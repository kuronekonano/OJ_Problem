#include<stdio.h>
#include<string.h>
#include<algorithm>
#define LL long long
using namespace std;
LL a[100005],dp1[100005],dp2[100005];
int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        memset(dp1,0,sizeof(dp1));
        memset(dp2,0,sizeof(dp2));
        for(int i=1; i<=n; i++)scanf("%d",&a[i]);
        for(int i=k+1; i<=n; i++)///��k+1λ��ʼ�ƣ����������i��i-kλ���
        {
            dp1[i]=dp2[i-k]+a[i]+a[i-k];///dp1��ʾ ȡ  i-2k��i-3k�ĺ� �Լ�i��i-k�ĺ���Ϊ��ѡֵ
            dp2[i]=max(dp1[i-k],dp2[i-k]);///dp2��ʾ����iλʱ��ѡi-k��i-2k �ĺ�  ��   i-k�����ֵ  �Ƚ�ȡ�ϴ�ֵ
        }
        LL ans=0;
        for(int i=n-k+1; i<=n; i++)ans+=max(dp1[i],dp2[i]);///���ȡ���kλ�ܺ���ͣ�Ҳ����k�����У�k�γ�ȡ���ܺ�
        printf("%lld\n",ans);
    }
}
