#include<stdio.h>
int main()
{
    unsigned long long a[1000];//��89��쳲�������̫����
    int n,k,m,i;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        a[1]=n;
        a[2]=m;
        for(i=3;i<=k;i++)
        {
            a[i]=a[i-1]+a[i-2];
        }
        printf("%llu\n",a[k]);
    }
    return 0;
}
