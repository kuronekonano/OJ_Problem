#include<stdio.h>
int main()
{
    float a,b,c;
    while(scanf("%f%f",&a,&b)!=EOF)
    {
        c=a/b;
        printf("%.2f\n",c);
    }
    return 0;
}
