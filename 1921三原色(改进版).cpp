#include<stdio.h>///��ԭɫ������ȡ����������������Ȼ����Ϊ�й������䣬��������Ĳ��ּӻ����ͺ���
long long gcd(long long x,long long y)
{
    while(y!=0)///���Լ��
    {
        long long z=y;///����Ҫ��ס�����������ķ�������ʱ�洢b
        y=x%y;
        x=z;
    }
    return x;
}
long long lcm(long long a,long long b)///��С������
{
    long long c=gcd(a,b);
    return a*b/c;
}
int main()
{
    long long x,y,z,n;
    while(scanf("%lld%lld%lld%lld",&x,&y,&z,&n)!=EOF)
    {
        long long red=lcm(x,y);///��ɫ���沿�֣��������������������
        long long yellow=lcm(x,z);
        long long green=lcm(y,z);
        long long black=lcm(red,z);///�������沿�֣����ظ������Ĺ���������
        long long much=n/red+n/yellow+n/green-2*(n/black);///������ͳ��������Ϊ�����������ĸ���
        printf("%lld\n",n-much);///������������������
    }
    return 0;///ע�������n���ڣ��ж���m�ı�����ֱ����n/m����
}
