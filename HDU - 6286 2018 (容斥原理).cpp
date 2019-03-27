#include<stdio.h>
#include<string.h>
#include<algorithm>
#define LL long long
using namespace std;
LL a,b,c,d;
int main()
{
    while(scanf("%lld%lld%lld%lld",&a,&b,&c,&d)!=EOF)
    {
        LL l2018=b/2018-(a-1)/2018;
        LL r2018=d/2018-(c-1)/2018;
        LL l1009=b/1009-(a-1)/1009;
        LL r1009=d/1009-(c-1)/1009;
        LL l2=b/2-(a-1)/2;
        LL r2=d/2-(c-1)/2;
        LL l=b-a+1;
        LL r=d-c+1;
        LL tmp=l*r2018;
        tmp+=l2*(r1009-r2018);
        tmp+=l1009*(r2-r2018);
        tmp+=l2018*r;
        tmp-=l2018*r2;
        tmp-=l2018*r1009;
        tmp+=l2018*r2018;
        printf("%lld\n",tmp);
    }
}
