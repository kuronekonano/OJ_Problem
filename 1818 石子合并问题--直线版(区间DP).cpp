#include<stdio.h>///����DP
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    int a[105],n,i,j,k,len,sum[108],dpmax[108][108],dpmin[106][106];
    while(scanf("%d",&n)!=EOF)
    {
        memset(sum,0,sizeof(sum));///������飬���ĳ��������ʯ��������
        memset(dpmax,0,sizeof(dpmax));///������dp
        memset(dpmin,0x3f,sizeof(dpmin));///��С���dp
        sum[0]=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            sum[i]=sum[i-1]+a[i];///�������ͬʱ�ۼ����
            dpmax[i][i]=0;///��άdp�������±�ij��ʾ�����i��j��ʯ��������
            dpmin[i][i]=0;
        }
        for(len=2;len<=n;len++)///dp���䳤�ȣ��ӳ���Ϊ2��������ӵ�����Ϊn�����䣬һֱɸѡ����ֵ
        {
            for(i=1;i<=n-len+1;i++)///��ĳ��len�ĳ����£�������i��i+����=j��ξ���
            {
                j=i+len-1;
                for(k=i;k<j;k++)///��i��j��γ�len�ľ����£�ȡĳ���е�k���ֳ����ݣ��Ӷ�ɸѡ������͵�����ֵ
                {
                    dpmax[i][j]=max(dpmax[i][j],(dpmax[i][k]+dpmax[k+1][j]+sum[j]-sum[i-1]));///Ҳ��������i��k��������k+1��j֮�͡�������ͺ��������ֵ
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
