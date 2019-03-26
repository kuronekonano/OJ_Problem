#include<stdio.h>
int main()
{
    int n,i,j,s,x,y;
    while(scanf("%d",&n)!=EOF)
    {
        y=n;
        for(i=1;i<=n;i++)//第i层
        {
            s=10+2*(i-1);//有s个i输出
            for(j=y-1;j>0;j--)//每层输出空格数
            {
                printf(" ");
            }
            for(x=1;x<=s;x++)//输出x个i
            {
                printf("i");
            }
            printf("\n");
            y--;
        }
    }
    return 0;
}
