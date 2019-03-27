#include<bits/stdc++.h>///盖毯子，最多用多少毯子
using namespace std;
int n,m,a,b,t,ans[100008];
int main()
{
    int num[20][20];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        memset(num,0,sizeof(num));
        memset(ans,0,sizeof(ans));
        for(int i=0; i<n; i++)
        {
            scanf("%d%d",&a,&b);
            for(int i=0; i<a; i++)num[b][i]++;
        }
        for(int i=0; i<m; i++)
        {
            int sum=0;
            for(int j=1; j<=16; j++)
                sum+=num[j][i%j];
            ans[sum]++;
        }
        for(int i=0; i<=n; i++) printf("%d\n",ans[i]);
    }
}
