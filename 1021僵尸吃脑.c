#include<stdio.h>
int main()
{
    int i,n,x,y;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&x,&y);
        if(x<y)
        {
            printf("NO BRAINS\n");
        }
        if(x>=y)
        {
            printf("MMM BRAINS\n");
        }
    }
    return 0;
}
