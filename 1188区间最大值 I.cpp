#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int n,a[5005],i,t,flag=1;
    while(scanf("%d",&n)!=EOF)///n����
    {
        for(i=1; i<=n; i++)///����n����
        {
            scanf("%d",&a[i]);
        }
        scanf("%d",&t);///t������
        int j=t-1;
        int x,y;
        int b[5005];///���ֵ�洢����
        while(t--)///��Ϊ�ǵ��ŵģ����Ե�t�η����ǵ�1��
        {
            scanf("%d%d",&x,&y);///��x��y��������
            int max=a[x];///ȡ���ֵ�ǳ�ʼx
            for(i=x; i<=y; i++)///����x��y
            {
                if(a[i]>max)///ȡmax��ֵ
                {
                    max=a[i];
                }
            }
            b[t]=max;///��¼��t�ε���ֵ
        }
        printf("Case %d:\n",flag++);
        for(i=j;i>=0;i--)///����������Ǵ�ͷ���
        {
            printf("%d\n",b[i]);
        }
    }
    return 0;
}
