#include<stdio.h>///����DP
#include<algorithm>
#include<string.h>
using namespace std;///���ҵ���������������С�;ͺ�
int a[1001][1001];
int b[1001][1001];
int main()
{
    int n,i,j;
    while(scanf("%d",&n)!=EOF)
    {
        memset(a,0,sizeof(a));
        for(i=0;i<n;i++)///����
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        memset(b,0,sizeof(b));
        b[0][0]=a[0][0];///�߽��ʼ����
        for(i=0,j=1;j<n;j++)
        {
            b[i][j]=b[i][j-1]+a[i][j];
        }
        for(i=1,j=0;i<n;i++)
        {
            b[i][j]=b[i-1][j]+a[i][j];
        }
        for(i=1;i<n;i++)///dp
        {
            for(j=1;j<n;j++)
            {
                b[i][j]=a[i][j]+min(b[i-1][j],b[i][j-1]);///��С��dp
            }
        }
        printf("%d\n",b[i-1][j-1]);///��������ڵ�������
    }
    return 0;
}
