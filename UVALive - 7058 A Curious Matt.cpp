#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;
struct kuo
{
    int t,x;
}a[10008];
bool cmp(kuo a,kuo b)
{
    return a.t<b.t;
}
int main()
{
    int t,cas=0,i,n;
    scanf("%d",&t);
    while(t--)
    {
        cas++;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&a[i].t,&a[i].x);
        }
        sort(a,a+n,cmp);
        double ans=0;
        for(i=1;i<n;i++)
        {
            double speed=1.0*abs((a[i].x-a[i-1].x))/abs((a[i].t-a[i-1].t));
            ans=max(ans,speed);
        }
        printf("Case #%d: %.2f\n",cas,ans);
    }
}
