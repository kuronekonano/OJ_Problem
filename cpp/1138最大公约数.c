//#include<stdio.h>
//int main()
//{
//    int a,b,c;
//    while(scanf("%d%d",&a,&b)!=EOF)//���ˣ�������С��������������֮���������Լ��
//    {
//        while(a%b!=0)
//        {
//            c=a%b;//շת�������ŷ������㷨�������Լ������12��9��12%9=3��9%3=0�������Լ��Ϊ3��
//            a=b;//�ݹ�˼��
//            b=c;//��a<bʱ��a,bλ�õ���
//        }
//        printf("%d\n",b);
//    }
//    return 0;
//}
#include<stdio.h>///���Ʒ���ע������ʱ�洢bֵ������a�У�ͬ��������Ϊ��ģ��0�������޷�����ѭ�������
long long gcd(long long a,long long b)
{
    while(b!=0)
    {
        long long c=b;
        b=a%b;
        a=c;
    }
    return a;
}
int main()
{
    long long a,b,c;
    while(scanf("%lld%lld",&a,&b)!=EOF)
    {
//        long long h=b;
//        long long t=a;
//        long long x;
//        x=t*h/gcd(a,b);
        printf("%lld\n",gcd(a,b));
//        printf("%lld\n",x);
    }
    return 0;
}
//#include<stdio.h>///1076�ݹ鷨��������������޷�����GCDѭ�������
//unsigned long gcd(unsigned long a,unsigned long b)
//{
//    if(b==0) return a;
//    else return gcd(b, a%b);
//}
//int main()
//{
//    unsigned long a,b,c;
//    while(scanf("%lu%lu",&a,&b)!=EOF)
//    {
//        printf("%lu\n",gcd(a,b));
//    }
//    return 0;
//}
