#include<stdio.h>
#include<string.h>///��������������޸ĸ��ж���������
#include<algorithm>
using namespace std;
int main()
{
    int i,j,a[1080],dp[1080],n;
    int t;
    scanf("%d",&t);///t������
    while(t--)
    {
        scanf("%d",&n);///n����
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        memset(dp,0,sizeof(dp));///���dp����
        int flag;
        dp[0]=1;///��ʼ���߽�
        for(i=1;i<n;i++)///��ʼdp�����ӵڶ�������ʼ
        {
            flag=dp[i];///flag��¼Ŀǰ����г���
            for(j=0;j<i;j++)///�ڲ�ѭ���ӵ�һ�����������i����
            {
                if(a[i]<=a[j]&&dp[j]>flag)///�Ա�һ��С�ڻ����ǰ���Ǹ������ҳ��ȴ���flag��¼�ĳ��ȣ��ͽ����Ϊ���ֵ
                {
                    flag=dp[j];///��Ϊ����г�����ʱ��¼��flag��
                }
            }
            dp[i]=flag+1;///��һ������+1�����ձ������flag�ڴ���ǵ�i����֮ǰ������ȣ���ô�ټ�i����(+1)���Ǵ�ʱ�������
        }
        sort(dp,dp+n);///�ҳ���󳤶�
        printf("%d\n",dp[n-1]);
    }
    return 0;
}
