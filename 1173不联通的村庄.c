#include<stdio.h>
int main()
{
    int m,n;//需考虑任意排列的路线，不仅仅是最少路线
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(m<=(n-1)*(n-2)/2)//将一个点孤立，相当于不连接那个村庄，之后计算剩下的村庄互相连接的路线最大值，若超过最大值，则所有村庄连接
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
