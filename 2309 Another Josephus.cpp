#include<stdio.h>
int main()
{
    int n,t,x,y;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&x,&y);
        int ans=0;
        for(int i=2;i<=n;i++)
        {
            if(i&1)ans=(ans+x)%i;
            else ans=(ans+y)%i;
        }
        printf("%d\n",ans);
    }
    return 0;
}
