#include<stdio.h>///��Ŀ���������0.00005���������ˣ�����ûҪ��
#include<math.h>///�򵥶��֣���ʼ�߽�l=0,r=100
double workout(double x)
{
    return 8*pow(x,4)+2*pow(x,2)+7*pow(x,3)+3*x+6;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        double y;
        scanf("%lf",&y);
        if(y>8*pow(100,4)+2*pow(100,2)+7*pow(10,3)+3*100+6||y<6)///�ж�yֵ��Χ
        {
            printf("No solution!\n");
            continue;
        }
        else
        {
            double l=0,r=100,mid;
            while(r-l>1e-7)///���
            {
                mid=(l+r)/2;
                if(workout(mid)>y)///����ѭ��
                {
                    r=mid;
                }
                else
                {
                    l=mid;
                }
            }
            printf("%.4f\n",mid);///������λ����
        }
    }
    return 0;
}
