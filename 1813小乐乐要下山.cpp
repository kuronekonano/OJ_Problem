#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    int a[505][505],i,j,n,dp[505][505];
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0; i<n; i++)
        {
            for(j=0; j<=i; j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        memset(dp,0,sizeof(dp));
        for(j=0; j<n; j++) //���һ�й�Ϊdp�����ڴ洢
        {
            dp[n-1][j]=a[n-1][j];
        }
        for(i=n-2; i>=0; i--)
        {
            for(j=0; j<=i; j++)
            {
                dp[i][j]=a[i][j]+min(dp[i+1][j],dp[i+1][j+1]);//�ӵ����ڶ��п�ʼ��ֵ�����
            }
        }
        printf("%d",a[0][0]);//ɽ���ǿ϶�Ҫ�ߵ�
        i=0;//��ʼ����0��ʼ��Ҳ����λ��λ��ɽ��
        j=0;
        while(i<n-1)//һֱ���㵽n-2�У������ڶ��У���Ϊ���ʱ�ǵ��м�һ
        {
            if(dp[i+1][j]<dp[i+1][j+1])//����֮ǰdp�������ۼӵ�·��,ͨ���Ƚϸ���λ��֮�����ʹ�С���ж���Сֵ����Ч��a���������·��
            {
                printf(" %d",a[i+1][j]);
                i=i+1;//ÿ�������Ҫ�ǵð������ƶ����Ǹ��ո������λ�ã�������һ����������
            }
            else
            {
                printf(" %d",a[i+1][j+1]);
                i=i+1;
                j=j+1;
            }
        }
        printf("\n");
    }
    return 0;
}
//#include<stdio.h>
//#include<algorithm>
//#include<string.h>
//using namespace std;
//int main()
//{
//    int n,i,j;
//    int a[505][505],dp[505][505];
//    while(scanf("%d",&n)!=EOF)
//    {
//        memset(dp,0,sizeof(dp));
//        for(i=1;i<=n;i++)
//        {
//            for(j=1;j<=i;j++)
//            {
//                scanf("%d",&a[i][j]);
//                if(i==n)
//                {
//                    dp[i][j]=a[i][j];
//                }
//            }
//        }
//        for(i=n-1;i>=1;i--)
//        {
//            for(j=1;j<=i;j++)
//            {
//                dp[i][j]=a[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
//            }
//        }
//        printf("%d",a[1][1]);
//        i=1,j=1;
//        while(i<n)
//        {
//            printf(" %d",dp[i+1][j]<dp[i+1][j+1]?a[i+1][j]:a[i+1][j+1]);
//            i=i+1;
//            j=dp[i+1][j]<dp[i+1][j+1]?j:j+1;
//        }
//        printf("\n");
//    }
//    return 0;
//}

