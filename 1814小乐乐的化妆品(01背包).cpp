#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct worth
{
    int c;//���
    int val;//��ֵ
}Get[106];

int main()
{
    int i,n,v,dp[105][1005];//dp�������ǻ�ױƷ����������������
    while(scanf("%d%d",&n,&v)!=EOF)//n����Ʒ�������Ϊv
    {
        memset(dp,0,sizeof(dp));//ע���������
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&Get[i].c,&Get[i].val);
        }
        for(i=Get[1].c;i<=v;i++)//��ʼ����һ����ױƷ�����ݣ���˼�ǣ��ڵ�һ�У�Ҳ���Ǵӵ�һ����Ʒ��ʼ��
        {
            dp[1][i]=Get[1].val;///�г�����̬�滮��񣬺����Ǳ�����װ�Ĵ�С��һֱ��˳����������ô�����е�һ����Ʒ����Ȼ��ֻ�ܷŵ���װ���Ǹ���Ʒ������
        }
        for(int i=2;i<=n;i++)//�Ѿ���ɳ�ʼ��һ����Ʒ�İ��ţ��ӵڶ�����Ʒ��ʼ����
        {
            for(int j=1;j<=v;j++)//���ȴҪ��1��ʼ����
            {
                if(j>=Get[i].c)//ע������Ҫ�ж�Ŀǰ�������Ƿ����Ҫװ��Ʒ���������������Ͳ�װ��ֱ��������һ������
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-Get[i].c]+Get[i].val);//��ʵ���ң��Ǽ�����ǰ��Ʒ���������װ�������Ʒ�����Ļ��㣬���Ǳ���ԭ�������������㡣
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
//        for(i=1;i<=n;i++)//��̬�滮�����ĳ���������
//        {
//            for(int j=1;j<=v;j++)
//            {
//                printf("%5d",dp[i][j]);
//            }
//            printf("\n");
//        }
        printf("%d\n",dp[n][v]);
    }
    return 0;
}
