#include<stdio.h>
int main()
{
    int m,n,t,j,i;
    double s,e,a;//必须用双精度型，否则可能数据会损失，如30 15
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        s=1;e=1;
        if(m>n||(m==0&&n==0))
        {
            printf("0\n");
        }
        else if(m==n||m==0)
        {
            printf("1\n");
        }
        else
        {
            for(i=n;i>n-m;i--)
            {
                s=s*i;
            }
            for(j=m;j>0;j--)
            {
                e=e*j;
            }
            a=s/e;
            printf("%.0f\n",a);
        }
    }
    return 0;
}
