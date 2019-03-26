#include<stdio.h>
#include<math.h>
int main()
{
    double r,h,v,s,pi=acos(-1.0);
    while(scanf("%lf%lf",&h,&r)!=EOF)
    {
        s=pi*r*r;
        v=s*h/3;
        printf("%.2f\n",v);
    }
    return 0;
}
