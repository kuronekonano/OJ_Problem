#include<stdio.h>
int main()
{
    int n,m,a[10005],i,j;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)///n��ľ��
        {
            scanf("%d",&a[i]);
        }
        int maxn=0;///��ʼ��������ֵ
        for(i=0;i<n;i++)///��ͷ����ľ��
        {
            int sum=1;///ȡ���ڱ���ľ�屾��Ϊ1
            for(j=i+1;j<n;j++)///����ľ���ұ���չ
            {
                if(a[j]>=a[i])///Ψ�д��ڵ���ľ�屾��Ĳż���
                {
                    sum++;
                }
                else///һ�����ֶ����Լ���ľ�壬˵��������ڴν�ֹ��ֱ�������
                    break;
            }
            for(j=i-1;j>=0;j--)///��ľ�������չ
            {
                if(a[j]>=a[i])
                {
                    sum++;
                }
                else
                    break;
            }
            maxn=sum*a[i]>maxn?sum*a[i]:maxn;///�������ȡ��ֵ
        }
        printf("%d\n",maxn);///�����ֵ
    }
    return 0;
}
