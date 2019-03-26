#include<stdio.h>///素数筛出所有素数，将素数遍历，找出倒转后不相等且仍为素数的反素数，最后直接输出
#include<string.h>
bool vis[100008];
int emirp[1008],prim[10008],ans;
int rever(int a)
{
    int b=0;
    while(a>0)
    {
        b=b*10+a%10;
        a/=10;
    }
    return b;
}
void inti()
{
    memset(vis,true,sizeof(vis));
    int num=0;
    for(int i=2;i<=100000;i++)
    {
        if(vis[i])
        {
            prim[num++]=i;
            for(int j=i+i;j<=100000;j+=i)
            {
                vis[j]=false;
            }
        }
    }
    ans=0;
    for(int i=4;i<num;i++)
    {
        if(vis[rever(prim[i])]&&rever(prim[i])!=prim[i])
        {
            emirp[ans++]=prim[i];
        }
    }
}
int main()
{
    inti();
    int n,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",emirp[n-1]);
    }
}
