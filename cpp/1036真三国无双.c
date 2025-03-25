#include<stdio.h>
int main()
{
    int a,b,d,t;
    float s;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&a,&b,&d);
        s=(a+b-d)/10.00;
        if(d<b||a+b>=3600+d)//释放时间必须小于或等于空中时间，且动画加释放时间小于360度×10加空中时间
        {
            printf("IMPOSSIBLE\n");
        }
        else if(a+b-d>=0)//防止动画加释放时间小于空中时间而出现负数时间情况
        {
            printf("%.2f\n",s);
        }
        else
        {
            printf("0.00\n");
        }
    }
    return 0;
}
