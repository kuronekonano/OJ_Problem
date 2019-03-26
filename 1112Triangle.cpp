#include<stdio.h>
#include<math.h>
int main()
{
    double a,b,c,t,s;
    int n;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%lf%lf%lf",&a,&b,&c);
        if(a+b<=c||b+c<=a||a+c<=b)
        {
            printf("Illegal!\n");
        }
        else
        {
            t=(a+b+c)/2;
            s=sqrt(t*(t-a)*(t-b)*(t-c));
            printf("%.1f\n",s);
        }
    }
    return 0;
}
