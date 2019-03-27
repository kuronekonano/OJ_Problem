#include<bits/stdc++.h>///任意两数交换，那就找循环节，因为数都是唯一的，那么找到每一个数应该在的位置，任何不在自己位置的数都是要交换的环中的，直接暴力找，计数即可
#define LL long long
#define M(a,b) memset(a,b,sizeof a)
#define pb(x) push_back
using namespace std;
const int maxn=1e5+7;
int a[maxn];
bool vis[maxn];
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        M(vis,false);
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        LL ans=0;
        for(int i=1;i<=n;i++)
        {
            int cnt=0;
            int tmp=i;
            while(!vis[tmp]&&a[tmp]!=tmp)///找下一个自己该在的位置
            {
                cnt++;
                vis[tmp]=true;///标记环中该值是否被遍历过
                tmp=a[tmp];
            }
            if(cnt) ans+=cnt-1;///每个环的交换次数求和
        }
        printf("%lld\n",ans);
    }
}
