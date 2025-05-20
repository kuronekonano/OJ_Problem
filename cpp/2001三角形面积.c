#include<stdio.h>
#include<math.h>
int main()
{
    double s,a,b,c,p;
    int i,j,t;


    scanf("%d",&t);
    int x[4],y[4];//数组尽量开大，否则在后台的地址是随机分配的，刚好或小了的数组可能使各地址间的数据重合并混乱
    for(i=1;i<=t;i++)//(i=t;i>=1;i--)
    {
        for(j=1;j<=3;j++)
        {
           scanf("%d%d",&x[j],&y[j]);
        }
        a=sqrt(pow(x[1]-x[2],2)+pow(y[1]-y[2],2));
        b=sqrt(pow(x[1]-x[3],2)+pow(y[1]-y[3],2));
        c=sqrt(pow(x[3]-x[2],2)+pow(y[3]-y[2],2));
        p=(a+b+c)/2;
        s=sqrt(p*(p-a)*(p-b)*(p-c));
        if(a+b<=c||a+c<=b||b+c<=a)
        {
            printf("not a triangle!\n");
        }
        else
        {
            printf("area=%.2f\n",s);
        }
    }
    return 0;
}
