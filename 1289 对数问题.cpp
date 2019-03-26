#include<stdio.h>
#include<math.h>
int main()
{
    int i;
    double a,b;
    while(scanf("%lf%lf",&a,&b)!=EOF)
    {
        printf("%d\n",(int)(log((double)b)/log((double)a)));
    }
}
