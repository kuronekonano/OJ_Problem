#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int t,i,n,j,k;
    long long a[1008];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        long long ans=0;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
        }
        for(i=0;i<n-2;i++)
        {
            for(j=i+1;j<n-1;j++)
            {
                for(k=j+1;k<n;k++)
                {
                    if(k!=i&&j!=k)
                    {
                        ans=max(ans,((a[i]+a[j])^a[k]));
                        ans=max(ans,((a[j]+a[k])^a[i]));
                        ans=max(ans,((a[i]+a[k])^a[j]));
                    }
                }
            }
        }
        printf("%lld\n",ans);
    }
}
