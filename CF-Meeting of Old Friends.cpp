#include<stdio.h>
#include<algorithm>
using namespace std;///找相交区间
int main()
{
    long long l1,l2,r1,r2,k;
    while(scanf("%lld%lld%lld%lld%lld",&l1,&r1,&l2,&r2,&k)!=EOF)
    {
        if(min(r1,r2)-max(l1,l2)+1<=0)
        {
            printf("0\n");
            continue;
        }
        else
        {
            long long ans=min(r2,r1)-max(l1,l2)+1;
            if(k<=min(r1,r2)&&k>=max(l1,l2))
            {
                printf("%lld\n",ans-1);
            }
            else
            {
                printf("%lld\n",ans);
            }
        }
    }
    return 0;
}
