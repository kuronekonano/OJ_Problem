#include<stdio.h>
int main()
{
    int n,t;
    long long a[10005];
    a[1]=2;
    for(int i=2;i<=10000;i++)
    {
        a[i]=a[i-1]+6*(i-1);///�����������������԰�ƽ��ֳɼ�������ĵ��ƹ�ʽ
    }
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%lld\n",a[n]);
    }
    return 0;
}
