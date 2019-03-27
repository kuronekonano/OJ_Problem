#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=100005;
int main()
{
    LL n,a[maxn],b[maxn];
    while(scanf("%lld",&n)!=EOF)
    {
        LL sum=0;
        for(int i=0; i<n; i++)
        {
            scanf("%lld",&a[i]);
            sum+=a[i];
        }
        bool ans=true;
        LL t=sum/(n*(n+1)/2);
        LL tt=t;
        for(int i=0; i<n; i++)
        {
            LL tmp=a[i]-a[(i-1+n)%n];
            if((t-tmp)%n!=0||t<tmp) ans=false;
            else tt-=(t-tmp)/n;
        }
//        printf("%lld    %lld    %lld\n",sum%(n*(n+1)/2),sum,n*(n+1)/2);
        printf("%s\n",ans&&sum%(n*(n+1)/2)==0&&tt==0?"YES":"NO");
    }
}
