#include<stdio.h>
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        long long a,b;
        scanf("%lld%lld",&a,&b);
        printf("Case #%d:\n",cas++);///ͨ��һ�µ������������õ�(A^2+B^2)/A*B<=(C^2+D^2)/C*D
        if(a==b)///�������ʽ��A------------B����У���ȡ���������Ǳض���A/B+B/AС�ģ�����ȡ��A��B�͸պõ��ڣ���˲����д���A/B+B/A�������պõ��ڵ�Ҳ����A B����
        {
            printf("1\n%lld %lld\n",a,b);
        }
        else///���Թ̶��ģ�ֱ������ͺã�ע����10^18��Ҫ��long long �洢
        {
            printf("2\n%lld %lld\n%lld %lld\n",a,b,b,a);
        }
    }
    return 0;
}
