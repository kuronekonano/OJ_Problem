#include<string.h>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#define LL long long
using namespace std;
const int maxn=1003+10;
struct num
{
    LL ab,cc;
    int p;
    num(){}
    num(LL a,LL b,int c)
    {
        ab=a;
        cc=b;
        p=c;
    }
}aa[maxn];
bool cmp(num a,num b)
{
    if(a.ab*b.cc==a.cc*b.ab)return a.p<b.p;
    return a.ab*b.cc<a.cc*b.ab;
}
int n;
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        LL a,b,c;
        for(int i=1;i<=n;i++)
        {
            scanf("%lld%lld%lld",&a,&b,&c);
            aa[i]=num(a+b,c,i);
        }
        sort(aa+1,aa+1+n,cmp);
        for(int i=1;i<=n;i++) printf("%d%c",aa[i].p,i==n?'\n':' ');
    }
}

/*
2/3  1/2
1/2  2/3
4/5  4/5  5/5
*/
