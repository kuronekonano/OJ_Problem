#include<stdio.h>///第一个不相同的二进制位数
#include<string.h>///区间连续或，且操作
long long num[65];
void inti()
{
    num[0]=1;
    for(int i=1; i<63; i++)
    {
        num[i]=num[i-1]*2;
    }
}
int main()
{
    inti();
    long long a,b,t,cas=0;
    char aa[70],bb[70],cc[70];
    scanf("%lld",&t);
    while(t--)
    {
        memset(aa,0,sizeof(aa));
        memset(bb,0,sizeof(bb));
        memset(cc,0,sizeof(cc));
        scanf("%lld%lld",&a,&b);
        int mix=0;
        while(a>0)
        {
            aa[mix++]=a%2;
            a/=2;
        }
        mix=0;
        while(b>0)
        {
            bb[mix]=b%2;
            cc[mix]=b%2;
            mix++;
            b/=2;
        }
        bool flag=false;
        for(int i=66;i>=0;i--)
        {
            if(aa[i]!=bb[i]&&!flag)
            {
                flag=true;
            }
            if(flag)
            {
                bb[i]=1;
                cc[i]=0;
            }
        }
        long long oor=0,andd=0;
        for(int i=0;i<mix;i++)
        {
            oor+=bb[i]*num[i];
            andd+=cc[i]*num[i];
        }
        printf("Case %lld: %lld %lld\n",++cas,oor,andd);
    }
}
