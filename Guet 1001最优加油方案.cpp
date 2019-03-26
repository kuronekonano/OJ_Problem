#include<stdio.h>
int main()
{
    int n,k,km[25],i,ans[24];
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        int sum=0,flag=0,j=0;
        bool dis=false;
        for(i=0;i<=k;i++)
        {
            scanf("%d",&km[i]);
            if(km[i]>n)dis=true;
            sum+=km[i];
            if(sum>n)
            {
                ans[j++]=i;
                sum=km[i];
                flag++;
            }
        }
        if(km[k]>n||dis)
        {
            printf("No solution\n");
            continue;
        }
        printf("%d\n ",flag);
        for(i=0;i<j;i++)
        {
            printf("%d%c",ans[i],i==j-1?'\n':' ');
        }
    }
}
