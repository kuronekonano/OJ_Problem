#include<stdio.h>
int main()
{
    int t,n,k,sum;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        if(k==13)//������13�׸�ĵ��ӵ���12��������
        {
            k--;
        }
        sum=n/k;
        int s=n%k;
        if(s!=0)
        {
            sum++;
            if(s==13&&n<k||s==13&&k==14)//������Ϊ13�׸��ʱ���ǿ��Դ�ǰ��ĵ�����ȡһ�������ϵģ�����ÿ�ŵ���װ14�׸�����
            {
                sum++;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
