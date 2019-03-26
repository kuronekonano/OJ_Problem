#include<stdio.h>
int main()
{
    int a,b,c;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF)
    {
        if(a>168&&b>168&&c>168)printf("NO CRASH\n");
        else
        {
            int ans;
            if(a<=168)ans=a;
            else if(b<=168)ans=b;
            else ans=c;
            printf("CRASH %d\n",ans);
        }
    }
}
