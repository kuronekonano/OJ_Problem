#include<stdio.h>///���ֻ���    ��Ŀ��ȱ�ݣ���a=9,b=4,c=1ʱ�������ڵ�������������£�Ҳ�н⣬���뿼�ǣ�Լ��-0.39��������ֵȡ0
#include<math.h>///��������������Ϊc=1�ˣ��������ʲ��죬����a bֵ��c���
int a,b,c;
double unknow(double ans)///a+b��ֵӦ����c
{
    return pow(a,ans)+pow(b,ans)-pow(c,ans);
}
int main()
{
    double l,r;
    while(scanf("%d%d%d%lf%lf",&a,&b,&c,&l,&r)!=EOF)
    {
        if(unknow(l)<0||(unknow(l)>0&&unknow(r)>0))///ֻ�����˵����ݼ���ȱ�ݣ�
        {
            printf("No Answer!\n");///���Բ���ֱ���жϵ������ݼ���NO ANSWER
        }
        else
        {
            double mid;
            while(r-l>1e-7)
            {
                mid=(l+r)/2;
                if(unknow(mid)>0)///�����㷨����ô���յ����ݼ������д��
                {
                    l=mid;
                }
                else
                {
                    r=mid;
                }
            }
            printf("%f\n",mid);
        }
    }
    return 0;
}
