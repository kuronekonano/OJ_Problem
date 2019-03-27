#include<stdio.h>
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int main()
{
    int m,n,z;
    while(scanf("%d%d%d",&n,&m,&z)!=EOF)
    {
        int lcm=n*m/gcd(n,m),ans=0;
        for(int i=lcm;i<=z;i+=lcm) ans++;
        printf("%d\n",ans);
    }
}
