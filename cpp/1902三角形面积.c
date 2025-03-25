#include<stdio.h>
#include<math.h>
int main()
{
    int i,t;
    float s,p;
    while(scanf("%d",&t)!=EOF)
    {
        int a[t],b[t],c[t];
        for(i=t;i>=1;i--)
        {
            scanf("%d%d%d",&a[i],&b[i],&c[i]);
        }
        for(i=t;i>=1;i--)
        {
            if(a[i]+b[i]<=c[i]||a[i]+c[i]<=b[i]||b[i]+c[i]<=a[i])
            {
                printf("it's not a triangle!\n");
            }
            else
            {
                p=(a[i]+b[i]+c[i])/2;
                s=sqrt(p*(p-a[i])*(p-b[i])*(p-c[i]));
                printf("%.02f\n",s);
            }
        }
    }
    return 0;
}
