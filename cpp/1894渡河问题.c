#include<stdio.h>
#include<math.h>
int main()
{
    double x1,t1,x2,t2,w;
    double t,v1,v2,v;
    while(scanf("%lf%lf%lf%lf%lf",&x1,&t1,&x2,&t2,&w)!=EOF)
    {
        v1=(x1/t1+x2/t2)/2;
        v2=(x1/t1-x2/t2)/2;
        v=sqrt(v1*v1-v2*v2);
        t=w/v;
        printf("%.2f\n",t);
    }
    return 0;
}
