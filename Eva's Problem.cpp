#include<stdio.h>
int main()
{
    double t,a,b,c,d,e;
    scanf("%lf",&t);
    while(t--)
    {
        scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
        if(d/c==c/b)
        {
            e=d/c*d;
            printf("%.0f %.0f %.0f %.0f %.0f\n",a,b,c,d,e);
        }
        else if(d-c==c-b)
        {
            e=d-c+d;
            printf("%.0f %.0f %.0f %.0f %.0f\n",a,b,c,d,e);
        }
    }
    return 0;
}
