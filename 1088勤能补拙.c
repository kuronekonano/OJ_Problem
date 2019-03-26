#include<stdio.h>
int main()
{
    float a,b,c;
    while(scanf("%f%f",&a,&b)!=EOF)
    {
        c=0.99*a+0.01*b;
        printf("%.2f\n",c);
    }
    return 0;
}
