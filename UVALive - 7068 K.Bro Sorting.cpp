#include<stdio.h>
#include<algorithm>
using namespace std;
struct num
{
    int val,pos;
}a[1000006];
bool cmp(num a,num b)
{
    return a.val<b.val;
}
int main()
{
    int i,cas=0,n,t;
    scanf("%d",&t);
    while(t--)
    {
        cas++;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i].val);
            a[i].pos=i;
        }
        sort(a,a+n,cmp);
        int ans=0,maxn=a[0].pos;
        for(i=1;i<n;i++)
        {
            if(a[i].pos<maxn)ans++;
            else maxn=a[i].pos;
        }
        printf("Case #%d: %d\n",cas,ans);
    }
}
