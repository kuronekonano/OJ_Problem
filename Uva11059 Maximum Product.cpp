#include<stdio.h>///����ö��
int main()
{
    int a[21],i,j,n,k,M=0;
    long long max;
    while(scanf("%d",&n)!=EOF)
    {
        M++;
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        max=0;
        long long sum;///�ӵ�һ���׳˵����һ������Ϊ���������ĳ˻������˿����������������
        for(i=0; i<n; i++)///��1��5����1��2��3��4��5��ѡȡmax���ٴ�2��5��ѡȡ���ֵ������ÿһ�����������ֶ�ѡȡ�˻����ֵ�����վ��������˻����ֵ
        {
            sum=a[i];
            if(sum>max)///�˴�Ϊ��ֹ����Ϊ1������������Ƚϵ�ǰ��λ���֣�a[0]���ĳ˻���max��ʼ���ĳ˻�0,
            {
                max=sum;
            }
            for(j=i+1; j<n; j++)
            {
                sum=sum*a[j];
                if(sum>max)
                {
                    max=sum;
                }
            }
        }
        printf("Case #%d: The maximum product is %lld.\n\n",M,max);
    }
    return 0;
}
