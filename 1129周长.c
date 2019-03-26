#include<stdio.h>
int main()
{
    int a,i;
    while(scanf("%d",&a)!=EOF)
    {
        int b=0;//初始化b
        if(a<3)
        {
            printf("0\n");//小于3的周长不可能有多边形
        }
        else
        {
            for(i=3;i<=a;i++)
            {
                if(a%i==0)
                {
                    b++;//用b计数
                }
            }
            printf("%d\n",b);
        }
    }
    return 0;
}
