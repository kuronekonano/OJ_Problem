#include<stdio.h>///ע��������������������

int main()
{
    double x1,x2,x3,y1,y2,y3,xl,yl;
    while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&xl,&yl)!=EOF)
    {
        double turn1=(x2-x1)*(yl-y1)-(y2-y1)*(xl-x1);///�˴�������ü���
        double turn2=(x3-x2)*(yl-y2)-(y3-y2)*(xl-x2);
        double turn3=(x1-x3)*(yl-y3)-(y1-y3)*(xl-x3);
        if(turn1<0&&turn2<0&&turn3<0)///��ʱҪע�⣬˳ʱ��ʱ���������ڣ���ȫ�����ұ�
        {
            printf("Die\n");
        }
        else if(turn1>0&&turn2>0&&turn3>0)///��ʱ��ʱ��������������ȫ������ߣ���Ϊ���������������������Ժ���˳�������ʱ��˳ʱ�붼Ҫ���ǣ���ͬ�ž������ڲ�
        {
            printf("Die\n");
        }
        else
            printf("Live\n");
    }
    return 0;
}
