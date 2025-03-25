#include<stdio.h>
int main()
{
    int t,i,j,n,x,k;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d%d",&k,&j);
        for(n=1;n<=j;n++)
        {
            printf(">+");
            for(x=1;x<=k-2;x++)
            {
                printf("-");
            }
            printf("+>\n");
        }
    }
    return 0;
}
