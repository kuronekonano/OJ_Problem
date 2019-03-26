#include<bits/stdc++.h>
#define LL long long
#define M(a,b) memset(a,b,sizeof a)
#define pb(x) push_back(x)
using namespace std;
const int maxn=2e5+7;
int n;
LL a[maxn];
int main()
{
    scanf("%d",&n);
    LL mx=-1;
    for(int i=1; i<=n; i++)
    {
        scanf("%lld",&a[i]);
        if(a[i]>mx)mx=a[i];
    }
    LL ans=n;
    for(int i=2; i<=n; i++)
    {
        if(a[i]>a[i-1])ans+=a[i]-a[i-1]-1;
        else
        {
            if(a[i]==0&&a[i-1]==mx)continue;
            else ans+=mx-a[i-1]+a[i];
        }
    }
    printf("%lld\n",ans);
}
