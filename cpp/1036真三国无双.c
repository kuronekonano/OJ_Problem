#include<stdio.h>
int main()
{
    int a,b,d,t;
    float s;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&a,&b,&d);
        s=(a+b-d)/10.00;
        if(d<b||a+b>=3600+d)//�ͷ�ʱ�����С�ڻ���ڿ���ʱ�䣬�Ҷ������ͷ�ʱ��С��360�ȡ�10�ӿ���ʱ��
        {
            printf("IMPOSSIBLE\n");
        }
        else if(a+b-d>=0)//��ֹ�������ͷ�ʱ��С�ڿ���ʱ������ָ���ʱ�����
        {
            printf("%.2f\n",s);
        }
        else
        {
            printf("0.00\n");
        }
    }
    return 0;
}
