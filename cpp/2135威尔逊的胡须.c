#include<stdio.h>
int main()
{
    int n,t;
    while(scanf("%d",&n)!=EOF)
    {
        if(n<4)
        {
            printf("0\n");
        }
        else if(n<8&&n>=4)
        {
            printf("1\n");
        }
        else if(n>=8&&n<16)
        {
            t=n/8*3+n%8/4*1;
            printf("%d\n",t);
        }
        else
        {
            t=n/16*9+(n%16)/8*3+(n%8)/4*1;//����16����ģ�ٳ�8��֮������ģ8��������4����������������С����
            printf("%d\n",t);
        }
    }
    return 0;
}
