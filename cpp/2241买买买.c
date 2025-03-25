#include<stdio.h>
int main()
{
    int t,n,x,k,i,flag;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&x,&k);
        int pi[n],ci[n];
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&pi[i],&ci[i]);
        }
        flag=0;
        for(i=0;i<n;i++)
        {
            if(pi[i]>=x&&ci[i]==k)//必须美观度在标准X之上，且价格也必须等于K值，不需要所有符合条件的裙子加起来之和等于K值
            {
                flag++;
            }
        }
        if(flag>0)
        {
            printf("Yes\n");
        }
        else if(flag==0)
        {
            printf("No\n");
        }
    }
    return 0;
}
