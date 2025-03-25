#include<stdio.h>
int main()
{
    int i,p,q,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&p,&q);
        i=p*1+q;
        if(i%2!=0)
        {
            if(((p*2+q)%2)!=0)
                printf("Orz!\n");
            else
                printf("PleaseCallMeFlash!\n");
        }
        else if(i%2==0)
        {
            if(((p*2+q)%2)==0)
            {
                printf("JiaoZhuV5!\n");
            }
            else
                printf("PleaseCallMeFlash!\n");
        }
    }
    return 0;
}
