#include<stdio.h>///排序后按从小到大的顺序遍历，因为已经排完序，因此不用管ti值的筛选，因为每次都是足够大的
#include<algorithm>///因此只用在遍历到一个更大的数时记录或判断这个i是否足够小。注意重复的数，直接略过判断
using namespace std;///因为最小mini的ti值不能与i的ti值相等，并且相同的几个数，i较大的排序放前面，剩余的i就不判断了
struct num
{
    int n,i;
}a[1000006];
int aa[1000006];
bool cmp(num a,num b)
{
    if(a.n==b.n)return a.i>b.i;
    return a.n<b.n;
}
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&aa[i]);
            a[i].i=i,a[i].n=aa[i];
        }
        sort(a,a+n,cmp);
        int ans=0,mini=n;
        for(int i=0;i<n;i++)
        {
            if(a[i].i==aa[mini])continue;
            if(a[i].i<mini) mini=a[i].i;
            else ans=a[i].i-mini>ans?a[i].i-mini:ans;
        }
        printf("%d\n",ans);
    }
}
