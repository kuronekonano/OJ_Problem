#include<stdio.h>
int main()
{
    int t;
    double c;
    scanf("%d",&t);
    while(t--)
    {
        char wet;
        scanf("%lf %c",&c,&wet);
        if(wet=='C')
        {
            c=(9/(double)5*c)+32;
            printf("%.0fF\n",c);
        }
        else
        {
            c=(5/(double)9)*(c-32);
            printf("%.0fC\n",c);
        }
    }
    return 0;
}
