#include<stdio.h>
#include<string.h>
#define FOR(x) for(int x=-50;x<=50;x++)///�Զ���ѭ��������x��Ϊһ���βΣ������Ѿ�����õ�FOR������
short int hashi[25000001];///��������С��������50^4=6250000������Ϊ��a1��a2���ٳ�2������Ϊ�Ǵ��������෴�����ٳ�2=4*50^4
int main()
{
    int a1,a2,a3,a4,a5;
    while(scanf("%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5)!=EOF)///a1~a5,x1~x5�ķ�Χ����-50~50��
    {
        memset(hashi,0,sizeof(hashi));
        FOR(x1)///x1��x2�������������x1�൱�ڷ���FOR�����Զ��庯���еĲ���
        {
            if(x1)///x1�൱��i����һֱ�仯��������if��Ϊ���ų�0
            {
                FOR(x2)
                {
                    if(x2)
                    {
                        int sum=a1*x1*x1*x1+a2*x2*x2*x2*(-1);///�������ƶ�������ĸ�λ��������Ϊ�����෴�������������-1����������������
                        if(sum<0)///ʵ������ֻ�����鼫�޵�1/2��ʵ�ʾ������x1+x2��Ȼ���Ӧ��������Ǻ͵��෴���ĸ���
                        {
                            sum=sum+25000000;
                        }
                        hashi[sum]++;///�˴�x1+x2���ܲ�ֹһ�ԣ���˵�ʱ�Ӹ���ʱ��Ҳ��һһ���䣬����һ���ͼ���ô���
                    }
                }
            }
        }
        int flag=0;///�ܸ���������
        FOR(x3)
        {
            if(x3)
            {
                FOR(x4)
                {
                    if(x4)
                    {
                        FOR(x5)
                        {
                            if(x5)
                            {
                                int sum=a3*x3*x3*x3+a4*x4*x4*x4+a5*x5*x5*x5;///����ȣ����ﲻ��������ֻ���ж�
                                if(sum<0)
                                {
                                    sum=sum+25000000;
                                }
                                if(hashi[sum])
                                {
                                    flag=flag+hashi[sum];
                                }
                            }
                        }
                    }
                }
            }
        }
        printf("%d\n",flag);
    }
    return 0;
}