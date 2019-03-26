#include<stdio.h>
#include<string.h>
struct sc
{
    char name[16];
    char kind;
} pk[10005];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
    {
        scanf("%s %c",pk[i].name,&pk[i].kind);
    }
    char a[16],b[16];
    while(m--)
    {
        scanf("%s%s",a,b);
        int j,k;
        for(j=1; j<=n; j++)
        {
            if(strcmp(a,pk[j].name)==0)
            {
                break;
            }
        }
        for(k=1;k<=n;k++)
        {
            if(strcmp(b,pk[k].name)==0)
            {
                break;
            }
        }
        if((pk[j].kind=='T'&&pk[k].kind=='Z')||(pk[j].kind=='P'&&pk[k].kind=='T')||(pk[j].kind=='Z'&&pk[k].kind=='P'))
        {
            printf("XiaoM Wins!\n");
        }
        else if(pk[j].kind==pk[k].kind)
        {
            printf("End in a draw!\n");
        }
        else
        {
            printf("TianT Wins!\n");
        }
    }
    return 0;
}
