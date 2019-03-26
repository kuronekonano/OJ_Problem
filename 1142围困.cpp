#include<stdio.h>///注意分清叉积与点积，叉乘与点乘

int main()
{
    double x1,x2,x3,y1,y2,y3,xl,yl;
    while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&xl,&yl)!=EOF)
    {
        double turn1=(x2-x1)*(yl-y1)-(y2-y1)*(xl-x1);///此处叉积是用减法
        double turn2=(x3-x2)*(yl-y2)-(y3-y2)*(xl-x2);
        double turn3=(x1-x3)*(yl-y3)-(y1-y3)*(xl-x3);
        if(turn1<0&&turn2<0&&turn3<0)///此时要注意，顺时针时在三角形内，是全部在右边
        {
            printf("Die\n");
        }
        else if(turn1>0&&turn2>0&&turn3>0)///逆时针时，在三角形内是全部在左边，因为不清楚输入的三个坐标是以何种顺序，因此逆时针顺时针都要考虑，即同号就是在内部
        {
            printf("Die\n");
        }
        else
            printf("Live\n");
    }
    return 0;
}
