#include<stdio.h>
#include<math.h>

int main()
{
    double a;
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%d",&a,&n);
        a=pow(10,n)*a;
        printf("%d\n",(int)a%10);
    }
    return 0;
}
