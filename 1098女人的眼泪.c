#include<stdio.h>
int main()
{
    int t,i;
    float p,m,v;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%f%f",&m,&v);
        p=m/v;
        printf("%.04f\n",p);
    }
    return 0;
}
