#include<stdio.h>
#include<math.h>
int main()
{
    int t,i;
    float x1,y1,x2,y2,d;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%f%f%f%f",&x1,&y1,&x2,&y2);
        d=sqrt(pow(x2-x1,2)+pow(y2-y1,2));
        printf("%.2f\n",d);
    }
    return 0;
}
