#include<bits/stdc++.h>
#define LL long long
#define M(a,b) memset(a,b,sizeof a)
#define pb(x) push_back(x)
using namespace std;
int n,m,p;
int main()
{
    scanf("%d%d%d",&n,&m,&p);
    if(n%p==0||m%p==0)
    {
        int cnt=1;
        printf("Yes\n");
        if(m%p==0)
        {
            for(int i=1; i<=n; i++)
                for(int j=1; j<=m; j++)
                    printf("%d%c",cnt,j==m?'\n':' '),cnt=j%p?cnt:cnt+1;
        }
        else
        {
            int a[108][108];
            for(int i=1; i<=m; i++)
                for(int j=1; j<=n; j++)a[j][i]=cnt,cnt=j%p?cnt:cnt+1;
            for(int i=1; i<=n; i++)
                for(int j=1; j<=m; j++)
                    printf("%d%c",a[i][j],j==m?'\n':' ');
        }
    }
    else printf("No\n");
}
