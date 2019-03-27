#include<stdio.h>
int main()
{
    int t,cas=0;
    double a,b;
    scanf("%d",&t);
    while(t--)
    {
        cas++;
        scanf("%lf%lf",&a,&b);
        if(a>=0.05&&b==0.01||a>=0.5&&b==0.1||a>=5&&b==1||a>=50&&b==10)
        {
            printf("Case #%d: 0.02\n",cas);
        }
        else
        {
            printf("Case #%d: 0.01\n",cas);
        }
    }
}
