#include<bits/stdc++.h>///机器人行走，去掉中间或后面或前面一些指令后，机器人能回到原点的最大指令数，只用计数出去和回来的次数就好
using namespace std;
int main()
{
    int n;
    char a[1002];
    while(scanf("%d",&n)!=EOF)
    {
        scanf("%s",a);
        int R=0,L=0,U=0,D=0,ans=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]=='L')L++;
            if(a[i]=='R')R++;
            if(a[i]=='U')U++;
            if(a[i]=='D')D++;
        }
        ans=2*min(L,R)+2*min(U,D);
        printf("%d\n",ans);
    }
}
