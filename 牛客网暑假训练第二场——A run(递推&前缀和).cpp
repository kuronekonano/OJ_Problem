#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=1e5+10;
const int inf=0x7fffffff;
const int mod = 1e9+7;
LL dp[maxn][3];
int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        memset(dp,0,sizeof dp);
        dp[0][0]=1;
        dp[k][1]=1;
        dp[0][2]=2;
        for(int i=1;i<100001;i++)
        {
            dp[i][0]=(dp[i-1][0]+dp[i-1][1])%mod;
            if(i-k>0) dp[i][1]=(dp[i][1]+dp[i-k][0])%mod;
            dp[i][2]=(dp[i-1][2]+(dp[i][0]+dp[i][1])%mod)%mod;
        }
        int l,r;
        while(n--)
        {
            scanf("%d%d",&l,&r);
            printf("%lld\n",(dp[r][2]-dp[l-1][2]+mod)%mod);
        }
    }
}
