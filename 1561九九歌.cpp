#include<stdio.h>
int xxx(int x)
{
    int flag=0;
    while(x!=0)
    {
        x/=10;
        flag++;
    }
    return flag;
}
int main()
{
    int j,i,n;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=i;j++)
            {
                printf("%*d x %*d = %*d%c",xxx(n*n)+1,i,xxx(n*n)+1,j,xxx(n*n)+1,i*j,i==j?'\n':' ');///动态控制字符长度！！！！
            }
        }
        printf("\n");
    }
    return 0;
}
