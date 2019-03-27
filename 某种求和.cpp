#include<stdio.h>
int main()
{
    float sum,a,i,t,b=1,c=2;
    for(i=1;i<=20;i++)
    {
        t=c/b;
        a=c;
        c=b+c;
        b=a;
        sum=sum+t;
    }
    printf("%.3f\n",sum);
    return 0;
}
